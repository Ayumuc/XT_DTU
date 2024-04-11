/*
**************************************************************************************************
* @file    		w5500_conf.c
* @author  		WIZnet Software Team 
* @version 		V1.0
* @date    		2015-12-12
* @brief  		����MCU����ֲW5500������Ҫ�޸ĵ��ļ�������W5500��MAC��IP��ַ
**************************************************************************************************
*/
#include <stdio.h> 
#include <string.h>

#include "w5500_conf.h"

#include "utility.h"
#include "w5500.h"
#include "dhcp.h"

CONFIG_MSG  ConfigMsg;																	/*���ýṹ��*/
EEPROM_MSG_STR EEPROM_MSG;															/*EEPROM�洢��Ϣ�ṹ��*/

/*����MAC��ַ,������W5500�����������ͬһ�ֳ���������ʹ�ò�ͬ��MAC��ַ*/
uint8 mac[6]={0x00,0x08,0xdc,0x11,0x11,0x11};

/*����Ĭ��IP��Ϣ*/
uint8 local_ip[4]={192,168,1,88};												/*����W5500Ĭ��IP��ַ*/
uint8 subnet[4]={255,255,255,0};												/*����W5500Ĭ����������*/
uint8 gateway[4]={192,168,1,1};													/*����W5500Ĭ������*/
uint8 dns_server[4]={114,114,114,114};									/*����W5500Ĭ��DNS*/

uint16 local_port=5000;	                       					/*���屾�ض˿�*/

/*����Զ��IP��Ϣ*/
uint8  remote_ip[4]={192,168,0,100};											/*Զ��IP��ַ*/
uint16 remote_port=5000;																/*Զ�˶˿ں�*/

/*IP���÷���ѡ��������ѡ��*/
uint8	ip_from=IP_FROM_DHCP;				

uint8 dhcp_ok=0;																				/*dhcp�ɹ���ȡIP*/
uint32	ms=0;																						/*�������*/
																/*DHCP���м���*/
vu8	ntptimer = 0;																				/*NPT�����*/

/**
*@brief		����W5500��IP��ַ
*@param		��
*@return	��
*/

void set_w5500_mac(void)
{
  // ����������Ϣ��������Ҫѡ��
  ConfigMsg.sw_ver[0]=FW_VER_HIGH;
  ConfigMsg.sw_ver[1]=FW_VER_LOW;
  
  memcpy(ConfigMsg.mac, mac, 6);
  setSHAR(ConfigMsg.mac);
  getSHAR(mac);
  printf(" W5500 MAC��ַ  : %02x.%02x.%02x.%02x.%02x.%02x\r\n", mac[0],mac[1],mac[2],mac[3],mac[4],mac[5]);
}

void reboot(void)
{
  pFunction Jump_To_Application;
  uint32 JumpAddress;
  printf(" ϵͳ�����С���\r\n");
  //JumpAddress = *(vu32*) (0x00000004);
  Jump_To_Application = (pFunction) JumpAddress;
  Jump_To_Application();
}



