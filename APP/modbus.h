#ifndef _MODBUS_H_
#define _MODBUS_H_


#include "main.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

extern int my_flag;
uint8_t ModbusParse(uint8_t* buf,uint8_t* sended_buf);
int Data_Parse(uint8_t* buf, uint8_t* sended_buf ,int len);
void modbus_data_handle(void);

#endif   // _MODBUS_H_
