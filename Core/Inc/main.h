/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define NET_LED_Pin GPIO_PIN_14
#define NET_LED_GPIO_Port GPIOD
#define GPS_LED_Pin GPIO_PIN_15
#define GPS_LED_GPIO_Port GPIOD
#define STA_LED_Pin GPIO_PIN_6
#define STA_LED_GPIO_Port GPIOC
#define SW11_Pin GPIO_PIN_7
#define SW11_GPIO_Port GPIOC
#define W5500_Vin_Pin GPIO_PIN_8
#define W5500_Vin_GPIO_Port GPIOA
#define RS485_1_TX_Pin GPIO_PIN_10
#define RS485_1_TX_GPIO_Port GPIOC
#define RS485_1_RX_Pin GPIO_PIN_11
#define RS485_1_RX_GPIO_Port GPIOC
#define SPI3_RST_Pin GPIO_PIN_4
#define SPI3_RST_GPIO_Port GPIOD
#define RJ_PEN_Pin GPIO_PIN_5
#define RJ_PEN_GPIO_Port GPIOD
#define SPI3_CS_Pin GPIO_PIN_7
#define SPI3_CS_GPIO_Port GPIOD

/* USER CODE BEGIN Private defines */
#define EC600N_PWR_GPIO_Port GPIOB
#define EC600N_PWR_Pin GPIO_PIN_0
extern uint8_t modbus_send_buf[9][8];
extern int tim_count;
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
