///*
// * stm32_f103c6_gpio_driver.h
// *
// *  Created on: Apr 29, 2025
// *      Author: QUADRO
// */
//
//

#ifndef INC_STM32_F103C6_SPI_H_
#define INC_STM32_F103C6_SPI_H_

//Includes
#include "stm32f103c6.h"
#include "Stm32_F103C6_gpio_driver.h"

struct S_IRQ_SRC
{
	uint8_t TXE:1;      //Tx buffer empty interrupt
	uint8_t RXNE:1;     //Rx buffer not empty interrupt
	uint8_t ERRI:1;     //Error interrupt
	uint8_t Reserved:5;
};

//Configuration Structure
typedef struct
{

	uint16_t         Device_Mode;     		  // Specifies the SPI operating Mode @ref SPI_Device_Mode

	uint16_t  	     Communication_Mode ; 	  // Specifies the SPI bidirectional Mode state @ref SPI_Communication_Mode

	uint16_t 		 Frame_Format;			  // Specifies the LSB or MSB @ref SPI_Frame_Format

	uint16_t 		 DataSize ;			      //@ref SPI_DataSize.

	uint16_t 		 CLKPolarity ;			  //@ref SPI_CLKPolarity

	uint16_t 		 CLKPhase ;				  //@ref SPI_CLKPhase

	uint16_t	     NSS ;				      //Specifies whether the NSS signal is managed by
	//hardware(NSS pin ) or by software using the SSI bitenable @ref SPI_NSS
	uint16_t	     SPI_BAUDRATEPRESCALER ;  /* Specifies the Baud Rate prescaler value which will be
	                                            used to configure the transmit and receive SCK clock
	                                            this parameter can be a value of @ref SPI_BAUDRATEPRESCALER
	                                            @note the communication clock is derived from the master
	                                            clock. the slave clock does not need to be set */
	// take care you have to configure RCC to enter the correct clock to APB2 >> to SPI

	uint16_t         IRQ_Enable ;              //@ref SPI_IRQ_Enable

	void(* P_IRQ_CallBack)(struct S_IRQ_SRC irq_src ) ; //Set the C Function() which will be called once the IRQ  Happen

}SPI_Config;



// * =======================================================================================
//Reference Macros
// * =======================================================================================

/* @ref SPI_Device_Mode */
#define SPI_Device_Mode_SLAVE                         (0x00000000U)
#define SPI_Device_Mode_MASTER                        (0x1U<<2)

/* @ref SPI_Communication_Mode */
#define SPI_DIRECTIONAL_2LINES                        (0x00000000U)// 2 line full duplex
#define SPI_DIRECTIONAL_2LINES_RXONLY                 (0x1U<<10)//CR1.Bit 10 RXONLY: Receive only
#define SPI_DIRECTIONAL_1LINE_receive_only            (0x1U<<15)//CR1.Bit 15 BIDIMODE: Bidirectional data mode enable
#define SPI_DIRECTIONAL_1LINE_transmit_only           (0x1U<<15) | (0x1U<<14) //CR1.Bit 15 BIDIMODE: Bidirectional data mode enable & Bit 14 BIDIOE : output enable in bidirectional mode

/*@ref SPI_Frame_Format*/
#define SPI_Frame_Format_MSB_transmited_first         (0x00000000U)
#define SPI_Frame_Format_LSB_transmited_first         (0x1U<<7) //Bit 7 LSBFIRST:frame format

/* @ref SPI_DataSize*/
#define SPI_DataSize_8BIT                             (0x00000000U)
#define SPI_DataSize_16BIT                            (0x1U<<11) //CR1. Bit 11 DFF:Data frame format

/* @ref SPI_CLKPolarity */
#define SPI_CLKPolarity_LOW_when_idle                 (0x00000000U)
#define SPI_CLKPolarity_HIGH_when_idle                (0x1U<<1) //Bit 1 CPOL:clock polarity

/* @ref SPI_CLKPhase */
#define SPI_Clock_Phase_1EDGE_first_data_capture_edge      (0x00000000U)
#define SPI_Clock_Phase_2EDGE_first_data_capture_edge      (0x1U<<0) // Bit 0 CPOHA:clock Phase

/* @ref SPI_NSS */
/*HW*/
#define SPI_NSS_Hard_Slave                        (0x00000000U)
#define SPI_NSS_Hard_Master_SS_output_enable      (0x1U<<2) // CR2. Bit2 SSOE: SS output enable
#define SPI_NSS_Hard_Master_SS_output_disable     ~(0x1U<<2) // CR2. Bit2 SSOE: SS output disable

/*NSS is Driven by SW (Master or Slave)*/
#define SPI_NSS_soft_NSSInternalsoft_Reset        (0x1U<<9)
#define SPI_NSS_soft_NSSInternalsoft_set          ((0x1U<<9) | (0x1U<<8))

/* @ref SPI_BAUDRATEPRESCALER */
#define SPI_BAUDRATEPRESCALER_2                   (0x00000000U)
#define SPI_BAUDRATEPRESCALER_4                   (0b001U << 3)
#define SPI_BAUDRATEPRESCALER_8                   (0b010U << 3)
#define SPI_BAUDRATEPRESCALER_16                  (0b011U << 3)
#define SPI_BAUDRATEPRESCALER_32                  (0b100U << 3)
#define SPI_BAUDRATEPRESCALER_64                  (0b101U << 3)
#define SPI_BAUDRATEPRESCALER_128                 (0b110U << 3)
#define SPI_BAUDRATEPRESCALER_256                 (0b111U << 3)

/* @ref SPI_IRQ_Enable */
#define SPI_IRQ_Enable_NONE                       (uint32_t)(0)
#define SPI_IRQ_Enable_TXEIE                      (uint32_t) (1<<7) //SPI_CR2 Bit7 TXEIE: tx buffer interrupt enable
#define SPI_IRQ_Enable_RXNEIE                     (uint32_t) (1<<6) //SPI_CR2 Bit6 RXNEIE: Rx buffer not empty interrupt enable
#define SPI_IRQ_Enable_ERRIE                      (uint32_t) (1<<5) //SPI_CR2 Bit5 ERRIE: Error interrupt enable


enum PollingMechnism
{
	PollingEnable,
	PollingDisable
};

// * =======================================================================================

/*
 *
 *
 * =======================================================================================
 * 							APIs Supported by "MCAL GPIO DRIVER"
 * =======================================================================================
 */


/* Initialization/de-initialization functions  **********************************/


void MCAL_SPI_Init (SPI_TypeDef *SPIx, SPI_Config* SPI_Config);
void MCAL_SPI_DeInit (SPI_TypeDef *SPIx);


void MCAL_SPI_GPIO_Set_Pins (SPI_TypeDef *SPIx);


void MCAL_SPI_SendData	(SPI_TypeDef *SPIx, uint16_t *pTxBuffer,enum PollingMechnism PollingEn );
void MCAL_SPI_ReceiveData	(SPI_TypeDef *SPIx, uint16_t *pTxBuffer ,enum PollingMechnism PollingEn );
void MCAL_SPI_TX_RX 	(SPI_TypeDef *SPIx, uint16_t *pTxBuffer ,enum PollingMechnism PollingEn );


#endif /* INC_STM32_F103C6_SPI_DRIVER_H_ */
