#ifndef XT_TASK__H
#define XT_TASK__H

#include "main.h"
#include "string.h"

#include "stdio.h"
#include "usart.h"
#include "board_config_set.h"
#include "wizchip_conf.h"
#include "board_config.h"
#include "socket.h"
#include "dns.h"
#include "mqtt_api.h"
#include "w5500api.h"
#include "utility.h"
#include "dhcp.h"
#include "ztn_mqtt.h"
#include "stdlib.h"
#include "httputil.h"
#include "cJSON.h"
#include "RS485.h"
#include "delay.h"
#include "ec800n.h"
#include "tim.h"
#include "modbus.h"

int xt_task_init(void);
uint8_t DataCollect(void);


#endif   // XT_TASK__H