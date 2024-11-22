/*
 * CA.c
 *
 *  Created on: Oct 29, 2024
 *      Author: Aya Ramadan
 */

#include"state.h"
#include "CA.h"

// variables in block

int CA_speed=0;
int CA_distance=0;
int CA_threshold=50;

/* STATE pointer to function */
void (*CA_state) ();

void ULS_set_distance(int distance)
{
	CA_distance= distance;
	(CA_distance <= CA_threshold) ? (CA_state = STATE(CA_waiting)) : (CA_state= STATE(CA_driving));
	printf("ULS-----------distance=%d------------CA\n",CA_distance);
}

STATE_define(CA_waiting)
{
	/* state name */
	CA_state_id=CA_waiting;
	printf("CA_Waiting state: distance=%d  speed=%d \n",CA_distance,CA_speed);
	/* state action */
	CA_speed=0;
	//DC_Motor (CA_speed)
	DC_motor_speed(CA_speed);

}

STATE_define(CA_driving)
{
	/* state name */
	CA_state_id=CA_driving;
	printf("CA_driving state: distance=%d  speed=%d \n",CA_distance,CA_speed);
	/* state action */
	CA_speed=30;
	//DC_Motor (CA_speed)
	DC_motor_speed(CA_speed);
}






