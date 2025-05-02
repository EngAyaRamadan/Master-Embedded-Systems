/*
 * main.c
 *
 *  Created on: Sep 23, 2024
 *      Author: QUADRO
 */

#define  F_CPU 8000000UL

#include <avr/io.h>
#include<avr/interrupt.h>
#include <util/delay.h>

#include"BIT_MATH.h"

typedef unsigned char     u8;


/*PORTD*/
#define DDRD_REG  *(( volatile u8 *)0x31)
#define PORTD_REG *(( volatile u8 *)0x32)
/*PORTB*/
#define DDRB_REG  *(( volatile u8 *)0x37)
/* EXTI interrupt register */
/* status register >>global interrupt enable>>bit 7 */
#define SREG    *((volatile u8* )0x5B)
#define MCUCR   *((volatile u8* )0x55)
#define MCUCSR  *((volatile u8* )0x54)
#define GIFR    *((volatile u8* )0x5A)
#define GICR    *((volatile u8* )0x5B)



void main(){

	/* output pin */
	SET_BIT(DDRD_REG,5);
	SET_BIT(DDRD_REG,6);
	SET_BIT(DDRD_REG,7);

	/* enable external interrupt pins */
	SET_BIT(GICR,7);
	SET_BIT(GICR,6);
	SET_BIT(GICR,5);

	/* sensing */
	// any logic for INT0
	SET_BIT(MCUCR,0);
	CLR_BIT(MCUCR,1);
	// rising edge for INT1
	SET_BIT(MCUCR,2);
	SET_BIT(MCUCR,3);
	// falling edge for INT2
	CLR_BIT(MCUCSR,6);

	/* enable global interrupt */
	sei();

	while(1)
	{
		CLR_BIT(PORTD_REG,5);
		CLR_BIT(PORTD_REG,6);
		CLR_BIT(PORTD_REG,7);
	}

}

ISR(INT0_vect)
{
	SET_BIT(PORTD_REG,5);
	_delay_ms(1000);
}
ISR(INT1_vect)
{
	SET_BIT(PORTD_REG,6);
	_delay_ms(1000);
}
ISR(INT2_vect)
{
	SET_BIT(PORTD_REG,7);
		_delay_ms(1000);
}

