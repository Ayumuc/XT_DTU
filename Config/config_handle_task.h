#ifndef _CONFIG_HANDLE_TASK_H_
#define _CONFIG_HANDLE_TASK_H_

#include "main.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "board_config.h"

void handler_1(uint8_t *buf);
void handler_2(uint8_t *buf);
void handler_3(uint8_t *buf);
char strHandler(uint8_t *buf);
char saveConfig(DEVICE_CONFIG *s);


#endif   // _CONFIG_HANDLE_TASK_H_

