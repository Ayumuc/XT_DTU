#ifndef _W5500_PORT_HAL_
#define _W5500_PORT_HAL_

#include "wizchip_conf.h"
#include "stm32f4xx.h"
#include <string.h>
#include <stdio.h>

#define W5500_SPI_HANDLE    hspi1
#define W5500_CS_PORT       GPIOD
#define W5500_CS_PIN        GPIO_PIN_7
#define W5500_RST_PORT      GPIOD
#define W5500_RST_PIN       GPIO_PIN_4

#define DEFAULT_MAC_ADDR    {0x00,0xf1,0xbe,0xc4,0xa1,0x05}
#define DEFAULT_IP_ADDR     {192,168,0,136}
#define DEFAULT_SUB_MASK    {255,255,255,0}
#define DEFAULT_GW_ADDR     {192,168,0,1}
#define DEFAULT_DNS_ADDR    {8,8,8,8}

/* ???????????????,??????100M????? */
#define USE_AUTONEGO

/* ??????????????????DHCP */
//#define USE_DHCP

extern SPI_HandleTypeDef W5500_SPI_HANDLE;

void w5500_network_info_show(void);
int w5500_init(void);

#endif