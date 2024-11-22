/*
 * ULS.c
 *
 *  Created on: Oct 29, 2024
 *      Author: Aya Ramadan
 */

#include"state.h"
#include "ULS.h"

// variables in block

int ULS_distance=0;
/* STATE pointer to function */
void (*ULS_state) ();

void ULS_init()
{
	//ULS driver init
	printf("ULS_init\n");
}
STATE_define(ULS_BUSY)
{
	/* state name */
	ULS_state_id=ULS_BUSY;
	/* state action */
	ULS_distance=ULS_Get_distance_random (45,55,1);
	//DC_Motor (ULS_speed)

	/* Event check */
	printf("ULS_BUSY state: distance=%d \n",ULS_distance);
	ULS_set_distance(ULS_distance);
	ULS_state=STATE(ULS_BUSY);
}


int ULS_Get_distance_random ( int l,int r,int count)
{
	/* generate rondom number in range i and r */
	int i;
	for(i=0;i<count;i++)
	{
		int rand_num=(rand()%(r-l+1))+l;
		return rand_num;
	}

}
