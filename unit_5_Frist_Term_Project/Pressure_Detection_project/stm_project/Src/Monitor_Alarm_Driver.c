/*
 * Monitor_Alarm_Driver.c
 *
 *  Created on: November 22, 2024
 *      Author: Aya Ramadan
 */


#include"state.h"
#include"driver.h"
#include "Monitor_Alarm_driver.h"


void (*Monitor_Alarm_Driver_state) ();
void Monitor_Alarm_Driver_init()
{
	//printf("Monitor_Alarm_init\n");
}

void Stop_Alarm()
{
	Monitor_Alarm_Driver_state=STATE(Monitor_Alarm_Driver_AlarmOFF);
}
void Start_Alarm()
{
	Monitor_Alarm_Driver_state=STATE(Monitor_Alarm_Driver_AlarmON);
	
}
STATE_DEFINE(Monitor_Alarm_Driver_waiting)
{
	Monitor_Alarm_Driver_state_id=Monitor_Alarm_Driver_waiting;
	
}
STATE_DEFINE(Monitor_Alarm_Driver_AlarmON)
{
	Monitor_Alarm_Driver_state_id=Monitor_Alarm_Driver_AlarmON;
	Set_Alarm_actuator(1);
	Delay(60);
	Set_Alarm_actuator(0);
	Monitor_Alarm_Driver_state=STATE(Monitor_Alarm_Driver_waiting);
}
STATE_DEFINE(Monitor_Alarm_Driver_AlarmOFF)
{
	Monitor_Alarm_Driver_state_id=Monitor_Alarm_Driver_AlarmOFF;
	Set_Alarm_actuator(0);
	Monitor_Alarm_Driver_state=STATE(Monitor_Alarm_Driver_waiting);
	
}
