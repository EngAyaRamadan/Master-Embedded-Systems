/*
 * main.c
 *
 *  Created on: Jun 21, 2024
 *      Author: Aya Ramadan
 */


#include "FIFO.h"

void main()
{
	FIFO_Buf_t FIFO_uart;
	element_type i=0,temp=0;
	if(FIFO_inti(&FIFO_uart,uart_buffer1,5)== FIFO_NO_ERROR)
		printf("FIFO INIT ........ DONE\n");

	for(i=0;i<7;i++)
	{
		printf("FIFO Enqueue (%x)\n",i);
		if(FIFO_enqueue(&FIFO_uart,i) == FIFO_NO_ERROR)
			printf("\t FiFo Enqueue......DONE\n");
		else
			printf("\t FiFo Enqueue......FIALED\n");
	}

	FIFO_print(&FIFO_uart);
	if(FIFO_dequeue(&FIFO_uart,&temp)==FIFO_NO_ERROR)
		printf("\t FiFo Dequeue %x ......DONE\n",temp);
	if(FIFO_dequeue(&FIFO_uart,&temp)==FIFO_NO_ERROR)
		printf("\t FiFo Dequeue %x ......DONE\n",temp);
	FIFO_print(&FIFO_uart);
}
