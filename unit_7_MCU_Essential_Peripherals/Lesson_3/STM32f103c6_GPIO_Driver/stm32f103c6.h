/*
 * stm32f103c6.h
 *
 *  Created on: Apr 29, 2025
 *      Author: Aya Ramadan
 */

#ifndef INC_STM32F103C6_H_
#define INC_STM32F103C6_H_
// includes
#include "stdlib.h"
#include "stdint.h"

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
/* Base address for memories */
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

#define FLASH_MEMORY_BASE							0X08000000UL
#define SYSTEM_MEMORY_BASE							0X1FFFF000UL
#define SRAM_MEMORY_BASE							0X20000000UL

#define PERIPHERALS_BASE		  					0X40000000UL
#define CORTEX_M3_INTERNAL_PREPHERALS_BASE		    0XE0000000UL

/*-------------------------------------------------------------------------------*/

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
/* base  peripheral addresses */
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

/* RCC */
#define RCC_BASE                                    0x40021000UL

/* GPIO*/
/* A,B fully included in LQFP48 package */
#define GPIOA_BASE                                  0x40010800UL
#define GPIOB_BASE                                  0x40010C00UL
/* C,D partial included in LQFP48 package */
#define GPIOC_BASE                                  0x40011000UL
#define GPIOD_BASE                                  0x40011400UL
/* D not included in LQFP48 package */
#define GPIOE_BASE                                  0x40011800UL

/* EXTI */
#define EXTI_BASE                                   0x40010400UL

/* AFIO */
#define AAFIO_BASE                                  0x40010000UL


/*-------------------------------------------------------------------------------*/

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
// peripheral register
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
// peripheral register RCC
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;

}RCC_Typedef;



//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
// peripheral register GPIO
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

typedef struct
{
	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;

}GPIO_Typedef;

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
// peripheral register EXTI
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RSTR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;

}EXTI_Typedef;

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
// peripheral register AFIO
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t EVCR;
	volatile uint32_t MAPR;
	volatile uint32_t EXTICR1;
	volatile uint32_t EXTICR2;
	volatile uint32_t EXTICR3;
	volatile uint32_t EXTICR4;
	uint32_t         RESERVED0;
	volatile uint32_t MAPR2;

}AFIO_Typedef;


/*-------------------------------------------------------------------------------*/
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
// peripheral Instance
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

/*RCC*/
#define RCC            ((RCC_Typedef*) RCC_BASE )
/* GPIO */
#define GPIOA         ((GPIO_Typedef*) GPIOA_BASE )
#define GPIOB         ((GPIO_Typedef*) GPIOB_BASE )
#define GPIOC         ((GPIO_Typedef*) GPIOC_BASE )
#define GPIOD         ((GPIO_Typedef*) GPIOD_BASE )
#define GPIOE         ((GPIO_Typedef*) GPIOE_BASE )
/*EXTI*/
#define EXTI          ((EXTI_Typedef*) EXTI_BASE )
/*AFIO*/
#define AFIO          ((AFIO_Typedef*) AFIO_BASE )

/*-------------------------------------------------------------------------------*/
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
// clock Enable Macros
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

#define RCC_GPIOA_CLK_EN()            (RCC->APB2ENR |= 1<<2 )
#define RCC_GPIOB_CLK_EN()            (RCC->APB2ENR |= 1<<3 )
#define RCC_GPIOC_CLK_EN()            (RCC->APB2ENR |= 1<<4 )
#define RCC_GPIOD_CLK_EN()            (RCC->APB2ENR |= 1<<5 )
#define RCC_GPIOE_CLK_EN()            (RCC->APB2ENR |= 1<<6 )

#define AFIO_CLK_EN()                 (RCC->APB2ENR |= 1<<0 )

#endif /* INC_STM32F103C6_H_ */
