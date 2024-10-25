/*
 *  LIFO.h
 *
 *  Created on: Jun 21, 2024
 *      Author:  Aya Ramadan
 */

#ifndef LIFO_H_
#define LIFO_H_

#include <stdio.h>
#include <stdlib.h>

#define size 5
unsigned int buffer1 [size];

// type definition
typedef struct {
	unsigned int length;
	unsigned int count;
	unsigned int *base;
	unsigned int *head;
}LIFO_Buf_t;

typedef enum{
	LIFO_NO_ERROR,
	LIFO_full,
	LIFO_empty,
	LIFO_NULL
}LIFO_status;

// function (APIs)

LIFO_status LIFO_create(LIFO_Buf_t * Lifo_buf ,unsigned int * buf_name,unsigned int length);
LIFO_status LIFO_PUSH_Item(LIFO_Buf_t * Lifo_buf ,unsigned int element);
LIFO_status LIFO_POP_Item(LIFO_Buf_t * Lifo_buf ,unsigned int *element);








#endif /* LIFO_H_ */
