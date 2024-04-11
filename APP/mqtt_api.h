#ifndef __MQTT_API_H
#define __MQTT_API_H
#include "w5500api.h"

#define MAX_OVERTIME 300 	//3s��ʱ
//���к���
uint8 do_mqtt(SOCKET Socket,uint8 *sip,uint16 sport,uint16 lport);
//MQTT ping����
uint8 pingMqtt(uint8 Socket);
//MQTT������Ϣ����
uint8 publishMqtt(uint8 Socket,char *pTopic,char *pMessage);
uint8_t mqtt_rechandle(unsigned char* buf);
//MQTT���ĺ���
uint8 subscribMqtt(uint8 Socket,char *pTopic);
//MQTT��������Ϣ����
void dealPublish(SOCKET Socket,uint8 *msgbuf,uint16 msglen);
#endif
