/**
  ******************************************************************************
  * @file    flash_if.h 
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    07/16/2010 
  * @brief   Header for flash_if.c module
  ******************************************************************************
  * @copy
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2010 STMicroelectronics</center></h2>
  */ 

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __FLASH_IF_H
#define __FLASH_IF_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"

/* IAP options */
//#define USE_IAP_TFTP   /* enable IAP using TFTP */
//#define USE_IAP_HTTP   /* enable IAP using HTTP */
//#define USE_LCD        /* enable LCD  */  
//#define USE_DHCP       /* enable DHCP, if disabled static address is used*/

/* Flash Addresses*/   
/* !!! Be sure that USER_FLASH_FIRST_PAGE_ADDRESS do not overlap with IAP code
* When TFTP,HTTP,LCD and DHCP are used, depending on the used compiler
* the following values can be used as start address for the user application code 
*/ 

#if defined ( __CC_ARM   )
        #define USER_FLASH_FIRST_PAGE_ADDRESS 0x08009000
#elif defined (__ICCARM__)
        #define USER_FLASH_FIRST_PAGE_ADDRESS 0x0800A000
#elif defined   (  __GNUC__  )
        #define USER_FLASH_FIRST_PAGE_ADDRESS 0x08010000  
#elif defined   (  __TASKING__  )
        #define USER_FLASH_FIRST_PAGE_ADDRESS 0x0800E000
#endif


#define USER_FLASH_LAST_PAGE_ADDRESS  0x0807F800
#define USER_FLASH_END_ADDRESS        0x0807FFFF 

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
#define USER_FLASH_SIZE   (USER_FLASH_END_ADDRESS - USER_FLASH_FIRST_PAGE_ADDRESS)
#define FLASH_PAGE_SIZE   0x800

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void FLASH_If_Write(__IO uint32_t* Address, uint32_t* Data, uint16_t DataLength);
int8_t FLASH_If_Erase(uint32_t StartSector);
void FLASH_If_Init(void);

#endif /* __FLASH_IF_H */

/******************* (C) COPYRIGHT 2010 STMicroelectronics *****END OF FILE****/
