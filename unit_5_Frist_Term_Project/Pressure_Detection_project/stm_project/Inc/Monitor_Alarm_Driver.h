/*
 * Monitor_Alarm_Driver.h
 *
 *  Created on: November 22, 2024
 *      Author: Aya Ramadan
 */

#ifndef MONITOR_ALARM_DRIVER_H_
#define MONITOR_ALARM_DRIVER_H_

/*define states*/
enum
{
	Monitor_Alarm_Driver_waiting,
	Monitor_Alarm_Driver_AlarmON,
	Monitor_Alarm_Driver_AlarmOFF
	
}Monitor_Alarm_Driver_state_id;

/*declare states functions ULS */
STATE_DEFINE(Monitor_Alarm_Driver_waiting);
STATE_DEFINE(Monitor_Alarm_Driver_AlarmON);
STATE_DEFINE(Monitor_Alarm_Driver_AlarmOFF);

void Monitor_Alarm_Driver_init();
/* STATE pointer to function */
extern void (*Monitor_Alarm_Driver_state) ();



#endif 
