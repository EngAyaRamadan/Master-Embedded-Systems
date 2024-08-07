/*
 * uart.c
 *
 *  Created on: Feb 9, 2024
 *      Author: Aya Ramadan
 */

#include "uart.h"

#define UART0DR *((volatile unsigned int*)((unsigned int*)0x101f1000))

void Uart_send_string(unsigned char* p_tx_string) /* parammter is an transmmited string */
{
	while(*p_tx_string !='\0')
	{
		UART0DR=(unsigned int*)(*p_tx_string);
		p_tx_string++;
	}
	
}
