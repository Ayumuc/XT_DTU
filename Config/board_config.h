#ifndef _BOARD_CONFIG_H_
#define _BOARD_CONFIG_H_

#include "main.h"

typedef struct {
		uint8_t Local_ip[4];
		uint8_t Local_nm[4];
		uint8_t Local_gw[4];
}Config_Network_Local;

typedef struct {
		uint8_t Tcp_dest_ip[4];
	  int Tcp_dest_port;
}Tcp_client_mode;

typedef struct {
		uint8_t Sip[4];
	  int SPort;
		int LPort;
		char pubTopic[256];
		char subTopic[256];
		char mqttClientId[256];
		int 	keepalive;
		char mqttUsername[256];
		char password[256];
}Mqtt_client_config;

typedef struct {
		int rs485_1_baut;
		int rs485_2_baut;
		int rs232_baut;
	
		uint8_t rs485_1_wordlength;
		uint8_t rs485_2_wordlength;
		uint8_t rs232_wordlength;
	
		uint8_t rs485_1_stopbit;
		uint8_t rs485_2_stopbit;
		uint8_t rs232_stopbit;
	
		uint8_t rs485_1_parity;
		uint8_t rs485_2_parity;
		uint8_t rs232_parity;
		
}Usart_config;


typedef struct
{
	int modbus_count;
	int modbus_flag[256];
	int modbus_dataType[256];
	int modbus_uptime[256];
	int modbus_period[256];
	char modbus_data[40][60];
	char Version[126];
	int Type;
	int firstBoot;
	int Net_Mode;
	Config_Network_Local Config_network_local;
	Tcp_client_mode Tcp_Client_mode;
	Mqtt_client_config Mqtt_client_Config;
	Usart_config Usart_Config;
	int task_count;
}DEVICE_CONFIG;

extern DEVICE_CONFIG XT_config;

int isFirstBoot(void);
DEVICE_CONFIG* readConfig(void);
extern uint8_t Board_config_init(void);
uint8_t Local_network_init(void);
uint8_t Tcp_client_config_init(void);
uint8_t Read_Config(void);
uint8_t Mqtt_client_config_init(void);
int Config_Printf(void);
uint8_t Data_init(void);
int Usart_Config_init(void);


#endif   // _CONFIG_H_

