/*
 * LIFO.c
 *
 *  Created on: Jun 21, 2024
 *      Author: Aya Ramadan
 */


#include "LIFO.h"

LIFO_status LIFO_create(LIFO_Buf_t * Lifo_buf ,unsigned int *buf_name,unsigned int length)
{
	if(buf_name == NULL)
		return LIFO_NULL;
	Lifo_buf->base = buf_name;
	Lifo_buf->head = buf_name;
	Lifo_buf->length =length;
	Lifo_buf->count=0;
	return LIFO_NO_ERROR;
}

LIFO_status LIFO_PUSH_Item(LIFO_Buf_t * Lifo_buf ,unsigned int element)
{
	/* check LIFO is valid(exist) or not */
	if(!Lifo_buf-> base || !Lifo_buf->head)
		return LIFO_NULL;

	/* check LIFO is full or not */
	//if(Lifo_buf->head >= ((Lifo_buf->base) + (Lifo_buf->length*4)))
	if(Lifo_buf->count == Lifo_buf->length)
		return LIFO_full;
	/* add value */
	*(Lifo_buf->head)= element;
	++ Lifo_buf->head;
	++ Lifo_buf->count;

	return LIFO_NO_ERROR;

}
LIFO_status LIFO_POP_Item(LIFO_Buf_t * Lifo_buf ,unsigned int *element)
{
	/* check LIFO is valid(exist) or not */
	if(!Lifo_buf-> base || !Lifo_buf->head)
		return LIFO_NULL;
	/* check LIFO is empty or not */
	/* if( Lifo_buf->head >= Lifo_buf->base ) */
	if(Lifo_buf->count == 0)
		return LIFO_empty;
	/* add value */
	-- Lifo_buf->head;
	*element = *(Lifo_buf->head);
	-- Lifo_buf->count;

	return LIFO_NO_ERROR;
}
