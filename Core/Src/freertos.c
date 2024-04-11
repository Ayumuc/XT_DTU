/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
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

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
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
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
//static int Configmode(void);
//int MQTT_ETH_MODE(void);
//int MQTT_4G_MODE(void);
//void W5500_Tcp_client(void);
//uint8_t my_ip[4] = {10,192,178,87};
//void init_Net(void);
//uint8_t cnt_flag=0,sub_flag=0,pub_flag=0;
//uint8_t mpptbuf[8] = {0x01,0x03,0x00,0x00,0x0A,0xAC,0x43,0x17};
//uint16_t time=0;
//#define MQTT_SOCK 5
//uint8_t ZTN_MQTT_ENCODE(void);
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
osThreadId defaultTaskHandle;
osThreadId DataTaskHandle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void const * argument);
void StartTask02(void const * argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* GetIdleTaskMemory prototype (linked to static allocation support) */
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize );

/* USER CODE BEGIN GET_IDLE_TASK_MEMORY */
static StaticTask_t xIdleTaskTCBBuffer;
static StackType_t xIdleStack[configMINIMAL_STACK_SIZE];

void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize )
{
  *ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
  *ppxIdleTaskStackBuffer = &xIdleStack[0];
  *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
  /* place for user code */
}
/* USER CODE END GET_IDLE_TASK_MEMORY */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */
	//Configmode();

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of defaultTask */
  osThreadDef(defaultTask, StartDefaultTask, osPriorityNormal, 0, 128);
  defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);

  /* definition and creation of DataTask */
  osThreadDef(DataTask, StartTask02, osPriorityIdle, 0, 128);
  DataTaskHandle = osThreadCreate(osThread(DataTask), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
	
  /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void const * argument)
{
  /* USER CODE BEGIN StartDefaultTask */

//			printf("mode:%d\r\n",XT_config.Net_Mode);
//			while(1){
//					switch(XT_config.Net_Mode){
//						case 1:W5500_Tcp_client();break;
//						case 3:MQTT_ETH_MODE();break;
//						case 4:MQTT_4G_MODE();break;
//						default:break;
//					}
//			}
//			
  /* Infinite loop */
  /* USER CODE END StartDefaultTask */
}

/* USER CODE BEGIN Header_StartTask02 */
/**
* @brief Function implementing the DataTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask02 */
void StartTask02(void const * argument)
{
  /* USER CODE BEGIN StartTask02 */
  /* Infinite loop */

	//	delay_ms(10);
	
  /* USER CODE END StartTask02 */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

//int MQTT_ETH_MODE(void){
//	
////		int time_485 = 0;
////		init_Net();
////		printf("init_Net OK\r\n");
////		//HAL_UART_Transmit(&huart3, modbus_send_buf[tim_count],8,100);
////		while(1){
////		do_https();
////		cnt_flag=do_mqtt(MQTT_SOCK,XT_config.Mqtt_client_Config.Sip,XT_config.Mqtt_client_Config.SPort,XT_config.Mqtt_client_Config.LPort);
////		if(cnt_flag==0){sub_flag=0;pub_flag=0;time=0;}
////		if(cnt_flag&&sub_flag==0)sub_flag=!subscribMqtt(MQTT_SOCK,XT_config.Mqtt_client_Config.subTopic);
////		if(cnt_flag&&sub_flag&&pub_flag==0){
////			pub_flag=!publishMqtt(MQTT_SOCK,XT_config.Mqtt_client_Config.pubTopic,"hello mqtt");
////		}
////		if(cnt_flag){time++;}
////		if(time==1500){
////			time=0;
////			pingMqtt(MQTT_SOCK);
////			HAL_UART_Transmit(&huart3, modbus_send_buf[tim_count],8,100);
////			while(1){
////				HAL_UART_Receive_DMA(&huart3, RS485_2_BUFF , sizeof(RS485_2_BUFF));
////				time_485++;
////				if(USART3_RX_END_FLAG == 1){
////					tim_count++;
////					if(tim_count >= 3 ){
////						tim_count = 0;
////					}
////					break;
////				}
////				else if(time_485 > 3000){
////					break;
////				}
////				delay_ms(10);
////			}
////		}
////		if(USART3_RX_END_FLAG == 1){
////			ZTN_MQTT_ENCODE();
////			USART3_RX_END_FLAG = 0;
////		}
////		delay_ms(10);
////	}
////	return 1;
//}

//int MQTT_4G_MODE(void){
//	static int FLAG_4G = 0;
//	static int timeout = 2500;
//	static int mqtt_tim = 0;
//	tim_count = 0;
//	timeout++;
//	if(FLAG_4G == 0 ){
//	HAL_GPIO_WritePin(EC600N_PWR_GPIO_Port,EC600N_PWR_Pin,GPIO_PIN_SET);
//	printf("4G UP\r\n");
//	FLAG_4G = 1;
//  ec800n_uart_send("AT\r\n",sizeof("AT\r\n"),"AT");
//	delay_ms(5000);
//	ec800n_uart_send("AT+CPIN?\r\n",sizeof("AT+CPIN?\r\n"),"READY");
//	delay_ms(5000);
//	ec800n_uart_send("AT+CSQ\r\n",sizeof("AT+CSQ\r\n"),"CSQ");
//	delay_ms(5000);
//	ec800n_uart_send("AT+CREG?\r\n",sizeof("AT+CREG?\r\n"),"CREG");
//	delay_ms(5000);
//	ec800n_uart_send("AT+QIACT=1\r\n",sizeof("AT+QIACT=1\r\n"),"OK");
//	delay_ms(5000);
//	ec800n_uart_send("AT+QMTCFG=\"qmtping\",0,30\r\n",sizeof("AT+QMTCFG=\"qmtping\",0,30\r\n"),"OK");
//	delay_ms(5000);
//	ec800n_uart_send("AT+QMTCFG=\"recv/mode\",0,0,1\r\n",sizeof("AT+QMTCFG=\"recv/mode\",0,0,1\r\n"),"OK");
//	delay_ms(5000);
//	ec800n_uart_send("AT+QMTOPEN=0,\"dt.ztn-tech.com\",1883\r\n",sizeof("AT+QMTOPEN=0,\"dt.ztn-tech.com\",1883"),"+QMTOPEN");
//	delay_ms(5000);
//	ec800n_uart_send("AT+QMTCONN=0,\"SolarTestT00011_4G\",\"SolarTest_22AB562F\",\"E4E41CFF8C884B0C5B2DBB9A015BE1B6\"\r\n",sizeof("AT+QMTCONN=0,\"SolarTestT00011_4G\",\"SolarTest_22AB562F\",\"E4E41CFF8C884B0C5B2DBB9A015BE1B6\"\r\n"),"+QMTCONN");
//	delay_ms(5000);
//	ec800n_uart_send("AT+QMTSUB=0,1,\"/ztn/SolarTestT00011_4G/get\",0\r\n",sizeof("AT+QMTSUB=0,1,\"/ztn/SolarTestT00011_4G/get\",0\r\n"),"OK");
//	}
//	if(timeout > 4000){
//		timeout = 0;
//		HAL_UART_Transmit(&huart3, modbus_send_buf[0],8,1000);
//		while(1){
//				HAL_UART_Receive_DMA(&huart3, RS485_2_BUFF , sizeof(RS485_2_BUFF));
//				if(USART3_RX_END_FLAG == 1){
//					cJSON* ZTN_OBJECT = cJSON_CreateObject();
//					cJSON_AddStringToObject(ZTN_OBJECT, "dCore","SolarTestT00011_4G");
//					cJSON_AddStringToObject(ZTN_OBJECT, "v","dd_1");
//					cJSON_AddNumberToObject(ZTN_OBJECT, "r", 1);
//					cJSON* ZTN_EXTERN_OBJECT = cJSON_CreateObject();
//					cJSON_AddStringToObject(ZTN_EXTERN_OBJECT, "IMEI","LZH");
//					cJSON_AddStringToObject(ZTN_EXTERN_OBJECT, "SIM","LZH");
//					cJSON_AddStringToObject(ZTN_EXTERN_OBJECT, "SV","DTU1.01");
//					cJSON_AddStringToObject(ZTN_EXTERN_OBJECT, "HV","XTDTU");
//					cJSON_AddItemToObject(ZTN_OBJECT, "extend", ZTN_EXTERN_OBJECT);
//					cJSON* ZTN_sum_OBJECT = cJSON_CreateObject();
//					cJSON_AddNumberToObject(ZTN_sum_OBJECT, "port", 1);
//					cJSON* ZTN_val_OBJECT = cJSON_CreateObject();
//					switch(mqtt_tim){
//						case 0:
//						cJSON_AddNumberToObject(ZTN_val_OBJECT, "charge_status", ztn_data.ztn[100] );
//						cJSON_AddNumberToObject(ZTN_val_OBJECT, "V_power", ztn_data.ztn[101]);
//						cJSON_AddNumberToObject(ZTN_val_OBJECT, "V_bat", ztn_data.ztn[102]);
//						cJSON_AddNumberToObject(ZTN_val_OBJECT, "I_charge", ztn_data.ztn[103]);
//						mqtt_tim++;
//						break;
//						case 1:
//						cJSON_AddNumberToObject(ZTN_val_OBJECT, "V_output", ztn_data.ztn[104]);
//						cJSON_AddNumberToObject(ZTN_val_OBJECT, "V_load", ztn_data.ztn[105]);
//						cJSON_AddNumberToObject(ZTN_val_OBJECT, "I_load", ztn_data.ztn[106]);
//						cJSON_AddNumberToObject(ZTN_val_OBJECT, "power_charge", ztn_data.ztn[107]);
//						mqtt_tim++;
//						break;
//						case 2:
//						cJSON_AddNumberToObject(ZTN_val_OBJECT, "power_load", ztn_data.ztn[108]);
//						cJSON_AddNumberToObject(ZTN_val_OBJECT, "T_bat", ztn_data.ztn[109]);
//						cJSON_AddNumberToObject(ZTN_val_OBJECT, "T_inside", ztn_data.ztn[110]);
//						mqtt_tim++;
//						break;
//						case 3:
//						cJSON_AddNumberToObject(ZTN_val_OBJECT, "C02", (ztn_data.ztn[111] << 8 | ztn_data.ztn[112]));
//						mqtt_tim++;
//						break;
//						case 4:
//						cJSON_AddNumberToObject(ZTN_val_OBJECT, "Fault_codes", ztn_data.ztn[113]);
//						cJSON_AddNumberToObject(ZTN_val_OBJECT, "System", ztn_data.ztn[114]);
//						cJSON_AddNumberToObject(ZTN_val_OBJECT, "Surplus", ztn_data.surplus);
//						cJSON_AddStringToObject(ZTN_val_OBJECT, "Signal","16");
//						mqtt_tim=0;
//						break;
//						default:break;
//					}
//					cJSON_AddItemToObject(ZTN_sum_OBJECT, "val", ZTN_val_OBJECT);
//					cJSON* ZTN_sDATA_OBJECT = cJSON_CreateArray();
//					cJSON_AddItemToArray(ZTN_sDATA_OBJECT, ZTN_sum_OBJECT);
//					cJSON_AddItemToObject(ZTN_OBJECT,"sData",ZTN_sDATA_OBJECT);
//					char* my_str = cJSON_Print(ZTN_OBJECT);
//					printf("my_str:%s\r\n",my_str);
//					delay_ms(400);
//					char at_buf[100]={0};
//					char mqtt_buf[600]={0};
//					sprintf(at_buf,"AT+QMTPUBEX=0,0,0,0,\"/ztn/SolarTestT00011_4G/update\",%d\r\n",(strlen(my_str)));
//					HAL_UART_Transmit(&huart2, (unsigned char*)at_buf,strlen(at_buf),1000);
//					delay_ms(500);
//					sprintf(mqtt_buf,"%s\r\n\r\n",my_str);
//					printf("mqtt_buf;%d\r\n",strlen(mqtt_buf));
//					HAL_UART_Transmit(&huart2, (unsigned char*)mqtt_buf,strlen(mqtt_buf),1000);
//					free(my_str);
//					cJSON_Delete(ZTN_OBJECT);
//					USART3_RX_END_FLAG = 0;
//					break;
//				}
//				delay_ms(10);
//			}
//	}
//	
//	return 1;
//}

//static int Configmode(void){
//		
//		printf("SW11:%d\r\n",HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_7));
//		printf("SW12:%d\r\n",HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_8));
//		printf("SW13:%d\r\n",HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_9));
//		
//		if(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_9) == GPIO_PIN_SET){
//			 printf("welcome to config mode............\r\n");
//			 board_config_set();
//		}
//		else{
//			printf("welcome to normal mode............\r\n");
//			return 0;
//		}
//		return 1;
//}

//void W5500_RESET(void);
//void put_defaultNet(void);
//void init_Net(void){
//	uint8_t try_times=0;
//	W5500_ChipInit();
//	printf("w5500 init success\r\n");
////	put_defaultNet();
////	printf("put success\r\n");
//// 	while(!do_dns((uint8_t *)"www.baidu.com"));
////	init_dhcp_client();
////	printf("dhcp init success\r\n");
////	while(check_DHCP_state(SOCK_DHCP)!=DHCP_RET_UPDATE){
////			try_times++;
////			if(try_times==255){							//³¬Ê± ÖØÆôÐ¾Æ¬
////				W5500_RESET();
////				init_dhcp_client();
////				try_times=0;
////			}
////			delay_ms(10);
////		}
////	while(!set_Network());
//}

//int ec800n_uart_send(char* tx_buf, uint16_t len ,char* rx_buf){
//	HAL_UART_Transmit(&huart2, (uint8_t*)tx_buf, len,1000);
//	return 1;
//	while(1){
//		HAL_UART_Receive_DMA(&huart2,RECV_4G_BUFF,sizeof(RECV_4G_BUFF));
//		if(Uart_4g_End == 1){
//			if(strstr((char*)RECV_4G_BUFF,rx_buf) != NULL){
//				Uart_4g_End = 0;
//				break;
//			}
//		}
//		delay_ms(20);
//	}
//	return 1;
//}




/* USER CODE END Application */
