/*
 * Monitor_Alarm.c
 *
 *  Created on: November 22, 2024
 *      Author: Aya Ramadan
 */
 

#include"state.h"
#include"driver.h"
#include "Monitor_Alarm.h"

// // variables in block
int Alarm_timer=0;
int Alarm_Period=60;
 
 void (*Monitor_Alarm_state) ();
 
 void Monitor_Alarm_init()
 {
	// printf("Monitor_Alarm_init\n");
 }
 void High_Pressure_Detected()
 {
	 Monitor_Alarm_state= STATE(Monitor_Alarm_AlarmON);
 }
 
 STATE_DEFINE(Monitor_Alarm_AlarmOFF)
{
   Monitor_Alarm_state_id=Monitor_Alarm_AlarmOFF;
	Stop_Alarm();
}
 STATE_DEFINE(Monitor_Alarm_AlarmON)
{
  Monitor_Alarm_state_id=Monitor_Alarm_AlarmON;
  Start_Alarm();
  Alarm_timer=Alarm_Period;
  Monitor_Alarm_state= STATE(Monitor_Alarm_waiting);
  Monitor_Alarm_state();
}
 STATE_DEFINE(Monitor_Alarm_waiting)
{
    Monitor_Alarm_state_id=Monitor_Alarm_waiting;
    Delay(Alarm_timer);
    Alarm_timer=0;
	Monitor_Alarm_state= STATE(Monitor_Alarm_AlarmOFF);

}

