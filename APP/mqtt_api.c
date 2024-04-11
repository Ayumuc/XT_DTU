#include "mqtt_api.h"
#include "MQTTPacket.h"
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "ztn_mqtt.h"
#include "board_config.h"
#include "cJSON.h"
#include "flash.h"
#include "config_handle_task.h"
char *mqttClientId="SUN_000001_ETH";
int 	keepalive=180;
int 	cleansession=1;
char *mqttUsername="GW_ZHONGTNSW";
char *password="B99C0BFCED33A1801C869350A90D5E15";

uint8 buf[1024]={0};
int buflen = sizeof(buf);

/******解析收到的ACK报文*********/
int mqtt_decode_msg(unsigned char*buf)
{
	int rc = -1;
	MQTTHeader header = {0};
	header.byte = buf[0];
	rc = header.bits.type;
	return rc;
}

//连接MQTT服务器函数
uint8 connectMqtt(SOCKET Socket){
	int len,rc,wait_ack_time=0;
//	MQTTPacket_connectData data = MQTTPacket_connectData_initializer;//配置部分可变头部的值
//	data.clientID.cstring = mqttClientId;		//客户端标识，用于区分每个客户端
//	data.keepAliveInterval = keepalive;			//保活计时器，定义了服务器收到客户端消息的最大时间间隔
//	data.cleansession = cleansession;				//该标志置1服务器必须丢弃之前保持的客户端的信息，将该连接视为“不存在”
//	data.username.cstring = mqttUsername;
//	data.password.cstring = password;
	MQTTPacket_connectData data = MQTTPacket_connectData_initializer;//配置部分可变头部的值
	data.clientID.cstring = XT_config.Mqtt_client_Config.mqttClientId;		//客户端标识，用于区分每个客户端
	data.keepAliveInterval = XT_config.Mqtt_client_Config.keepalive;			//保活计时器，定义了服务器收到客户端消息的最大时间间隔
	data.cleansession = cleansession;				//该标志置1服务器必须丢弃之前保持的客户端的信息，将该连接视为“不存在”
	data.username.cstring = XT_config.Mqtt_client_Config.mqttUsername;
	data.password.cstring = XT_config.Mqtt_client_Config.password;
	memset(buf,0,buflen);
	len = MQTTSerialize_connect(buf, buflen, &data); 	/*1 构造连接报文*/
	rc = send(Socket,buf,len);												//发送连接请求
	if(rc != len)
	{
		printf("Send Connect Error: rc=%d len=%d\n\r",rc,len);
		return 1;
	}
	//循环获取Connect Ack
	do{
		delay_ms(10);
		len=getSn_RX_RSR(Socket);	
		wait_ack_time++;
		if(wait_ack_time>MAX_OVERTIME)
		{
			printf("Wait CONNACK Overtime\n\r");
			return 2;
		}
	}while(len<=0);
	recv(Socket,buf,len);//接收数据 判断是否为Connect Ack
	if(mqtt_decode_msg(buf)!=CONNACK){
		printf("Error CONNACK:%s\n\r",buf);
		return 3;
	}
	printf("Connect Is Ok:%s\r\n",buf);
	return 0;
}

//PING服务器 保持存活
uint8 pingMqtt(SOCKET Socket){
	int len,rc,wait_ack_time=0;
	memset(buf,0,buflen);
	len=MQTTSerialize_pingreq(buf,buflen);
	rc=send(Socket,buf, len);
	if(len!=rc)
	{
		printf("Send Ping Error: rc=%d len=%d\n\r",rc,len);
		return 1;
	}
	do{
		delay_ms(10);
		len=getSn_RX_RSR(Socket);
		wait_ack_time++;
		if(wait_ack_time>MAX_OVERTIME)
		{
			printf("Wait PINGRESP Overtime\n\r");
			return 2;
		}
	}while(len<=0);
	recv(Socket,buf,len);
	if(mqtt_decode_msg(buf) != PINGRESP){
		printf("Error PINGRESP:%s\n\r",buf);
		return 3;
	}
	printf("PING Successfully:%s\n\r",buf);
//	if(len>2){
//		if(mqtt_decode_msg(buf+2) == PUBLISH){
//			dealMqtt(Socket,buf+2,buflen-2);
//		}
//	}
	return 0;
}

//MQTT发布消息函数
uint8 publishMqtt(SOCKET Socket,char *pTopic,char *pMessage)
{
	int len,rc,wait_ack_time=0;
	MQTTString topicString = MQTTString_initializer;
	int msglen = strlen(pMessage);//计算发布消息的长度
	topicString.cstring = pTopic;
	len = MQTTSerialize_publish(buf, buflen, 0, 1, 0, 0, topicString, (unsigned char*)pMessage, msglen); /*2 构造发布消息的报文*/
	rc = send(Socket,buf,len);		//发送消息
	if (rc != len)
	{
		printf("Send Publish Error: rc=%d len=%d\n\r",rc,len);
		return 1;
	}
	do{
		delay_ms(10);
		len=getSn_RX_RSR(Socket);
		wait_ack_time++;
		if(wait_ack_time>MAX_OVERTIME)
		{
			printf("Wait PUBACK Overtime\n\r");
			return 2;
		}
	}while(len<=0);
	recv(Socket,buf,len);
	if(mqtt_decode_msg(buf) != PUBACK){
		printf("error PUBACK:%s\n\r",buf);
		return 3;
	}
	printf("Publish Successfully:%s\n\r",buf);
	return 0;
}
//MQTT订阅函数
uint8 subscribMqtt(SOCKET Socket,char *pTopic)
{
	int len,rc,wait_ack_time=0;
	MQTTString topicString = MQTTString_initializer;
	int msgid = 1;							//该值为消息标识符
	char req_qos = '1';
	memset(buf,0,buflen);
	topicString.cstring = pTopic;
	len = MQTTSerialize_subscribe(buf, buflen, 0, msgid, 1, &topicString, &req_qos);//构造订阅主题报文
	rc = send(Socket,buf,len);	//发送消息
	if (rc != len)
	{
		printf("Send Subscrib Error: rc=%d len=%d\n\r",rc,len);
		return 1;
	}
	do{
		delay_ms(10);
		len=getSn_RX_RSR(Socket);
		wait_ack_time++;
		if(wait_ack_time>MAX_OVERTIME)
		{
			printf("Wait SUBACK Overtime\n\r");
			return 2;
		}
	}while(len<=0);
	recv(Socket,buf,len);
	if(mqtt_decode_msg(buf) != SUBACK){
		printf("Error SUBACK:%s\n\r",buf);
		return 3;
	}
	printf("Subscrib Successfully:%s\n\r",buf);
	return 0;
}

//MQTT处理订阅消息函数
void dealPublish(SOCKET Socket,uint8 *msgbuf,uint16 msglen){
	//////////获取订阅消息参数//////////////
	unsigned char dup;
	int qos;
	unsigned char retained;
	unsigned short mssageid;
	int payloadlen_in;
	unsigned char* payload_in;
	MQTTString receivedTopic;
	/////////////////////////////////////////
	int len,rc;
	MQTTDeserialize_publish(&dup, &qos, &retained, &mssageid, &receivedTopic,
							&payload_in, &payloadlen_in, msgbuf, msglen);
	//printf("message id: %d\n\r",mssageid);
	//printf("message qos: %d\n\r",qos);
	//printf("message receivedTopic: %s\n\r",receivedTopic.lenstring.data);
	//printf("message arrived[%d]: %s\n\r", payloadlen_in, payload_in);
	mqtt_rechandle(payload_in);
	if(qos>0){//需要回复
		len = MQTTSerialize_puback(buf, buflen, mssageid);//构造ack报文
		rc = send(Socket,buf,len);	//发送消息
		if(len!=rc)printf("Send PUBACK Error: rc=%d len=%d\n\r",rc,len);
	}
}
/*
{
    "dCode":"SolarDev_C103",
    "msgId":"91810fb51e2f6421",
    "cmd":"addTask",
    "start":0, //开始
    "end":99,  //结束
    "index":99, //当前下发任务索引
    "task":{
        "flag":"Surplus",
        "channel":1, // 通道排序号，按照从站地址大小排序0-N
        "dataType":1,//数据类型
        "start":0,
        "period":100,  //采样周期 ms
        "respTime":100, //应答时间 ms
        "slaveStationAddr":1,//从站地址
        "funcCode":3,//功能码
        "dataAddr":10, //寄存器地址 10进制
        "timer":0, //定时上传 1-开启，0-禁用
        "times":100,//单位 s
        "dataChange":1, //数值变化上传 1-开启，0-禁用
        "changeValue":11,//数值变化值
        "threshold":11,//阈值触发，1-开启，0-禁用
        "thrMin":11,//低于阈值  thrMin,thrMax 都不为空，条件为介于
        "thrMax":11, //高于阈值
        "delay":10 //持续时间 * 100ms 只在阈值触发时生效
    }
}*/


uint8_t mqtt_rechandle(unsigned char* buf){
		printf("message arrived[170]: %s\n\r",buf);
		char callback_buf[256];
	  static int zero_flag = 0;
		char* tmp_str;
    cJSON* ztn_object = NULL;
    cJSON* param = NULL;
		cJSON* task = NULL;
		char msgid[50] = {0};
    char dCore[50] = {0};
    char cmd[50] = {0};
		int index = NULL;
		int tmp_flag = 0;
    ztn_object = cJSON_Parse((char*)buf);
    if(ztn_object == NULL)
    {
        printf("parse fail.\n");
        return -1;
    }
    else{
        printf("格式正确\r\n");
    }
		param = cJSON_GetObjectItem(ztn_object,"cmd");
		if(strcmp(param->valuestring,"setRTC") != 0 ){
			task = cJSON_GetObjectItem(ztn_object,"task");
			param = cJSON_GetObjectItem(task,"param");
			for(int i = 0 ; i < 256 ; i++){
				if(XT_config.modbus_flag[i] == param->valueint){
					tmp_flag = 1;
					break;
				}
			}
			if(tmp_flag != 1){
				param = cJSON_GetObjectItem(task,"times");
				XT_config.modbus_uptime[XT_config.modbus_count] = (param->valueint/1000);
				param = cJSON_GetObjectItem(task,"period");
				XT_config.modbus_period[XT_config.modbus_count] = param->valueint;
				param = cJSON_GetObjectItem(task,"dataType");
				XT_config.modbus_dataType[XT_config.modbus_count] = param->valueint;
				param = cJSON_GetObjectItem(task,"slaveStationAddr");
				XT_config.modbus_flag[XT_config.modbus_count] = param->valueint;
				param = cJSON_GetObjectItem(task,"flag");
				sprintf(XT_config.modbus_data[XT_config.modbus_count],"%s",param->valuestring);
				printf("modbus_flag:%d\r\n",XT_config.modbus_flag[XT_config.modbus_count]);
				printf("XT_config.modbus_data:%s\r\n",XT_config.modbus_data[XT_config.modbus_count]);
				printf("modbus_count:%d\r\n",XT_config.modbus_count);
				XT_config.modbus_count++;
				sprintf(msgid,"%s",cJSON_GetObjectItem(ztn_object,"msgId")->valuestring);
				sprintf(dCore,"%s",cJSON_GetObjectItem(ztn_object,"dCode")->valuestring);
				sprintf(cmd,"%s",cJSON_GetObjectItem(ztn_object,"cmd")->valuestring);
				index = cJSON_GetObjectItem(ztn_object,"index")->valueint;
				sprintf(callback_buf,"{\"msgId\":\"%s\",\"dCode\":\"%s\",\"cmd\":\"%s\",\"index\":%d, \"err\":\"\"}",msgid,dCore,cmd,index);
				printf("callback:%s\r\n",callback_buf);
				publishMqtt(5,XT_config.Mqtt_client_Config.pubTopic,callback_buf);
				saveConfig(&XT_config);
			}
		}
    return 1;
}

//uint8_t mqtt_rechandled(unsigned char* buf){
//	printf("message arrived[170]: %s\n\r",buf);
//	char callback_buf[256];
//	static int zero_flag = 0;
//	char* tmp_str;
//  cJSON* cjson_test = NULL;
//  cJSON* param = NULL;
//  cJSON* cmd = NULL;
//	cJSON* msgid = NULL;
//	int tmp_flag = 0;
//    cjson_test = cJSON_Parse((char*)buf);
//    if(cjson_test == NULL)
//    {
//        printf("parse fail.\n");
//        return -1;
//    }
//    else{
//        printf("格式正确\r\n");
//    }
//    param = cJSON_GetObjectItem(cjson_test,"param");
//    cmd = cJSON_GetObjectItem(cjson_test,"cmd");
//		msgid = cJSON_GetObjectItem(cjson_test,"msgId");
//    tmp_str = strtok(param->valuestring, ",");
//    for(int i = 0 ; i < 14 ; i++){
//      tmp_str = strtok(NULL, ",");
//    }
//			for(int i = 0 ; i < 256 ; i++){
//			if(XT_config.modbus_flag[i] == atoi(tmp_str)){
//				tmp_flag = 1;
//				break;
//			}
//		}
//		if(tmp_flag != 1){
//		XT_config.modbus_flag[XT_config.modbus_count] = atoi(tmp_str);
//		sprintf(XT_config.modbus_data[XT_config.modbus_count],"%sED",cmd->valuestring);
//		printf("modbus_flag:%d\r\n",XT_config.modbus_flag[XT_config.modbus_count]);
//		printf("XT_config.modbus_data:%s\r\n",XT_config.modbus_data[XT_config.modbus_count]);
//		printf("modbus_count:%d\r\n",XT_config.modbus_count);
//		XT_config.modbus_count++;
//		sprintf(callback_buf,"{\"dCode\":\"%s\",\"msgId\":\"%s\",\"cmd\":\"%s\",\"err\":\"%s\"}",XT_config.Mqtt_client_Config.mqttClientId,msgid->valuestring,cmd->valuestring,"6");
//		publishMqtt(5,XT_config.Mqtt_client_Config.pubTopic,callback_buf);
//		saveConfig(&XT_config);
//	}
//    return 1;
//}

uint8 do_mqtt(SOCKET Socket,uint8 *sip,uint16 sport,uint16 lport){
	static uint8 CONNECT_FLAG = 0;
	uint16 rlen;
	switch(getSn_SR(Socket)){
		 case SOCK_INIT:
			 connect(Socket,sip,sport);
			 break;
		 case SOCK_ESTABLISHED:
			 if(getSn_IR(Socket)&Sn_IR_CON)setSn_IR(Socket,Sn_IR_CON);
			 if(!CONNECT_FLAG)if(!connectMqtt(Socket))CONNECT_FLAG=1;
			 rlen=getSn_RX_RSR(Socket);
			 if(rlen>0){
					recv(Socket,buf,rlen);
					switch(mqtt_decode_msg(buf)){
						case PUBLISH:
							dealPublish(Socket,buf,rlen);
						break;
						default:
							printf("recv:%s",buf);
						break;
					}
			 }
			 break;
		 case SOCK_CLOSE_WAIT:
				disconnect(Socket);
				close(Socket);
			 break;
		 case SOCK_CLOSED:
				CONNECT_FLAG=0;
				socket(Socket,Sn_MR_TCP,lport,Sn_MR_ND);
			 break;
	 }
	return CONNECT_FLAG;
}



