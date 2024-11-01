/*
 * FIFO.h
 *
 *  Created on: Jun 21, 2024
 *      Author: Aya Ramadan
 */

#ifndef FIFO_H_
#define FIFO_H_

#include <stdio.h>
#include <stdint.h>

/* user configuration */
// select element type (uint8_t , uint16_t ,uint32_t,....)
#define element_type uint8_t

#define width 5
element_type uart_buffer1[width];

typedef struct
{
	unsigned int length;
	unsigned int count;
	element_type *base,*head,*tail;
}FIFO_Buf_t;

typedef enum{
	FIFO_NO_ERROR,
	FIFO_full,
	FIFO_empty,
	FIFO_NULL

}FIFO_status;

/* FIFO APIs */
FIFO_status FIFO_inti (FIFO_Buf_t* fifo, element_type* buf ,uint32_t length);
FIFO_status FIFO_enqueue (FIFO_Buf_t* fifo, element_type item  );
FIFO_status FIFO_dequeue (FIFO_Buf_t* fifo, element_type* item );
FIFO_status FIFO_IS_FULL (FIFO_Buf_t* fifo );
void FIFO_print (FIFO_Buf_t* fifo );

#endif /* FIFO_H_ */
