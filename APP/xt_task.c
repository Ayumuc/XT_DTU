#include "xt_task.h"


static int Configmode(void);
int MQTT_ETH_MODE(void);
int MQTT_4G_MODE(void);
void W5500_Tcp_client(void);
uint8_t my_ip[4] = {10,192,178,87};
void init_Net(void);
uint8_t cnt_flag=0,sub_flag=0,pub_flag=0;
uint8_t mqqtbuf[8] = {0x01,0x03,0x00,0x00,0x00,0x00,0x00,0x00};
int modbus_send(void);
uint16_t time=0;
#define MQTT_SOCK 5
uint8_t ZTN_MQTT_ENCODE(void);

int xt_task_init(void){
	Configmode();
	printf("mode:%d\r\n",XT_config.Net_Mode);
	while(1){
			switch(XT_config.Net_Mode){
				case 1:W5500_Tcp_client();break;
				case 3:MQTT_ETH_MODE();break;
				case 4:MQTT_4G_MODE();break;
				default:break;
			}
	}
}

//int MQTT_ETH_MODE(void){
//		int time_485 = 0;
//		init_Net();
//		printf("init_Net OK\r\n");
//		while(1){
//		do_https();
//		cnt_flag=do_mqtt(MQTT_SOCK,XT_config.Mqtt_client_Config.Sip,XT_config.Mqtt_client_Config.SPort,XT_config.Mqtt_client_Config.LPort);
//		if(cnt_flag==0){sub_flag=0;pub_flag=0;time=0;}
//		if(cnt_flag&&sub_flag==0)sub_flag=!subscribMqtt(MQTT_SOCK,XT_config.Mqtt_client_Config.subTopic);
//		if(cnt_flag&&sub_flag&&pub_flag==0){
//			pub_flag=!publishMqtt(MQTT_SOCK,XT_config.Mqtt_client_Config.pubTopic,"hello mqtt");
//		}
//		if(cnt_flag){time++;}
//		if(time==1000){
//			time=0;
//			pingMqtt(MQTT_SOCK);
//			HAL_UART_Transmit(&huart3, modbus_send_buf[tim_count],8,100);
//			while(1){
//				HAL_UART_Receive_DMA(&huart3, RS485_2_BUFF , sizeof(RS485_2_BUFF));
//				time_485++;
//				if(USART3_RX_END_FLAG == 1){
//					tim_count++;
//					if(tim_count >= 3 ){
//						tim_count = 0;
//					}
//					break;
//				}
//				else if(time_485 > 3000){
//					break;
//				}
//				delay_ms(10);
//			}
//		}
//		if(USART3_RX_END_FLAG == 1){
//			ZTN_MQTT_ENCODE();
//			USART3_RX_END_FLAG = 0;
//		}
//		delay_ms(10);
//	}
//	return 1;
//}


int MQTT_ETH_MODE(void){
		int time_485 = 0;
		init_Net();
		printf("init_Net OK\r\n");
		while(1){
		cnt_flag=do_mqtt(MQTT_SOCK,XT_config.Mqtt_client_Config.Sip,XT_config.Mqtt_client_Config.SPort,XT_config.Mqtt_client_Config.LPort);
		if(cnt_flag==0){sub_flag=0;pub_flag=0;time=0;}
		if(cnt_flag&&sub_flag==0)sub_flag=!subscribMqtt(MQTT_SOCK,XT_config.Mqtt_client_Config.subTopic);
		if(cnt_flag&&sub_flag&&pub_flag==0){
			pub_flag=!publishMqtt(MQTT_SOCK,XT_config.Mqtt_client_Config.pubTopic,"{\"dCode\":	\"SGW0400008_4G\", \"data\":	{\"Signal\":\"16\" }}");
			HAL_TIM_Base_Start_IT(&htim2);
			HAL_TIM_Base_Start_IT(&htim4);
		}
		if(cnt_flag){time++;}
		if(time==4500){
			time=0;
			pingMqtt(MQTT_SOCK);
			//ZTN_MQTT_ENCODE();
			//modbus_send();
		}
		delay_ms(10);
	}
	return 1;
}

int modbus_send(void){
	int timeout = 0;
	static int modbus_time = 0;
	for(int i = 0 ; i < XT_config.modbus_count ; i++){
		if((modbus_time%XT_config.modbus_period[i]) == 0){
			int8_t high,low;
			high = (XT_config.modbus_flag[i] >> 8) & 0xff;
			low = XT_config.modbus_flag[i] & 0xff;
			mqqtbuf[2] = high;
			mqqtbuf[3] = low;
			mqqtbuf[4] = 0;
			mqqtbuf[5] = 1;
			int crc16 = getModbusCRC16(mqqtbuf,6);
			high = (crc16 >> 8) & 0xff;
			low = (crc16) & 0xff;
			mqqtbuf[6] = low;
			mqqtbuf[7] = high;
			for(int i = 0 ; i < 8 ; i++){
				printf(" %02x",mqqtbuf[i]);
			}
			printf("\r\n");
			HAL_UART_Transmit(&huart3, mqqtbuf,8,100);
			while(1){
					timeout++;
					HAL_UART_Receive_DMA(&huart3, RS485_2_BUFF , sizeof(RS485_2_BUFF));
					if(USART3_RX_END_FLAG == 1){
						timeout = 0;
						USART3_RX_END_FLAG = 0;
						break;
					}
					if(timeout > 200){
						timeout = 0;
						break;
					}
					delay_ms(10);
				}
		}
	}
	modbus_time++;
	if(modbus_time > 10000){
		modbus_time = 0;
	}
	my_flag = 0;
	
}



int MQTT_4G_MODE(void){
	static int FLAG_4G = 0;
	static int timeout = 2500;
	static int mqtt_tim = 0;
	tim_count = 0;
	timeout++;
	if(FLAG_4G == 0 ){
	HAL_GPIO_WritePin(EC600N_PWR_GPIO_Port,EC600N_PWR_Pin,GPIO_PIN_SET);
	printf("4G UP\r\n");
	FLAG_4G = 1;
  ec800n_uart_send("AT\r\n",sizeof("AT\r\n"),"AT");
	delay_ms(5000);
	ec800n_uart_send("AT+CPIN?\r\n",sizeof("AT+CPIN?\r\n"),"READY");
	delay_ms(5000);
	ec800n_uart_send("AT+CSQ\r\n",sizeof("AT+CSQ\r\n"),"CSQ");
	delay_ms(5000);
	ec800n_uart_send("AT+CREG?\r\n",sizeof("AT+CREG?\r\n"),"CREG");
	delay_ms(5000);
	ec800n_uart_send("AT+QIACT=1\r\n",sizeof("AT+QIACT=1\r\n"),"OK");
	delay_ms(5000);
	ec800n_uart_send("AT+QMTCFG=\"qmtping\",0,30\r\n",sizeof("AT+QMTCFG=\"qmtping\",0,30\r\n"),"OK");
	delay_ms(5000);
	ec800n_uart_send("AT+QMTCFG=\"recv/mode\",0,0,1\r\n",sizeof("AT+QMTCFG=\"recv/mode\",0,0,1\r\n"),"OK");
	delay_ms(5000);
	ec800n_uart_send("AT+QMTOPEN=0,\"dt.ztn-tech.com\",1883\r\n",sizeof("AT+QMTOPEN=0,\"dt.ztn-tech.com\",1883"),"+QMTOPEN");
	delay_ms(5000);
	ec800n_uart_send("AT+QMTCONN=0,\"SolarTestT00011_4G\",\"SolarTest_22AB562F\",\"E4E41CFF8C884B0C5B2DBB9A015BE1B6\"\r\n",sizeof("AT+QMTCONN=0,\"SolarTestT00011_4G\",\"SolarTest_22AB562F\",\"E4E41CFF8C884B0C5B2DBB9A015BE1B6\"\r\n"),"+QMTCONN");
	delay_ms(5000);
	ec800n_uart_send("AT+QMTSUB=0,1,\"/ztn/SolarTestT00011_4G/get\",0\r\n",sizeof("AT+QMTSUB=0,1,\"/ztn/SolarTestT00011_4G/get\",0\r\n"),"OK");
	}
	if(timeout > 4000){
		timeout = 0;
		HAL_UART_Transmit(&huart3, modbus_send_buf[0],8,1000);
		while(1){
				HAL_UART_Receive_DMA(&huart3, RS485_2_BUFF , sizeof(RS485_2_BUFF));
				if(USART3_RX_END_FLAG == 1){
					cJSON* ZTN_OBJECT = cJSON_CreateObject();
					cJSON_AddStringToObject(ZTN_OBJECT, "dCore","SolarTestT00011_4G");
					cJSON_AddStringToObject(ZTN_OBJECT, "v","dd_1");
					cJSON_AddNumberToObject(ZTN_OBJECT, "r", 1);
					cJSON* ZTN_EXTERN_OBJECT = cJSON_CreateObject();
					cJSON_AddStringToObject(ZTN_EXTERN_OBJECT, "IMEI","LZH");
					cJSON_AddStringToObject(ZTN_EXTERN_OBJECT, "SIM","LZH");
					cJSON_AddStringToObject(ZTN_EXTERN_OBJECT, "SV","DTU1.01");
					cJSON_AddStringToObject(ZTN_EXTERN_OBJECT, "HV","XTDTU");
					cJSON_AddItemToObject(ZTN_OBJECT, "extend", ZTN_EXTERN_OBJECT);
					cJSON* ZTN_sum_OBJECT = cJSON_CreateObject();
					cJSON_AddNumberToObject(ZTN_sum_OBJECT, "port", 1);
					cJSON* ZTN_val_OBJECT = cJSON_CreateObject();
					switch(mqtt_tim){
						case 0:
						cJSON_AddNumberToObject(ZTN_val_OBJECT, "charge_status", ztn_data.ztn[100] );
						cJSON_AddNumberToObject(ZTN_val_OBJECT, "V_power", ztn_data.ztn[101]);
						cJSON_AddNumberToObject(ZTN_val_OBJECT, "V_bat", ztn_data.ztn[102]);
						cJSON_AddNumberToObject(ZTN_val_OBJECT, "I_charge", ztn_data.ztn[103]);
						mqtt_tim++;
						break;
						case 1:
						cJSON_AddNumberToObject(ZTN_val_OBJECT, "V_output", ztn_data.ztn[104]);
						cJSON_AddNumberToObject(ZTN_val_OBJECT, "V_load", ztn_data.ztn[105]);
						cJSON_AddNumberToObject(ZTN_val_OBJECT, "I_load", ztn_data.ztn[106]);
						cJSON_AddNumberToObject(ZTN_val_OBJECT, "power_charge", ztn_data.ztn[107]);
						mqtt_tim++;
						break;
						case 2:
						cJSON_AddNumberToObject(ZTN_val_OBJECT, "power_load", ztn_data.ztn[108]);
						cJSON_AddNumberToObject(ZTN_val_OBJECT, "T_bat", ztn_data.ztn[109]);
						cJSON_AddNumberToObject(ZTN_val_OBJECT, "T_inside", ztn_data.ztn[110]);
						mqtt_tim++;
						break;
						case 3:
						cJSON_AddNumberToObject(ZTN_val_OBJECT, "C02", (ztn_data.ztn[111] << 8 | ztn_data.ztn[112]));
						mqtt_tim++;
						break;
						case 4:
						cJSON_AddNumberToObject(ZTN_val_OBJECT, "Fault_codes", ztn_data.ztn[113]);
						cJSON_AddNumberToObject(ZTN_val_OBJECT, "System", ztn_data.ztn[114]);
						cJSON_AddNumberToObject(ZTN_val_OBJECT, "Surplus", ztn_data.surplus);
						cJSON_AddStringToObject(ZTN_val_OBJECT, "Signal","16");
						mqtt_tim=0;
						break;
						default:break;
					}
					cJSON_AddItemToObject(ZTN_sum_OBJECT, "val", ZTN_val_OBJECT);
					cJSON* ZTN_sDATA_OBJECT = cJSON_CreateArray();
					cJSON_AddItemToArray(ZTN_sDATA_OBJECT, ZTN_sum_OBJECT);
					cJSON_AddItemToObject(ZTN_OBJECT,"sData",ZTN_sDATA_OBJECT);
					char* my_str = cJSON_Print(ZTN_OBJECT);
					printf("my_str:%s\r\n",my_str);
					delay_ms(400);
					char at_buf[100]={0};
					char mqtt_buf[600]={0};
					sprintf(at_buf,"AT+QMTPUBEX=0,0,0,0,\"/ztn/SolarTestT00011_4G/update\",%d\r\n",(strlen(my_str)));
					HAL_UART_Transmit(&huart2, (unsigned char*)at_buf,strlen(at_buf),1000);
					delay_ms(500);
					sprintf(mqtt_buf,"%s\r\n\r\n",my_str);
					printf("mqtt_buf;%d\r\n",strlen(mqtt_buf));
					HAL_UART_Transmit(&huart2, (unsigned char*)mqtt_buf,strlen(mqtt_buf),1000);
					free(my_str);
					cJSON_Delete(ZTN_OBJECT);
					USART3_RX_END_FLAG = 0;
					break;
				}
				delay_ms(10);
			}
	}
	
	return 1;
}


static int Configmode(void){
		
		printf("SW11:%d\r\n",HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_7));
		printf("SW12:%d\r\n",HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_8));
		printf("SW13:%d\r\n",HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_9));
		
		if(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_9) == GPIO_PIN_SET){
			 printf("welcome to config mode............\r\n");
			 board_config_set();
		}
		else{
			printf("welcome to normal mode............\r\n");
			return 0;
		}
		return 1;
}


uint8 tsize[MAX_SOCK_NUM] = {2,2,2,2,2,2,2,2};
uint8 rsize[MAX_SOCK_NUM] = {2,2,2,2,2,2,2,2};

void W5500_RESET(void);
void put_defaultNet(void);
void init_Net(void){
	uint8_t try_times=0;
	W5500_ChipInit();
	printf("w5500 init success\r\n");
//	put_defaultNet();
//	printf("put success\r\n");
//  init_dhcp_client();
// 	//while(!do_dns((uint8_t *)"www.baidu.com"));
//	printf("dhcp init success\r\n");
//	while(check_DHCP_state(Sn bhgf vmk j,5432azx  OCK_DHCP)!=DHCP_RET_UPDATE){
//			try_times++;
//			if(try_times==255){							//³¬Ê± ÖØÆôÐ¾Æ¬
//				W5500_RESET();
//				init_dhcp_client();
//				try_times=0;
//			}
//			delay_ms(10);
//		}
//	while(!set_Network());
}


int ec800n_uart_send(char* tx_buf, uint16_t len ,char* rx_buf){
	HAL_UART_Transmit(&huart2, (uint8_t*)tx_buf, len,1000);
	return 1;
	while(1){
		HAL_UART_Receive_DMA(&huart2,RECV_4G_BUFF,sizeof(RECV_4G_BUFF));
		if(Uart_4g_End == 1){
			if(strstr((char*)RECV_4G_BUFF,rx_buf) != NULL){
				Uart_4g_End = 0;
				break;
			}
		}
		delay_ms(20);
	}
	return 1;
}

uint8_t DataCollect(void){
	modbus_send();//Task of rs485_2 modbus data collect
	
	do_https();
	
	do_mqtt(MQTT_SOCK,XT_config.Mqtt_client_Config.Sip,XT_config.Mqtt_client_Config.SPort,XT_config.Mqtt_client_Config.LPort);
}


