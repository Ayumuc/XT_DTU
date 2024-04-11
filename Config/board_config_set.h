#ifndef _BOARD_CONFIG_SET_H_
#define _BOARD_CONFIG_SET_H_

#include "main.h"
#include "stdio.h"
#include "string.h"

extern int W5500_Mode;
extern uint8_t board_config_set(void);
void configHandler(uint8_t *buf);
void configRecv(uint8_t *ch, uint16_t len);
#endif   // _BOARD_CONFIG_SET_H_

