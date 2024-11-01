/*
 * FIFO.c
 *
 *  Created on: Jun 21, 2024
 *      Author: Aya Ramadan
 */

#include "FIFO.h"

FIFO_status FIFO_inti (FIFO_Buf_t* fifo, element_type* buf ,uint32_t length)
{
	if(buf== NULL)
		return FIFO_NULL;
	fifo->base=buf;
	fifo->head=buf;
	fifo->tail=buf;
	fifo->count=0;
	fifo->length=length;

	return FIFO_NO_ERROR;
}

FIFO_status FIFO_IS_FULL (FIFO_Buf_t* fifo )
{
	if(!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_NULL;
	if(fifo->count >= fifo->length)
		return FIFO_full;

	return FIFO_NO_ERROR;

}

FIFO_status FIFO_enqueue (FIFO_Buf_t* fifo, element_type item  )
{
	if(!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_NULL;
	if(FIFO_IS_FULL (fifo )== FIFO_full)
		return FIFO_full;
	*(fifo->head)=item;
	fifo->count++;
	// circular queue
	if(fifo->head== (fifo->base)+ (fifo->length * sizeof(element_type)))
		fifo->head=fifo->base;
	else
		fifo->head++;

	return FIFO_NO_ERROR;
}

FIFO_status FIFO_dequeue (FIFO_Buf_t* fifo, element_type* item )
{
	if(!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_NULL;
	if(fifo->count == 0)
		return FIFO_empty;
	*item=*fifo->tail;
	fifo->count--;
	// circular queue
	if(fifo->tail== (fifo->base)+ (fifo->length * sizeof(element_type)))
		fifo->tail=fifo->base;
	else
		fifo->tail++;

	return FIFO_NO_ERROR;
}

void FIFO_print (FIFO_Buf_t* fifo )
{
	element_type *temp;
	int i;
	if(fifo->count == 0)
		printf("fifo is empty\n");
	else
	{
		temp=fifo->tail;
		printf("->>>>> fifo printf>>>>>>>\n");
		for(i=0;i<fifo->count;i++)
		{
			printf("%x\n",*temp);
			temp++;
		}
	}
}
