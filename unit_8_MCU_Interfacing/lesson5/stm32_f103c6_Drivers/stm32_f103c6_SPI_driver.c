/////*
//// * stm32_f103c6_gpio_driver.c
//// *
//// *  Created on: Apr 29, 2025
//// *      Author: Aya Ramadan
//// */
////

#include "stm32_F103C6_SPI_driver.h"
/*
 * =======================================================================================
 * 							Generic Variables
 * =======================================================================================
 */

SPI_Config* Global_SPI_ConFig[2] = { NULL,NULL };
SPI_Config Global_SPI_ConFig1;
SPI_Config Global_SPI_ConFig2;

/*
 * =======================================================================================
 * 							Generic Macros
 * =======================================================================================
 */
#define SPI1_INDEX    0
#define SPI2_INDEX    1

#define SPI_SR_TXE       ((uint8_t) 0x02)  /* transmit buffer Empty*/
#define SPI_SR_RXNE      ((uint8_t) 0x01)  /* receive buffer not Empty*/


/*
 * =======================================================================================
 * 							Generic Functions
 * =======================================================================================
 */

/**================================================================
 * @Fn				- MCAL_SPI_Init
 * @brief 			- Initializes SPI according to the specified parameters
 * @param [in] 		- SPIx: where x can be (1..3 depending on device used)
 * @param [in] 		- SPI_Config: All SPI Configuration EXTI_PinConfig_t
 * @retval 			- none
 * Note				- Support for Now SPI full Duplex Master/Slave only & NSS HW only for slave
 *                  - in case of master you have to configure pin and drive it
 */
void MCAL_SPI_Init (SPI_TypeDef *SPIx, SPI_Config* SPI_Config)
{
	// Safety for register
	uint16_t tmpreg_CR1 = 0;
	uint16_t tmpreg_CR2 = 0;

	if(SPIx == SPI1)
	{
		Global_SPI_ConFig1 = *SPI_Config;
		Global_SPI_ConFig[SPI1_INDEX] = &Global_SPI_ConFig1  ;
		RCC_SPI1_CLK_EN();
	}
	else if(SPIx == SPI2)
	{
		Global_SPI_ConFig2 = *SPI_Config;
		Global_SPI_ConFig[SPI2_INDEX] = &Global_SPI_ConFig2 ;
		RCC_SPI2_CLK_EN();
	}

	// Enable SPI CR1:Bit 6 SPE : SPI enable
	tmpreg_CR1 =(0x1U<<6);
	// master or slave
	tmpreg_CR1 |= SPI_Config->Device_Mode ;
	// SPI_Communication_Mode
	tmpreg_CR1 |= SPI_Config->Communication_Mode ;
	// SPI_Frame_Format
	tmpreg_CR1 |= SPI_Config->Frame_Format ;
	// SPI Data Size
	tmpreg_CR1 |= SPI_Config->DataSize ;
	// SPI_Clock_Polarity
	tmpreg_CR1 |= SPI_Config->CLKPolarity ;
	// SPI_Colock_Phase
	tmpreg_CR1 |= SPI_Config->CLKPhase ;
	// ==============  NSS ======================

	if(SPI_Config->NSS == SPI_NSS_Hard_Master_SS_output_enable)
	{
		tmpreg_CR2 |= SPI_Config->NSS ;
	}
	else if (SPI_Config->NSS == SPI_NSS_Hard_Master_SS_output_disable)
	{
		tmpreg_CR2 &= SPI_Config->NSS ;
	}
	else
	{
		tmpreg_CR1 |= SPI_Config->NSS;
	}
	//================================================
	// SPI_BAUDRATEPRESCALLER
	tmpreg_CR1 |= SPI_Config->SPI_BAUDRATEPRESCALER ;

	// SPI interrupt
	if(SPI_Config->IRQ_Enable != SPI_IRQ_Enable_NONE)
	{
		// SPI_IRQ_Enable
		tmpreg_CR2 |= SPI_Config->IRQ_Enable;
		if( SPIx == SPI1 )
		{
			NVIC_IRQ35_SPI1_Enable;
		}
		else if ( SPIx == SPI2 )
		{
			NVIC_IRQ36_SPI2_Enable ;
		}

	}

	SPIx->SPI_CR1 =tmpreg_CR1 ;
	SPIx->SPI_CR2 =tmpreg_CR2 ;

}
/**================================================================
 * @Fn				- MCAL_SPI_DEInit
 * @brief 			- DEInitializes SPI according to the specified parameters
 * @param [in] 		- SPIx: where x can be (1..3 depending on device used)
 * @retval 			- none
 * Note				- Reset the Model by RCC
 */
void MCAL_SPI_DeInit (SPI_TypeDef *SPIx)
{
	if ( SPIx == SPI1 )
	{
		NVIC_IRQ35_SPI1_Disable ;
		RCC_SPI1_CLK_Reset();
	}

	else if ( SPIx == SPI2 )
	{
		NVIC_IRQ36_SPI2_Disable ;
		RCC_SPI2_CLK_Reset();
	}
}

/*********************************************************************
 * @fn      		  - MCAL_SPI_SendData
 * @brief             - Send Buffer on SPI
 * @param [in] 		  - SPIx: where x can be (1..3 depending on device used)
 * @param[in]         - pTxBuffer Buffer
 * @param[in]         - PollingEn   Enable pooling or dsable it
 * @return            - none
 * @Note              -
 */

void MCAL_SPI_SendData	(SPI_TypeDef *SPIx, uint16_t *pTxBuffer,enum PollingMechnism PollingEn )
{
	// todo receive only
	if (PollingEn == PollingEnable)
		while(!((SPIx)->SPI_SR & SPI_SR_TXE)  );

	SPIx->SPI_DR = *pTxBuffer;
}

void MCAL_SPI_ReceiveData	(SPI_TypeDef *SPIx, uint16_t *pRxBuffer ,enum PollingMechnism PollingEn )
{
	if (PollingEn == PollingEnable)
		while( ! ((SPIx)->SPI_SR  & SPI_SR_RXNE ));
	*pRxBuffer = SPIx->SPI_DR;
}

void MCAL_SPI_TX_RX 	(SPI_TypeDef *SPIx, uint16_t *pTxBuffer ,enum PollingMechnism PollingEn )
{
	if (PollingEn == PollingEnable)
		while(!((SPIx)->SPI_SR & SPI_SR_TXE)  );
	SPIx->SPI_DR = *pTxBuffer;

	if (PollingEn == PollingEnable)
		while(!((SPIx)->SPI_SR & SPI_SR_RXNE)  );
	*pTxBuffer = SPIx->SPI_DR;
}

/**================================================================
 * @Fn				-MCAL_UART_GPIO_Set_Pins
 * @brief 			- intialize GPIO Pins
 * @param [in] 		- USARTx: where x can be (1..3 depending on device used)
 * @retval 			-none
 * Note				-Should enable the corresponding ALT  & GPIO  in RCC clock Also called after MCAL_UART_Init()
 */
void MCAL_SPI_GPIO_Set_Pins (SPI_TypeDef *SPIx)
{
	GPIO_PinConfig_t pinCfg;
	if(SPIx == SPI1 )
	{
		//PA4 : SPI1_NSS
		//PA5 : SPI1_SCK
		//PA6 : SPI1_MISO
		//PA7 : SPI1_MOSI
		if(Global_SPI_ConFig[SPI1_INDEX]->Device_Mode == SPI_Device_Mode_MASTER )
		{
			//PA4 : SPI1_NSS
			switch(Global_SPI_ConFig[SPI1_INDEX]->NSS )
			{
			case SPI_NSS_Hard_Master_SS_output_disable:
				// Hardware master / slave Input floating
				pinCfg.GPIO_PinNumber = GPIO_PIN_4;
				pinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
				MCAL_GPIO_Init(GPIOA, &pinCfg);
				break;

			case SPI_NSS_Hard_Master_SS_output_enable:
				// Hardware master / NSS output enabled Alternate function push-pull
				pinCfg.GPIO_PinNumber = GPIO_PIN_4;
				pinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
				pinCfg.GPIO_Output_Speed=GPIO_SPEED_10M;
				MCAL_GPIO_Init(GPIOA, &pinCfg);
				break;
			}

			//PA5 : SPI1_SCK
			// Master Alternate function push-pull
			pinCfg.GPIO_PinNumber = GPIO_PIN_5;
			pinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			pinCfg.GPIO_Output_Speed=GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOA, &pinCfg);
			//PA6 : SPI1_MISO (supported only Full duplex)
			// Full duplex / master Input floating
			pinCfg.GPIO_PinNumber = GPIO_PIN_6;
			pinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOA, &pinCfg);
			// todo to support half duplex and simplex

			//PA7 : SPI1_MOSI (supported only Full duplex)
			// Full duplex /  Master Alternate function push-pull
			pinCfg.GPIO_PinNumber = GPIO_PIN_7;
			pinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			pinCfg.GPIO_Output_Speed=GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOA, &pinCfg);
		}
		else // slave
		{
			//PA4 : SPI1_NSS
			if(Global_SPI_ConFig[SPI1_INDEX]->NSS == SPI_NSS_Hard_Slave)
			{
				// Hardware master / slave Input floating
				pinCfg.GPIO_PinNumber = GPIO_PIN_4;
				pinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
				MCAL_GPIO_Init(GPIOA, &pinCfg);
			}
			//PA5 : SPI1_SCK
			// Slave Input floating
			pinCfg.GPIO_PinNumber = GPIO_PIN_5;
			pinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOA, &pinCfg);

			//PA6 : SPI1_MISO (supported only Full duplex)
			// Full duplex / slave (point to point) Alternate function push-pull
			// todo   Full duplex / slave (multi slave) Alternate function push-pull
			pinCfg.GPIO_PinNumber = GPIO_PIN_6;
			pinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			pinCfg.GPIO_Output_Speed=GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOA, &pinCfg);

			//PA7 : SPI1_MOSI
			// Full duplex /  slave Input floating
			pinCfg.GPIO_PinNumber = GPIO_PIN_7;
			pinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOA, &pinCfg);

		}
	}
	else if(SPIx == SPI2 )
	{
		//PB12 : SPI2_NSS
		//PB13 : SPI2_SCK
		//PB14 : SPI2_MISO
		//PB15 : SPI2_MOSI

		if(Global_SPI_ConFig[SPI2_INDEX]->Device_Mode == SPI_Device_Mode_MASTER )
		{
			//PB12 : SPI2_NSS
			switch(Global_SPI_ConFig[SPI2_INDEX]->NSS )
			{
			case SPI_NSS_Hard_Master_SS_output_disable:
				// Hardware master / slave Input floating
				pinCfg.GPIO_PinNumber = GPIO_PIN_12;
				pinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
				MCAL_GPIO_Init(GPIOB, &pinCfg);
				break;

			case SPI_NSS_Hard_Master_SS_output_enable:
				// Hardware master / NSS output enabled Alternate function push-pull
				pinCfg.GPIO_PinNumber = GPIO_PIN_12;
				pinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
				pinCfg.GPIO_Output_Speed=GPIO_SPEED_10M;
				MCAL_GPIO_Init(GPIOB, &pinCfg);
				break;
			}

			//PB13 : SPI2_SCK
			// Master Alternate function push-pull
			pinCfg.GPIO_PinNumber = GPIO_PIN_13;
			pinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			pinCfg.GPIO_Output_Speed=GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOB, &pinCfg);

			//PB14 : SPI2_MISO (supported only Full duplex)
			// Full duplex / master Input floating
			pinCfg.GPIO_PinNumber = GPIO_PIN_14;
			pinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOB, &pinCfg);
			// todo to support half duplex and simplex

			//PB15 : SPI2_MOSI (supported only Full duplex)
			// Full duplex /  Master Alternate function push-pull
			pinCfg.GPIO_PinNumber = GPIO_PIN_15;
			pinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			pinCfg.GPIO_Output_Speed=GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOB, &pinCfg);
		}
		else // slave
		{
			//PB12 : SPI1_NSS
			if(Global_SPI_ConFig[SPI2_INDEX]->NSS == SPI_NSS_Hard_Slave)
			{
				// Hardware master / slave Input floating
				pinCfg.GPIO_PinNumber = GPIO_PIN_12;
				pinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
				MCAL_GPIO_Init(GPIOB, &pinCfg);
			}
			//PB13 : SPI2_SCK
			// Slave Input floating
			pinCfg.GPIO_PinNumber = GPIO_PIN_13;
			pinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOB, &pinCfg);

			//PB14 : SPI1_MISO (supported only Full duplex)
			// Full duplex / slave (point to point) Alternate function push-pull
			// todo   Full duplex / slave (multi slave) Alternate function push-pull
			pinCfg.GPIO_PinNumber = GPIO_PIN_14;
			pinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			pinCfg.GPIO_Output_Speed=GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOB, &pinCfg);

			//PB15 : SPI1_MOSI
			// Full duplex /  slave Input floating
			pinCfg.GPIO_PinNumber = GPIO_PIN_15;
			pinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOB, &pinCfg);

		}
	}
}

//ISR


void SPI1_IRQHandler (void)
{
	struct S_IRQ_SRC irq_src;
	irq_src.TXE =  ((SPI1->SPI_SR & (1<<1)) >> 1);
	irq_src.RXNE = ((SPI1->SPI_SR & (1<<0)) >> 0);
	irq_src.ERRI = ((SPI1->SPI_SR & (1<<4)) >> 4);

	Global_SPI_ConFig[SPI1_INDEX]->P_IRQ_CallBack(irq_src) ;
}
void SPI2_IRQHandler (void)
{
	struct S_IRQ_SRC irq_src;
	irq_src.TXE =  ((SPI2->SPI_SR & (1<<1)) >> 1);
	irq_src.RXNE = ((SPI2->SPI_SR & (1<<0)) >> 0);
	irq_src.ERRI = ((SPI2->SPI_SR & (1<<4)) >> 4);

	Global_SPI_ConFig[SPI2_INDEX]->P_IRQ_CallBack (irq_src) ;
}

