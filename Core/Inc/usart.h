/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    usart.h
  * @brief   This file contains all the function prototypes for
  *          the usart.c file
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __USART_H__
#define __USART_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */
#define USART1_RX_BUF_SIZE 512
extern volatile uint8_t USART1_RX_LEN;              // ???????????
extern volatile uint8_t USART1_RECV_CPLT_FLAG;      // ??????????????
extern uint8_t USART3_RX_END_FLAG;
#define USART2_RX_BUF_SIZE 512
extern volatile uint8_t USART2_RX_LEN;              // ???????????
extern volatile uint8_t USART2_RECV_CPLT_FLAG;      // ??????????????
extern uint8_t USART2_RX_BUF[USART2_RX_BUF_SIZE];   // ?????????
extern uint8_t USART2_RX_END_FLAG;
#define USART5_RX_BUF_SIZE 512
extern volatile uint8_t USART5_RX_LEN;              // ???????????
extern volatile uint8_t USART5_RECV_CPLT_FLAG;      // ??????????????
/* USER CODE END Includes */

extern UART_HandleTypeDef huart5;

extern UART_HandleTypeDef huart1;

extern UART_HandleTypeDef huart2;

extern UART_HandleTypeDef huart3;

/* USER CODE BEGIN Private defines */
#define        UART1_BUF_SIZE       (512)
#define        UART2_BUF_SIZE       (512)
#define        UART5_BUF_SIZE       (512)
extern     volatile uint16_t  uart1_rx_len;
extern     volatile uint8_t   uart1_recv_end_flag;
extern              uint8_t   uart1_rx_buffer[UART1_BUF_SIZE];
extern     volatile uint16_t  uart2_rx_len;
extern     volatile uint8_t   uart2_recv_end_flag;
extern              uint8_t   uart2_rx_buffer[UART2_BUF_SIZE];
extern     volatile uint16_t  uart3_rx_len;
extern     volatile uint8_t   uart3_recv_end_flag;
extern              uint8_t   uart3_rx_buffer[UART2_BUF_SIZE];
extern     uint8_t web_wait_flag;
extern     uint8_t send_buf[8];
/* USER CODE END Private defines */

void MX_UART5_Init(void);
void MX_USART1_UART_Init(void);
void MX_USART2_UART_Init(void);
void MX_USART3_UART_Init(void);

/* USER CODE BEGIN Prototypes */

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __USART_H__ */

