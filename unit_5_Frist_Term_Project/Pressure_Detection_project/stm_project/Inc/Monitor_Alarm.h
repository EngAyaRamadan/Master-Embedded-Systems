/*
 * Monitor_Alarm.h
 *
 *  Created on: November 22, 2024
 *      Author: Aya Ramadan
 */

#ifndef MONITOR_ALARM_H_
#define MONITOR_ALARM_H_

/*define states*/
enum
{
	Monitor_Alarm_AlarmOFF,
	Monitor_Alarm_AlarmON,
	Monitor_Alarm_waiting,
	
}Monitor_Alarm_state_id;

/*declare states functions ULS */
STATE_DEFINE(Monitor_Alarm_AlarmOFF);
STATE_DEFINE(Monitor_Alarm_AlarmON);
STATE_DEFINE(Monitor_Alarm_waiting);

void Monitor_Alarm_init();
/* STATE pointer to function */
extern void (*Monitor_Alarm_state) ();



#endif 
