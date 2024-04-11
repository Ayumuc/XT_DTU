#ifndef _W5500API_H_
#define _W5500API_H_

#include "delay.h"
#include "spi.h"
#include "w5500.h"
#include "socket.h"
#include "utility.h"

#define	MAX_SOCK_NUM		8

#define WIZ_RESET		      GPIO_Pin_0
#define WIZ_RESET_PORT    GPIOB
#define WIZ_RESET_RCC			RCC_APB2Periph_GPIOB



typedef struct _W5500_CONFIG
{
	uint8 mac[6];			//MAC��ַ
  uint8 lip[4];			//����IP
  uint8 sub[4];			//��������
  uint8 gw[4];			//����
	uint8 dns[4];			//DNS
	uint8 rip[4];			//DNS ��������IP
}W5500_CONFIG;	

extern W5500_CONFIG NET_CONFIG;

void Reset_W5500(void);			//����W5500
void init_W5500(void);//��ʼ��W5500оƬ
uint8 set_Network(void);//�����������
uint8 PHY_check(void);//��������Ƿ�����

#endif
