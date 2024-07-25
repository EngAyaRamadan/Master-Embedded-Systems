
/*
 * app.c
 *
 *  Created on: Feb 9, 2024
 *      Author: Aya Ramadan
 */

#include "uart.h"

unsigned char string_buffer[100]="learn-in-depth:aya";
unsigned char const string_buffer_1[100]="to create rodata";

void main(void)
{
	
	Uart_send_string(string_buffer);
	
}