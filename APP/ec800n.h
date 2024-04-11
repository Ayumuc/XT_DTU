#ifndef EC800N__H
#define EC800N__H

#include "main.h"
#include "string.h"

int ec800n_uart_send(char* tx_buf, uint16_t len ,char* rx_buf);
extern uint8_t RECV_4G_BUFF[512];
extern uint8_t Uart_4g_End;
#endif   // _MODBUS_H_

