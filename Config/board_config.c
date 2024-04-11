
#include "main.h"
#include "stdio.h"
#include "board_config.h"
#include "string.h"
#include "stdlib.h"
#include "flash.h"
#include "ztn_mqtt.h"
#include "modbus.h"
#include "stm32f4xx_hal_uart.h"
DEVICE_CONFIG XT_config;
#define FIRSTBOOT                            0xaa
#define ETH_MODE_TCP_CLINET 1
#define ETH_MODE_TCP_SVERVE 2
#define ETH_MODE_MQTT       3
#define MODE_4G_MQTT        4
#define TYPE_SUN 1

uint8_t Local_ip[4] = {192,168,31,201};
uint8_t Local_nm[4] = {255,255,0,0};
uint8_t Local_gw[4] = {192,168,31,1};
uint8_t Mqtt_sip[4]={47,107,63,235};
int Mqtt_sPort = 1883;
int Mqtt_lPort = 5500;
char Mqtt_pubTopic[256] = "/sgw/SGW0400008_4G/update";
char Mqtt_subTopic[256] = "/sgw/SGW0400008_4G/get";
char Mqtt_ClientId[256] = "SGW0400008_4G";
int Mqtt_keepalive = 180;
char Mqtt_Username[256] = "SGW04_36859FCC";
char mqtt_Password[256] = "A29C1905B33A36FB577A4983967B1790";


uint8_t Tcp_Client_dest_ip[4] = {192,168,0,190};
int Tcp_Client_dest_port = 6000;

int isFirstBoot(void)
{
	DEVICE_CONFIG* XT_config = readConfig();
	if(XT_config->firstBoot != FIRSTBOOT)
	{
		return 1;
	}
	return 0;
}

char saveConfig(DEVICE_CONFIG *s);
uint8_t Board_config_init(void){
	printf("----board init-----\r\n");
	XT_config.modbus_count = 0;
	for(int i = 0 ; i < 256 ; i++){
		XT_config.modbus_flag[i] = 0;
	}
	for(int i = 0 ; i < 40 ; i++){
		sprintf(XT_config.modbus_data[i],"%s","");
	}
	sprintf(XT_config.Version,"%s","V1.0.1");
	XT_config.Type = TYPE_SUN;
	XT_config.firstBoot = FIRSTBOOT;
	XT_config.Net_Mode = ETH_MODE_MQTT;
	//Read config first
	Read_Config();
	//set Local network
	Local_network_init();
	//set Tcp_client_config
	Tcp_client_config_init();
	//set MQTT client config
	Mqtt_client_config_init();
	
	Usart_Config_init();
	
	XT_config.task_count = 0;
	memset(ztn_data.ztn,0,3000);
	saveConfig(&XT_config);
	return 1;
}

uint8_t Read_Config(void){
	return 1;
}

uint8_t Local_network_init(void){
	//Local IP init
	XT_config.Config_network_local.Local_ip[0] = Local_ip[0];
	XT_config.Config_network_local.Local_ip[1] = Local_ip[1];
	XT_config.Config_network_local.Local_ip[2] = Local_ip[2];
	XT_config.Config_network_local.Local_ip[3] = Local_ip[3];
	//Local NM init
	XT_config.Config_network_local.Local_nm[0] = Local_nm[0];
	XT_config.Config_network_local.Local_nm[1] = Local_nm[1];
	XT_config.Config_network_local.Local_nm[2] = Local_nm[2];
	XT_config.Config_network_local.Local_nm[3] = Local_nm[3];
	//Local GW init
	XT_config.Config_network_local.Local_gw[0] = Local_gw[0];
	XT_config.Config_network_local.Local_gw[1] = Local_gw[1];
	XT_config.Config_network_local.Local_gw[2] = Local_gw[2];
	XT_config.Config_network_local.Local_gw[3] = Local_gw[3];
	
	return 1;
}

uint8_t Tcp_client_config_init(void){
	//TCPclient ip init
	XT_config.Tcp_Client_mode.Tcp_dest_ip[0] = Tcp_Client_dest_ip[0];
	XT_config.Tcp_Client_mode.Tcp_dest_ip[1] = Tcp_Client_dest_ip[1];
	XT_config.Tcp_Client_mode.Tcp_dest_ip[2] = Tcp_Client_dest_ip[2];
	XT_config.Tcp_Client_mode.Tcp_dest_ip[3] = Tcp_Client_dest_ip[3];
	//Tcpclinet port init
	XT_config.Tcp_Client_mode.Tcp_dest_port = Tcp_Client_dest_port;
	
	return 1;
}

uint8_t Mqtt_client_config_init(void){
	
	XT_config.Mqtt_client_Config.Sip[0] = Mqtt_sip[0];
	XT_config.Mqtt_client_Config.Sip[1] = Mqtt_sip[1];
	XT_config.Mqtt_client_Config.Sip[2] = Mqtt_sip[2];
	XT_config.Mqtt_client_Config.Sip[3] = Mqtt_sip[3];
	
	XT_config.Mqtt_client_Config.SPort = Mqtt_sPort;
	
	XT_config.Mqtt_client_Config.LPort = Mqtt_lPort;
	
	memcpy(XT_config.Mqtt_client_Config.pubTopic,Mqtt_pubTopic,sizeof(Mqtt_pubTopic));
	
	memcpy(XT_config.Mqtt_client_Config.subTopic,Mqtt_subTopic,sizeof(Mqtt_subTopic));
	
	memcpy(XT_config.Mqtt_client_Config.mqttClientId,Mqtt_ClientId,sizeof(Mqtt_ClientId));
	
	XT_config.Mqtt_client_Config.keepalive = Mqtt_keepalive;
	
	memcpy(XT_config.Mqtt_client_Config.mqttUsername,Mqtt_Username,sizeof(Mqtt_Username));
	
	memcpy(XT_config.Mqtt_client_Config.password,mqtt_Password,sizeof(mqtt_Password));
	
	return 1;
	
}

int Usart_Config_init(void){
	 XT_config.Usart_Config.rs485_1_baut = 9600;
	 XT_config.Usart_Config.rs485_2_baut = 9600;
	 XT_config.Usart_Config.rs232_baut = 9600;
	
	 XT_config.Usart_Config.rs485_1_wordlength = UART_WORDLENGTH_8B;
	 XT_config.Usart_Config.rs485_2_wordlength = UART_WORDLENGTH_8B;
	 XT_config.Usart_Config.rs232_wordlength = UART_WORDLENGTH_8B;

	 XT_config.Usart_Config.rs485_1_stopbit = UART_STOPBITS_1;
	 XT_config.Usart_Config.rs485_2_stopbit = UART_STOPBITS_1;
	 XT_config.Usart_Config.rs232_stopbit = UART_STOPBITS_1;
	
	 XT_config.Usart_Config.rs485_1_parity = UART_PARITY_NONE;
	 XT_config.Usart_Config.rs485_2_parity = UART_PARITY_NONE;
	 XT_config.Usart_Config.rs232_parity = UART_PARITY_NONE;
	
	 return 1;
}


STM32FLASH_STATUS STM32FLASH_Write(uint32_t WriteAddr,uint32_t *pBuffer,uint16_t NumToWrite);
#define CONFIG_DATA_ADDR					 0x080F0000
char saveConfig(DEVICE_CONFIG *s)
{
	printf("size of DEVICE_CONFIG %d bytes\r\n", sizeof(DEVICE_CONFIG));
	int ret = STM32FLASH_Write(CONFIG_DATA_ADDR, (uint32_t *)s, sizeof(DEVICE_CONFIG)/4);
	printf("ret:%d\r\n",ret);
  return ret;
}


DEVICE_CONFIG* readConfig(void)//????
{
	STM32FLASH_Read(CONFIG_DATA_ADDR, (uint32_t *)&XT_config, sizeof(DEVICE_CONFIG)/4);
	//memcpy(&config,(unsigned int *)CONFIG_DATA_ADDR,sizeof(DEVICE_CONFIG));
	return &XT_config;
}

int Config_Printf(void){
	printf("-----------Device Config------------------\r\n");
	printf("\r\n");
	printf("-------Local Network Config-----------\r\n");
	printf("Local IP:%d.%d.%d.%d\r\n",XT_config.Config_network_local.Local_ip[0] ,XT_config.Config_network_local.Local_ip[1] ,XT_config.Config_network_local.Local_ip[2] ,XT_config.Config_network_local.Local_ip[3]);
	printf("Local SN:%d.%d.%d.%d\r\n",XT_config.Config_network_local.Local_nm[0] ,XT_config.Config_network_local.Local_nm[1] ,XT_config.Config_network_local.Local_nm[2] ,XT_config.Config_network_local.Local_nm[3]);
	printf("Local GW:%d.%d.%d.%d\r\n",XT_config.Config_network_local.Local_gw[0] ,XT_config.Config_network_local.Local_gw[1] ,XT_config.Config_network_local.Local_gw[2] ,XT_config.Config_network_local.Local_gw[3]);
	printf("--------------------------------------\r\n");
	printf("\r\n");
	printf("------------Network Mode---------------\r\n");
	switch(XT_config.Net_Mode){
		case ETH_MODE_TCP_CLINET:printf("Network Mode:ETH_MODE_TCP_CLINET\r\n");break;
		case ETH_MODE_TCP_SVERVE:printf("Network Mode:ETH_MODE_TCP_SVERVE\r\n");break;
		case ETH_MODE_MQTT:printf("Network Mode:ETH_MODE_MQTT\r\n");break;
		case MODE_4G_MQTT:printf("Network Mode:MODE_4G_MQTT\r\n");break;
		default:break;
	}
	printf("--------------------------------------\r\n");
	printf("\r\n");
	printf("----------Tcp Client Mode-------------\r\n");
	printf("Tcp Client SIP:%d.%d.%d.%d\r\n",XT_config.Tcp_Client_mode.Tcp_dest_ip[0] ,XT_config.Tcp_Client_mode.Tcp_dest_ip[1] ,XT_config.Tcp_Client_mode.Tcp_dest_ip[2] ,XT_config.Tcp_Client_mode.Tcp_dest_ip[3]);
	printf("Tcp Client SPORT:%d\r\n",XT_config.Tcp_Client_mode.Tcp_dest_port);
	printf("--------------------------------------\r\n");
	printf("\r\n");
	printf("-----------ETH MQTT Mode--------------\r\n");
	printf("MQTT SIP:%d.%d.%d.%d\r\n",XT_config.Mqtt_client_Config.Sip[0] ,XT_config.Mqtt_client_Config.Sip[1] ,XT_config.Mqtt_client_Config.Sip[2] ,XT_config.Mqtt_client_Config.Sip[3]);
	printf("MQTT SPORT:%d\r\n",XT_config.Mqtt_client_Config.SPort);
	printf("MQTT LPORT:%d\r\n",XT_config.Mqtt_client_Config.LPort);
	printf("MQTT PUB_TPOIC:%s\r\n",XT_config.Mqtt_client_Config.pubTopic);
	printf("MQTT SUB_TPOIC:%s\r\n",XT_config.Mqtt_client_Config.subTopic);
	printf("MQTT CLINET_ID:%s\r\n",XT_config.Mqtt_client_Config.mqttClientId);
	printf("MQTT KEEPALIVE:%d\r\n",XT_config.Mqtt_client_Config.keepalive);
	printf("MQTT USR_NAME:%s\r\n",XT_config.Mqtt_client_Config.mqttUsername);
	printf("MQTT USR_PWD:%s\r\n",XT_config.Mqtt_client_Config.password);
	printf("--------------------------------------\r\n");
	printf("\r\n");
	
	printf("--------------------------------------\r\n");
	printf("\r\n");
	printf("----------Usart Config-------------\r\n");
	printf("RS485 1 BAUT:%d\r\n",XT_config.Usart_Config.rs485_1_baut);
	printf("RS485 2 BAUT:%d\r\n",XT_config.Usart_Config.rs485_2_baut);
	printf("RS232 BAUT:%d\r\n",XT_config.Usart_Config.rs232_baut);
	printf("--------------------------------------\r\n");
	printf("\r\n");
	return 1;
}


uint8_t Data_init(void){
	ztn_data.charge_status = 0;
	ztn_data.v_power = 0;
	ztn_data.v_bat = 0;
	ztn_data.i_charge = 0;
	ztn_data.v_output = 0;
	ztn_data.v_load = 0;
	ztn_data.i_load = 0;
	ztn_data.power_charge = 0;
	ztn_data.power_load = 0;
	ztn_data.T_bat = 0;
	ztn_data.T_inside = 0;
	ztn_data.surplus = 0;
	memset(ztn_data.ztn,0,sizeof(ztn_data.ztn));
	return 1;
}





