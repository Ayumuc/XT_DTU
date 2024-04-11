#include "stdio.h"
#include "CJSON.h"
#include "string.h"
#include "stdlib.h"
#include "ztn_mqtt.h"
#include "board_config.h"
#include "mqtt_api.h"
#include "ec800n.h"
#include "usart.h"
ZTN_data ztn_data;
//uint8_t ZTN_MQTT_ENCODE(void){
//	
//		char* pub_buff;
//		int ret;
//    cJSON* ZTN_OBJECT = cJSON_CreateObject();
//    cJSON_AddStringToObject(ZTN_OBJECT, "dCore",XT_config.Mqtt_client_Config.mqttClientId);
//    cJSON_AddStringToObject(ZTN_OBJECT, "v","dd_1");
//    cJSON_AddNumberToObject(ZTN_OBJECT, "r", 1);
//		
//	
//		cJSON* ZTN_EXTERN_OBJECT = cJSON_CreateObject();
//    cJSON_AddStringToObject(ZTN_EXTERN_OBJECT, "IMEI","lzh");
//    cJSON_AddStringToObject(ZTN_EXTERN_OBJECT, "SIM","lzh");
//    cJSON_AddStringToObject(ZTN_EXTERN_OBJECT, "SV","OPV29");
//    cJSON_AddStringToObject(ZTN_EXTERN_OBJECT, "HV","NBV38A");
//    cJSON_AddItemToObject(ZTN_OBJECT, "extend", ZTN_EXTERN_OBJECT);
//	
//	
//    cJSON* ZTN_sum_OBJECT = cJSON_CreateObject();
//    cJSON_AddNumberToObject(ZTN_sum_OBJECT, "port", 1);
//		
////		cJSON* ZTN_val_OBJECT = cJSON_CreateObject();
////    cJSON_AddNumberToObject(ZTN_val_OBJECT, "charge_status", ztn_data.charge_status);
////    cJSON_AddNumberToObject(ZTN_val_OBJECT, "V_power", ztn_data.v_power);
////    cJSON_AddNumberToObject(ZTN_val_OBJECT, "V_bat", ztn_data.v_bat);
////    cJSON_AddNumberToObject(ZTN_val_OBJECT, "I_charge", ztn_data.i_charge);
////    cJSON_AddNumberToObject(ZTN_val_OBJECT, "V_output", ztn_data.v_output);
////    cJSON_AddNumberToObject(ZTN_val_OBJECT, "V_load", ztn_data.v_load);
////		cJSON_AddNumberToObject(ZTN_val_OBJECT, "I_load", ztn_data.i_load);
////		cJSON_AddNumberToObject(ZTN_val_OBJECT, "power_charge", ztn_data.power_charge);
////		cJSON_AddNumberToObject(ZTN_val_OBJECT, "power_load", ztn_data.power_load);
////    cJSON_AddNumberToObject(ZTN_val_OBJECT, "T_bat", ztn_data.T_bat);
////    cJSON_AddNumberToObject(ZTN_val_OBJECT, "T_inside", ztn_data.T_inside);
////    cJSON_AddNumberToObject(ZTN_val_OBJECT, "Surplus", ztn_data.surplus);
////    cJSON_AddStringToObject(ZTN_val_OBJECT, "Signal","16");

////		cJSON* ZTN_val_OBJECT = cJSON_CreateObject();
////    cJSON_AddNumberToObject(ZTN_val_OBJECT, "charge_status", ztn_data.ztn[100] );
////    cJSON_AddNumberToObject(ZTN_val_OBJECT, "V_power", ztn_data.ztn[101]);
////    cJSON_AddNumberToObject(ZTN_val_OBJECT, "V_bat", ztn_data.ztn[102]);
////    cJSON_AddNumberToObject(ZTN_val_OBJECT, "I_charge", ztn_data.ztn[103]);
////    cJSON_AddNumberToObject(ZTN_val_OBJECT, "V_output", ztn_data.ztn[104]);
////    cJSON_AddNumberToObject(ZTN_val_OBJECT, "V_load", ztn_data.ztn[105]);
////		cJSON_AddNumberToObject(ZTN_val_OBJECT, "I_load", ztn_data.ztn[106]);
////		cJSON_AddNumberToObject(ZTN_val_OBJECT, "power_charge", ztn_data.ztn[107]);
////		cJSON_AddNumberToObject(ZTN_val_OBJECT, "power_load", ztn_data.ztn[108]);
////    cJSON_AddNumberToObject(ZTN_val_OBJECT, "T_bat", ztn_data.ztn[109]);
////    cJSON_AddNumberToObject(ZTN_val_OBJECT, "T_inside", ztn_data.ztn[110]);
////		cJSON_AddNumberToObject(ZTN_val_OBJECT, "C02", (ztn_data.ztn[111] << 8 | ztn_data.ztn[112]));
////		cJSON_AddNumberToObject(ZTN_val_OBJECT, "Fault_codes", ztn_data.ztn[113]);
////		cJSON_AddNumberToObject(ZTN_val_OBJECT, "System", ztn_data.ztn[114]);
//		
//			cJSON* ZTN_val_OBJECT = cJSON_CreateObject();
//			for(int i = 0 ; i < XT_config.modbus_count ; i++){
//				cJSON_AddNumberToObject(ZTN_val_OBJECT, XT_config.modbus_data[i], ztn_data.ztn[XT_config.modbus_flag[i]] );
//			}
//			
////		cJSON_AddNumberToObject(ZTN_val_OBJECT, "Bat_type", ztn_data.ztn[200]);
////		cJSON_AddNumberToObject(ZTN_val_OBJECT, "Bat_sysv", ztn_data.ztn[201]);
////		cJSON_AddNumberToObject(ZTN_val_OBJECT, "CV_v", ztn_data.ztn[202]);
////		cJSON_AddNumberToObject(ZTN_val_OBJECT, "CF_v", ztn_data.ztn[203]);
////		cJSON_AddNumberToObject(ZTN_val_OBJECT, "MAX_charge", ztn_data.ztn[204]);
////		cJSON_AddNumberToObject(ZTN_val_OBJECT, "MAX_load", ztn_data.ztn[205]);
////		cJSON_AddNumberToObject(ZTN_val_OBJECT, "I_average", ztn_data.ztn[206]);
////		cJSON_AddNumberToObject(ZTN_val_OBJECT, "A_time", ztn_data.ztn[207]);
////		cJSON_AddNumberToObject(ZTN_val_OBJECT, "Load_factor", ztn_data.ztn[208]);
////		cJSON_AddNumberToObject(ZTN_val_OBJECT, "Bat_num", ztn_data.ztn[209]);
////		
////		cJSON_AddNumberToObject(ZTN_val_OBJECT, "Running_time", (ztn_data.ztn[300] << 8 | ztn_data.ztn[301]));
////		cJSON_AddNumberToObject(ZTN_val_OBJECT, "Device_addr", ztn_data.ztn[302]);
////		cJSON_AddNumberToObject(ZTN_val_OBJECT, "Running_day", ztn_data.ztn[303]);
////		cJSON_AddNumberToObject(ZTN_val_OBJECT, "Circle_num", ztn_data.ztn[304]);
////		cJSON_AddNumberToObject(ZTN_val_OBJECT, "day_elenum", (ztn_data.ztn[305] << 8 | ztn_data.ztn[306]));
////		cJSON_AddNumberToObject(ZTN_val_OBJECT, "day_eletime", (ztn_data.ztn[307] << 8 | ztn_data.ztn[308]));
////		cJSON_AddNumberToObject(ZTN_val_OBJECT, "mon_elenum", (ztn_data.ztn[309] << 8 | ztn_data.ztn[310]));
////		cJSON_AddNumberToObject(ZTN_val_OBJECT, "mon_eletime", (ztn_da ta.ztn[311] << 8 | ztn_data.ztn[312]));
////		cJSON_AddNumberToObject(ZTN_val_OBJECT, "sum_elenum", (ztn_data.ztn[313] << 8 | ztn_data.ztn[314]));
////		cJSON_AddNumberToObject(ZTN_val_OBJECT, "day_loadnum", (ztn_data.ztn[315] << 8 | ztn_data.ztn[316]));
////		cJSON_AddNumberToObject(ZTN_val_OBJECT, "mon_loadnum", (ztn_data.ztn[317] << 8 | ztn_data.ztn[318]));
////		cJSON_AddNumberToObject(ZTN_val_OBJECT, "sum_loadnum", (ztn_data.ztn[319] << 8 | ztn_data.ztn[320]));
////		cJSON_AddNumberToObject(ZTN_val_OBJECT, "Light", ztn_data.ztn[321]);
//    cJSON_AddNumberToObject(ZTN_val_OBJECT, "Surplus", ztn_data.surplus);
//    cJSON_AddStringToObject(ZTN_val_OBJECT, "Signal","16");
//		
//		cJSON_AddItemToObject(ZTN_sum_OBJECT, "val", ZTN_val_OBJECT);
//		cJSON* ZTN_sDATA_OBJECT = cJSON_CreateArray();
//    cJSON_AddItemToArray(ZTN_sDATA_OBJECT, ZTN_sum_OBJECT);
//    cJSON_AddItemToObject(ZTN_OBJECT,"sData",ZTN_sDATA_OBJECT);
//		char* my_str = cJSON_Print(ZTN_OBJECT);
//		char send_buff[1024] = {0};
//		switch(XT_config.Net_Mode){
//			case 3:publishMqtt(5,XT_config.Mqtt_client_Config.pubTopic,my_str);break;
//			case 4:ec800n_uart_send("AT+QMTPUBEX=0,0,0,0,\"/ztn/SolarTestT00011_4G/update\",10\r\n",sizeof("AT+QMTPUBEX=0,0,0,0\"/ztn/SolarTestT00011_4G/update\",10\r\n"),">");
//						 delay_ms(5000);
//						 ec800n_uart_send("1111111111\r\n",sizeof("1111111111\r\n"),"QMTPUBEX");
//						 break;
//			default:break;
//		}
//		free(my_str);
//    cJSON_Delete(ZTN_OBJECT);
//		return 1;
//}




//uint8_t ZTN_MQTT_ENCODE(void){
//	char mqtbuf[2048] = "{\
//	\"dCore\":	\"SUN_000002_ETH\",\
//	\"v\":	\"dd_1\",\
//	\"r\":	1,\
//	\"extend\":	{\
//		\"IMEI\":	\"lzh\",\
//		\"SIM\":	\"lzh\",\
//		\"SV\":	\"OPV29\",\
//		\"HV\":	\"NBV38A\"\
//	},\
//	\"sData\":	[{\
//			\"port\":	1,\
//			\"val\":	{\
//				\"Surplus\":	0,\
//				\"Signal\":	\"16\"\
//			}\
//		}]\
//    }";
//		char sum_buf[1024];
//    char s_buf[2048];
//		char inser_buf[256];
//		char tmp_buf[256];
//		char ss_buf[256];
//		char* tmp_str1;
//		char* tmp_str2;
//		char* tmp_str3;
//		char* tmp_str4;
//		for(int i = 0 ; i < XT_config.modbus_count ; i++){
//			if( i == 0 ){
//				tmp_str1 = strtok(mqtbuf ,"{");
//				tmp_str2 = strtok(NULL, "{");
//				tmp_str3 = strtok(NULL, "{");
//				tmp_str4 = strtok(NULL, "{");
//				sprintf(inser_buf,"%s:%d,",XT_config.modbus_data[i],ztn_data.ztn[XT_config.modbus_flag[i]]);
//				sprintf(sum_buf,"%s%s",inser_buf,tmp_str4);
//				sprintf(s_buf,"{%s{%s{%s{%s",tmp_str1,tmp_str2,tmp_str3,sum_buf);
//			}
//			else{
//				sprintf(tmp_buf,"%s",inser_buf);
//				sprintf(ss_buf,"%s%s:%d,",inser_buf,XT_config.modbus_data[i],ztn_data.ztn[XT_config.modbus_flag[i]]);
//				memset(inser_buf,0,strlen(inser_buf));
//				sprintf(inser_buf,"%s",ss_buf);
//				sprintf(sum_buf,"%s%s",ss_buf,tmp_str4);
//				sprintf(s_buf,"{%s{%s{%s{%s",tmp_str1,tmp_str2,tmp_str3,sum_buf);
//			}
//		}
//		printf("s_buf:%s\r\n",s_buf);
//		switch(XT_config.Net_Mode){
//			case 3:if(XT_config.modbus_count == 0 ){
//						 publishMqtt(5,XT_config.Mqtt_client_Config.pubTopic,mqtbuf);
//						 }	
//						 else{
//						 publishMqtt(5,XT_config.Mqtt_client_Config.pubTopic,s_buf);
//						 }
//						break;
//			case 4:ec800n_uart_send("AT+QMTPUBEX=0,0,0,0,\"/ztn/SolarTestT00011_4G/update\",10\r\n",sizeof("AT+QMTPUBEX=0,0,0,0\"/ztn/SolarTestT00011_4G/update\",10\r\n"),">");
//						 delay_ms(5000);
//						 ec800n_uart_send("1111111111\r\n",sizeof("1111111111\r\n"),"QMTPUBEX");
//						 break;
//			default:break;
//		}
//		return 1;
//}


/*
{
	"dCore": "SolarDev_C103", //????
	"data": {
		"V_power": 236,  //????// 		236mv ????
		"V_bat": 10795,	//????// 		10795mv ????
		"I_charge": 0,	//????//  	0mA ????
		"I_output": 34,	//????// 		34mA ????
		"V_basic": 2489,	//????// 		2489mV ????
		"T_bat": 0,		//????//  	0°C  ??????? ????
		"T_inside": 0,	//????// 		0°C  ??????? ????
		"Surplus": 0,	//????// 		0-100%  ????  ????
		"Signal": "16"	//??//    		0-31  ?????
	},
     "quality": {
		"V_power": 0,
		"V_bat": 1,
		"I_charge": 1,
		"I_output": 1,
		"V_basic": 1,	
		"T_bat": 1,	
		"T_inside": 1,
		"Surplus": 1,
		"Signal": 1
	}

}

*/


uint8_t ZTN_MQTT_ENCODE(void){
	static int up_time = 0;
	printf("uptime:%d\r\n",up_time);
	char mqtbuf[2048] = "{\
	\"dCode\":	\"SGW0400008_4G\",\
	\"data\":	{\
						\"Signal\":\"16\"\
						}\
    }";
		char sum_buf[1024];
    char s_buf[2048];
		char inser_buf[256];
		char tmp_buf[256];
		char ss_buf[256];
		char* tmp_str1;
		char* tmp_str2;
		char* tmp_str3;
		char* tmp_str4;
		for(int i = 0 ; i < XT_config.modbus_count ; i++){
			if(up_time%XT_config.modbus_uptime[i] == 0){
				if( i == 0 ){
					tmp_str1 = strtok(mqtbuf ,"{");
					tmp_str2 = strtok(NULL, "{");
					sprintf(inser_buf,"%s:%d,",XT_config.modbus_data[i],ztn_data.ztn[XT_config.modbus_flag[i]]);
					sprintf(sum_buf,"%s%s",inser_buf,tmp_str2);
					sprintf(s_buf,"{%s{%s",tmp_str1,sum_buf);
				}
				else{
					sprintf(tmp_buf,"%s",inser_buf);
					sprintf(ss_buf,"%s%s:%d,",inser_buf,XT_config.modbus_data[i],ztn_data.ztn[XT_config.modbus_flag[i]]);
					memset(inser_buf,0,strlen(inser_buf));
					sprintf(inser_buf,"%s",ss_buf);
					sprintf(sum_buf,"%s%s",ss_buf,tmp_str2);
					sprintf(s_buf,"{%s{%s",tmp_str1,sum_buf);
				}
			}
		}
		if(up_time > 10000){
			up_time = 0;
		}
		switch(XT_config.Net_Mode){
			case 3:if(XT_config.modbus_count == 0){
								if((up_time%5) == 0){
									publishMqtt(5,XT_config.Mqtt_client_Config.pubTopic,mqtbuf);
									printf("mqt_buf:%s\r\n",mqtbuf);
								}
						 }	
						 else{
								if(strlen(s_buf) > 5){
									publishMqtt(5,XT_config.Mqtt_client_Config.pubTopic,s_buf);
								}
						 printf("s_buf:%s\r\n",s_buf);	 
						 }
						break;
			case 4:ec800n_uart_send("AT+QMTPUBEX=0,0,0,0,\"/ztn/SolarTestT00011_4G/update\",10\r\n",sizeof("AT+QMTPUBEX=0,0,0,0\"/ztn/SolarTestT00011_4G/update\",10\r\n"),">");
						 delay_ms(5000);
						 ec800n_uart_send("1111111111\r\n",sizeof("1111111111\r\n"),"QMTPUBEX");
						 break;
			default:break;
		}
		up_time++;
		return 1;
}


