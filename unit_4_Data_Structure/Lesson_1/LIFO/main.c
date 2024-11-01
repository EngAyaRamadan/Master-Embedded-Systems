/*
 * main.c
 *
 *  Created on: Jun 21, 2024
 *      Author:  Aya Ramadan
 */


#include "LIFO.h"


void main() {
	int i,temp=0;
	LIFO_Buf_t uart_lifo,I2C_lifo;
	/* static allocation--> data memory*/
	LIFO_create(&uart_lifo,buffer1,5);
	/* dynamic allocation--> heap memory */
	unsigned int * buffer2=(unsigned int* )malloc (5 * sizeof(unsigned int ));
	LIFO_create(&I2C_lifo,buffer2,5);

	for(i=0; i<5; i++)
	{
		if (LIFO_PUSH_Item(&uart_lifo,i)==LIFO_NO_ERROR)
			printf("uart lifo push  %d\n",i);
	}
	printf("\n");
	for(i=0; i<5; i++)
	{
		if(LIFO_POP_Item(&uart_lifo,&temp) == LIFO_NO_ERROR)
			printf("uart lifo pop  %d\n",temp);
	}


}
