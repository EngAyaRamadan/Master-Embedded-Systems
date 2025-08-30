/*
 * stm32_f103c6_gpio_driver.h
 *
 *  Created on: Apr 29, 2025
 *      Author: QUADRO
 */

#ifndef INC_STM32_F103C6_RCC_DRIVER_H_
#define INC_STM32_F103C6_RCC_DRIVER_H_

// includes
#include "stm32f103c6.h"
#include "stm32_f103c6_gpio_driver.h"

/*-------------------------------------------------------------------------------*/

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
/* Macros Configuration  */
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
#define HSI_RC_CLK       (uint32_t)16000000
#define HSE_RC_CLK       (uint32_t)8000000



/*-------------------------------------------------------------------------------*/

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
/* APIs Supported by "MCAL" DRIVER */
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*


/* USART Assume operate on HSI -> 8 MHz */
uint32_t MCAL_RCC_GetSYS_CLK2Freq( void );
uint32_t MCAL_RCC_GetHCLKFreq    ( void );
uint32_t MCAL_RCC_GetPCLK1Freq   ( void );
uint32_t MCAL_RCC_GetPCLK2Freq   ( void );


#endif /* INC_STM32_F103C6_RCC_DRIVER_H_ */
