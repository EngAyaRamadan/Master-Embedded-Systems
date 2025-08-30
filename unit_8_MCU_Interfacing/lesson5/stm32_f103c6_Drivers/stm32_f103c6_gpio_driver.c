/*
 * stm32_f103c6_gpio_driver.c
 *
 *  Created on: Apr 29, 2025
 *      Author: Aya Ramadan
 */


#include"stm32_f103c6_gpio_driver.h"

uint8_t Get_CRLH_Position (uint16_t PinNumber)
{
	switch(PinNumber)
	{
	case GPIO_PIN_0:
	case GPIO_PIN_8:
		return 0; break;
	case GPIO_PIN_1:
	case GPIO_PIN_9:
		return 4; break;
	case GPIO_PIN_2:
	case GPIO_PIN_10:
		return 8; break;
	case GPIO_PIN_3:
	case GPIO_PIN_11:
		return 12; break;
	case GPIO_PIN_4:
	case GPIO_PIN_12:
		return 16; break;
	case GPIO_PIN_5:
	case GPIO_PIN_13:
		return 20; break;
	case GPIO_PIN_6:
	case GPIO_PIN_14:
		return 24; break;
	case GPIO_PIN_7:
	case GPIO_PIN_15:
		return 28; break;
	}
	return 0;
}

/**================================================================
 * @Fn               - MCAL_GPIO_Init
 * @brief            - Initializes the GPIOx Piny according to the specified parameters in the PinConfig
 * @param  [in]      - GPIOx where x can be (A..E depending on device used) to select the GPIO peripheral
 * @param  [in]    - PinConfig pointer to a GPIO_PinConfig_t structure that contains the configration
 *                     information for the specified GPIO PIN
 * @retval           - none
 * Note              - stm32f103c6 MCU has GPIO A,B,C,D Modules
 *                     but LQFP48 package has only GPIO A,B,part of C,D exported as external PINS from the MCU
 */

void MCAL_GPIO_Init(GPIO_Typedef* GPIOx,GPIO_PinConfig_t* pinConfig)
{

	// Port configuration register low (GPIOx_CRL) configure pin from  0 >> 7
	// Port configuration register high (GPIOx_CRH) configure pin from  8 >> 15
	volatile uint32_t* configregister = NULL;
	uint8_t PIN_Config = 0;
	configregister =(pinConfig->GPIO_PinNumber < GPIO_PIN_8)? &GPIOx->CRL : &GPIOx->CRH ;
	// clear CNF0[1:0] MODE0[1:0]
	(*configregister) &=~( 0xf<< Get_CRLH_Position(pinConfig->GPIO_PinNumber));

	// if pin is output
	if(pinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_AF_OD || pinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_AF_PP || pinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_OD || pinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_PP )
	{
		PIN_Config =( (((pinConfig->GPIO_MODE - 4)<< 2) | (pinConfig->GPIO_Output_Speed))& 0x0f );
	}
	// if pin is input
	else
	{
		if(pinConfig->GPIO_MODE == GPIO_MODE_ANALOG || pinConfig->GPIO_MODE == GPIO_MODE_INPUT_FLO  )
		{
			PIN_Config =( (((pinConfig->GPIO_MODE )<< 2) | 0x0 )& 0x0f );
		}
		else if(pinConfig->GPIO_MODE == GPIO_MODE_AF_INPUT) // consider it as input floating
		{
			PIN_Config =( (((GPIO_MODE_INPUT_FLO )<< 2) | 0x0 )& 0x0f );
		}
		else
		{
			PIN_Config =( (((GPIO_MODE_INPUT_PU )<< 2) | 0x0 )& 0x0f );
			if(pinConfig->GPIO_MODE == GPIO_MODE_INPUT_PU)
			{
				// Table 20. port bit configuration table PxODR 1
				GPIOx->ODR |= pinConfig->GPIO_PinNumber ;
			}
			else
			{
				// Table 20. port bit configuration table PxODR 0
				GPIOx->ODR &=~( pinConfig->GPIO_PinNumber) ;
			}
		}
	}
	// write on the CRL OR CRH
	(*configregister) |= ((PIN_Config)<< Get_CRLH_Position(pinConfig->GPIO_PinNumber));
}
/**================================================================
 * @Fn               - MCAL_GPIO_DeInit
 * @brief            - reset all the GPIO Registers
 * @param  [in]      - GPIOx where x can be (A..E depending on device used) to select the GPIO peripheral
 * @retval           - none
 * Note              - none
 */
void MCAL_GPIO_DeInit(GPIO_Typedef* GPIOx)
{
	// manual
	GPIOx->BRR  = 0x00000000;
	GPIOx->BSRR = 0x00000000;
	GPIOx->CRH  = 0x44444444;
	GPIOx->CRL  = 0x44444444;
	//  GPIOx->IDR  (read only)
	GPIOx->LCKR = 0x00000000;
	GPIOx->ODR  = 0x00000000;

	/* or you can use the reset controller */
	// APB2 peripheral reset register (RCC_APB2RSTR)
	// set and cleared by software
	if(GPIOx == GPIOA)
	{
		RCC->APB2RSTR |= (1<<2);
		RCC->APB2RSTR &= ~ (1<<2);
	}
	else if(GPIOx == GPIOB)
	{
		RCC->APB2RSTR |= (1<<3);
		RCC->APB2RSTR &= ~ (1<<3);
	}
	else if(GPIOx == GPIOC)
	{
		RCC->APB2RSTR |= (1<<4);
		RCC->APB2RSTR &= ~ (1<<4);
	}
	else if(GPIOx == GPIOD)
	{
		RCC->APB2RSTR |= (1<<5);
		RCC->APB2RSTR &= ~ (1<<5);

	}
	else if(GPIOx == GPIOE)
	{
		RCC->APB2RSTR |= (1<<6);
		RCC->APB2RSTR &= ~ (1<<6);
	}
}
/**================================================================
 * @Fn               - MCAL_GPIO_ReadPin
 * @brief            - Read specific PIN
 * @param  [in]      - GPIOx where x can be (A..E depending on device used) to select the GPIO peripheral
 * @param  [in]      - PinNumber: set pin number according to  @ref GPIO_PINS_define
 * @retval           - The input pin value (two values based on @ref GPIO_PIN_state )
 * Note              - none
 */
uint8_t MCAL_GPIO_ReadPin(GPIO_Typedef* GPIOx, uint16_t PinNumber)
{
	uint8_t bitstatus;
	if( ((GPIOx->IDR) & PinNumber) !=  (uint8_t) GPIO_PIN_RESET )
	{
		bitstatus =GPIO_PIN_SET ;
	}
	else
	{
		bitstatus =GPIO_PIN_RESET ;
	}

	return bitstatus;
}
/**================================================================
 * @Fn               - MCAL_GPIO_ReadPort
 * @brief            - Read specific PORT
 * @param  [in]      - GPIOx where x can be (A..E depending on device used) to select the GPIO peripheral
 * @retval           - The input port value
 * Note              - none
 */
uint16_t MCAL_GPIO_ReadPort(GPIO_Typedef* GPIOx )
{
	uint16_t portvalue ;
	portvalue= (uint16_t)(GPIOx->IDR);

	return portvalue;
}
/**================================================================
 * @Fn               - MCAL_GPIO_WritePort
 * @brief            - Write on specific output Pin
 * @param  [in]      - GPIOx: where x can be (A..E depending on device used) to select the GPIO peripheral
 * @param  [in]      - PinNumber: set pin number according to  @ref GPIO_PINS_define
 * @param  [in]      - value : set pin value according to  @ref GPIO_PINS_define
 * @retval           - none
 * Note              - none
 */
void MCAL_GPIO_WritePin ( GPIO_Typedef* GPIOx, uint16_t PinNumber, uint8_t value)
{
	if( value != GPIO_PIN_RESET )
	{
		// GPIOx->ODR |= PinNumber;
		// or
		GPIOx->BSRR =PinNumber;
	}
	else
	{
		GPIOx->BRR = PinNumber ;
	}

}
/**================================================================
 * @Fn               - MCAL_GPIO_WritePort
 * @brief            - Write on specific output PORT
 * @param  [in]      - GPIOx where x can be (A..E depending on device used) to select the GPIO peripheral
 * @param  [in]      - value : set port value
 * @retval           - none
 * Note              - none
 */
void MCAL_GPIO_WritePort( GPIO_Typedef* GPIOx, uint8_t value)
{
	GPIOx->ODR =(uint32_t)value;
}
/**================================================================
 * @Fn               - MCAL_GPIO_TogglePin
 * @brief            - Toggle  specific output PIN
 * @param  [in]      - GPIOx where x can be (A..E depending on device used) to select the GPIO peripheral
 * @param  [in]      - PinNumber: set pin number according to  @ref GPIO_PINS_define
 * @retval           - none
 * Note              - none
 */
void MCAL_GPIO_TogglePin ( GPIO_Typedef* GPIOx, uint16_t PinNumber )
{
	GPIOx->ODR ^= (PinNumber);
}
/**================================================================
 * @Fn               - MCAL_GPIO_LockPin
 * @brief            - The locking mechanism allows the IO configuration to be frozen
 * @param  [in]      - GPIOx where x can be (A..E depending on device used) to select the GPIO peripheral
 * @param  [in]      - PinNumber: set pin number according to  @ref GPIO_PINS_define
 * @retval           - ok if pin config is locked or error if pin not locked according to  @ref GPIO_RETURN_LOCK_define
 * Note              - none
 */
uint8_t MCAL_GPIO_LockPin ( GPIO_Typedef* GPIOx, uint16_t PinNumber )
{
	volatile uint32_t temp = 1<<16;
	temp |= PinNumber ;
	// write sequance
	// write 1
	GPIOx->LCKR = temp;
	// write 0
	GPIOx->LCKR = PinNumber ;
	// write 1
	GPIOx->LCKR = temp;
	// read 0
	temp = GPIOx->LCKR;
	// read 1
	if(((uint32_t) GPIOx->LCKR & 1<<16)  )
	{
		return GPIO_RETURN_LOCK_Enable ;
	}
	else
	{
		return GPIO_RETURN_LOCK_Error ;
	}
}
