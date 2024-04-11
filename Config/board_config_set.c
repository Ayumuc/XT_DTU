#include "board_config_set.h"
#include "usart.h"
#include "board_config.h"
#include "config_handle_task.h"
#include "usart.h"
#include "stdio.h"
int W5500_Mode;
uint8_t board_config_set(void);
#define W5500_TCPCLIENT 0
#define W5500_TCPSERVER 1
#define W5500_MQTT 2
uint8_t config_buff[100];
uint8_t uart1_recv_buf[256];


uint8_t board_config_set(void){
		while(1){
			if(uart1_recv_end_flag ==1){
				HAL_UART_Receive_DMA(&huart5,uart1_recv_buf,sizeof(uart1_recv_buf));
				printf("uart1_rx_len = %d\r\n",uart1_rx_len); 
				printf("recv:%s\r\n",uart1_recv_buf);
				configRecv(uart1_recv_buf, uart1_rx_len);
				configHandler(config_buff);
				uart1_rx_len=0;
				uart1_recv_end_flag=0;	
				memset(uart1_recv_buf,0,sizeof(uart1_recv_buf));
			}			
		}
		return 1;
}



void configRecv(uint8_t *ch, uint16_t len)
{
	if (ch[0] != '{')
	{
		printf("ch[0]:%c\r\n",ch[0]);
		printf("first byte err\r\n");
		return;
	}

	if (ch[1] != '"')
	{
		printf("ch[1]:%c\r\n",ch[1]);
		printf("first byte2 err\r\n");
		return;
	}
	if (ch[len-2] != '"')
	{
		printf("ch[len-2]:%c\r\n",ch[len-2]);
		printf("last byte:%c\r\n",ch[len-4]);
		printf("last byte err\r\n");
		return;
	}
	if (ch[len-1] != '}')
	{
		printf("ch[len-3]:%c\r\n",ch[len-3]);
		printf("last byte2:%c\r\n",ch[len-3]);
		printf("last byte2 err\r\n");
		return;
	}
	memcpy( config_buff, uart1_recv_buf+2, len-4);
}


typedef void (*HANDLER)(uint8_t *buf);
typedef struct{
	char *str;
	HANDLER handler;
}HANDLER_TAB;

void configHandler(uint8_t *buf){
	int i= 0;
	HANDLER_TAB handler_tab[11] = {
									{"hello",    handler_1},
								  {"bye",      handler_2},
								  {"IP",       handler_3},
									{"TCP",      handler_3},
									{"MQTT",     handler_3},
								  {"SET",      handler_3},
								  {"sd2078rtc",handler_3}
	                             };
	for( i = 0; i < 11; i++)
	{
		if (!strncasecmp((char *)buf, handler_tab[i].str, strlen(handler_tab[i].str)))
		{
			handler_tab[i].handler(buf);
		}
	}
	memset(config_buff,0,sizeof(config_buff));
}






























