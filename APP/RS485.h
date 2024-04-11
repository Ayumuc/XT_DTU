#ifndef RS485__h
#define RS485__h

#include "main.h"
#include "stdio.h"
#include "usart.h"
#include "string.h"
#include "stdlib.h"
#define MAX_NUMBER 70

typedef struct Encode_data{
		uint8_t Device_id;
		uint8_t Function_id;
		uint8_t First_addr[2];
		uint16_t Addr_Num;
		uint16_t crc;
}Encode_Data;

typedef struct Decode_data{
		uint8_t Device_id;
		uint8_t Function_id;
		uint8_t Data_NUM;
		uint16_t Data;
		uint16_t crc;
}decode_data;

extern uint8_t RS485_2_BUFF[MAX_NUMBER];
extern uint8_t RS485_2_Recv_flag;
extern Encode_Data Data_485;
extern decode_data Decode_485data;
void RS485_Data_Handle(uint8_t* buf);
void Start485Task(void const * argument);
unsigned short int getModbusCRC16(unsigned char *_pBuf, unsigned short int _usLen);





#endif

