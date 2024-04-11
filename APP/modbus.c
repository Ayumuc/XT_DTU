#include "modbus.h"
#include "ztn_mqtt.h"
#include "main.h"
#include "string.h"
#include "RS485.h"
#include "board_config.h"
#define READ_RIGISTER 3
int my_flag;

uint8_t ModbusParse(uint8_t* buf,uint8_t* sended_buf){
	
	uint8_t Function = buf[1];
	uint8_t Data_len = buf[2];
	switch(Function){
		case READ_RIGISTER:Data_Parse(buf,sended_buf,Data_len);break;
		default:break;
	}
	return 1;
}



//int Data_Parse(uint8_t* buf, uint8_t* sended_buf ,int len){
//	printf("data:");
//	for(int i = 0 ; i < MAX_NUMBER ; i++){
//		printf(" %02x",RS485_2_BUFF[i]);
//	}
//	printf("\r\n");
//	int modbus_tim = ((tim_count+1)*100);
//	printf("modbus_tim:%d\r\n",modbus_tim);
//	for(int i = 0 ; i < len ; i+=2){
//		ztn_data.ztn[modbus_tim] = (RS485_2_BUFF[i+3] << 8 | RS485_2_BUFF[i+4]);
//		printf("ztn[%d]:%d\r\n",modbus_tim,ztn_data.ztn[modbus_tim]);
//		modbus_tim = modbus_tim + 1;
//	}
//	//modbus_data_handle();
//	return 1;
//}

int Data_Parse(uint8_t* buf, uint8_t* sended_buf ,int len){
	printf("data:");
	for(int i = 0 ; i < MAX_NUMBER ; i++){
		printf(" %02x",RS485_2_BUFF[i]);
	}
	printf("\r\n");
	switch(XT_config.modbus_dataType[my_flag]){
		case 3:ztn_data.ztn[XT_config.modbus_flag[my_flag]] = (RS485_2_BUFF[3] << 8 | RS485_2_BUFF[4]);break;
		case 5:ztn_data.ztn[XT_config.modbus_flag[my_flag]] = ((RS485_2_BUFF[3] << 24) | (RS485_2_BUFF[4] << 16))|((RS485_2_BUFF[5] << 8 )| RS485_2_BUFF[6]);
		default:break;
	}
	
	printf("ztn[%d]:%d\r\n",my_flag,ztn_data.ztn[XT_config.modbus_flag[my_flag]]);
	my_flag++;
	//modbus_data_handle();
	return 1;
}

void modbus_data_handle(void){
	switch(tim_count){
		case 1:
//		ztn_data.charge_status = RS485_2_BUFF[3] << 8 | RS485_2_BUFF[4];
//		ztn_data.v_power = RS485_2_BUFF[5] << 8 | RS485_2_BUFF[6];
//		ztn_data.v_bat = RS485_2_BUFF[7] << 8 | RS485_2_BUFF[8];
//		ztn_data.i_charge = RS485_2_BUFF[9] << 8 | RS485_2_BUFF[10];
//		ztn_data.v_output = RS485_2_BUFF[11] << 8 | RS485_2_BUFF[12];
//		ztn_data.v_load = RS485_2_BUFF[13] << 8 | RS485_2_BUFF[14];
//		ztn_data.i_load = RS485_2_BUFF[15] << 8 | RS485_2_BUFF[16];
//		ztn_data.power_charge = RS485_2_BUFF[17] << 8 | RS485_2_BUFF[18];
//		ztn_data.power_load = RS485_2_BUFF[19] << 8 | RS485_2_BUFF[20];
//		ztn_data.T_bat = RS485_2_BUFF[21] << 8 | RS485_2_BUFF[22];
//		ztn_data.T_inside = RS485_2_BUFF[23] << 8 | RS485_2_BUFF[24];
//		ztn_data.surplus = RS485_2_BUFF[25] << 8 | RS485_2_BUFF[26];
		break;
		case 2:break;
	}
}

