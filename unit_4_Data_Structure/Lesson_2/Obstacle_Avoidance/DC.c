/*
 * DC.c
 *
 *  Created on: Oct 29, 2024
 *      Author: Aya Ramadan
 */

#include"state.h"
#include "DC.h"

// variables in block

int DC_speed=0;

/* STATE pointer to function */
void (*DC_state) ();

void DC_init()
{
   // init PWM
	printf("DC_init\n");
}

void DC_motor_speed(int speed)
{
	DC_speed= speed;
	DC_state = STATE(DC_BUSY);
	printf("CA-----------speed=%d------------DC \n",DC_speed);
}
STATE_define(DC_IDEAL)
{
	/* state name */
	DC_state_id=DC_IDEAL;
	/* state action */
	//Call PWM to make speed = DC_speed

	printf("DC_IDEAL state: speed=%d \n",DC_speed);
}

STATE_define(DC_BUSY)
{
	/* state name */
	DC_state_id=DC_BUSY;
	/* state action */
	DC_speed=30;
	//DC_Motor (DC_speed)
	//Call PWM to make speed = DC_speed

	DC_state = STATE(DC_IDEAL);
	printf("DC_BUSY state: speed=%d \n",DC_speed);

}


