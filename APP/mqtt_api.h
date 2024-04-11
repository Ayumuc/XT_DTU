#ifndef __MQTT_API_H
#define __MQTT_API_H
#include "w5500api.h"

#define MAX_OVERTIME 300 	//3s超时
//运行函数
uint8 do_mqtt(SOCKET Socket,uint8 *sip,uint16 sport,uint16 lport);
//MQTT ping函数
uint8 pingMqtt(uint8 Socket);
//MQTT发布消息函数
uint8 publishMqtt(uint8 Socket,char *pTopic,char *pMessage);
uint8_t mqtt_rechandle(unsigned char* buf);
//MQTT订阅函数
uint8 subscribMqtt(uint8 Socket,char *pTopic);
//MQTT处理订阅消息函数
void dealPublish(SOCKET Socket,uint8 *msgbuf,uint16 msglen);
#endif
