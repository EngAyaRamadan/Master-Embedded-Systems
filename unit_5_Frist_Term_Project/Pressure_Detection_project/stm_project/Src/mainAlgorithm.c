/*
 * mainAlgorithm.c
 *
 *  Created on: November 22, 2024
 *      Author: Aya Ramadan
 */
 
 
 
#include"state.h"
#include "mainAlgorithm.h"

 // variables in block
int Pressure_val=0;
int Pressure_threshold=20;

void (*mainAlgorithm_state) ();

void Pressure_sensor_set_val(int value)
{
	Pressure_val= value;
	//printf("Pressure_sensor-----------value=%d------------Monitor_Alarm\n",Pressure_val);
	mainAlgorithm_state=STATE(mainAlgorithm_High_pressure_Detect);

}
STATE_DEFINE(mainAlgorithm_High_pressure_Detect)
 {
	 mainAlgorithm_state_id= mainAlgorithm_High_pressure_Detect;
	 if(Pressure_val >  Pressure_threshold)
		 High_Pressure_Detected();

 }
