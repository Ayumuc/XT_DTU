#ifndef __DELAY_H
#define __DELAY_H
#include "stm32f407xx.h"	
#include "stm32f4xx.h"	
 
void delay_s(uint16_t s);
void delay_ms(uint16_t ms);
void delay_us(uint32_t us);

#endif
