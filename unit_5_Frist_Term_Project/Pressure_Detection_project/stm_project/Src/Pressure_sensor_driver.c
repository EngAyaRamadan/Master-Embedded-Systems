/*
 * Pressure_sensor_driver.c
 *
 *  Created on: November 22, 2024
 *      Author: Aya Ramadan
 */
 
 #include"state.h"
#include"driver.h"
#include "Pressure_sensor_driver.h"

// variables in block
int Pressure_sensor_Pval=0;
int Pressure_time=0;

/* STATE pointer to function */
void (*Pressure_sensor_state)  ();

void Pressure_sensor_init()
{
	//printf("Pressure_sensor_init\n");
}
STATE_DEFINE(Pressure_sensor_readflag)
{
		/* state name */
	Pressure_sensor_state_id=Pressure_sensor_readflag;
	/* state action */
	Pressure_sensor_Pval=getPressureVal();
		/* Event check */
	//printf("Pressure_sensor_readflag state: value=%d \n",Pressure_sensor_Pval);
	Pressure_sensor_set_val(Pressure_sensor_Pval);
	Pressure_time=100;
	Pressure_sensor_state=STATE(Pressure_sensor_waiting);
}
STATE_DEFINE(Pressure_sensor_waiting)
{
		/* state name */
	//Pressure_sensor_state_id=Pressure_sensor_waiting;
	Delay(Pressure_time);
	Pressure_time=0;
	Pressure_sensor_state=STATE(Pressure_sensor_readflag);
}



