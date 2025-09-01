/*
 ============================================================================
 Name        : pressure_detection.c
 Author      : Aya Ramadan
 Description :
 ============================================================================
 */


#include"state.h"
#include "driver.h"
#include"Pressure_sensor_driver.h"
#include"mainAlgorithm.h"
#include"Monitor_Alarm.h"
#include"Monitor_Alarm_driver.h"

void setup()
{
//	init all the drivers
//	init IRQ
//	init Hall US_Driver DC_Driver
//	init clock
	 Pressure_sensor_init();
	 Monitor_Alarm_init();
	 Monitor_Alarm_Driver_init();
// set state pointer for each block
	 Pressure_sensor_state=STATE(Pressure_sensor_readflag);
	 mainAlgorithm_state=STATE(mainAlgorithm_High_pressure_Detect);
	 Monitor_Alarm_state=STATE(Monitor_Alarm_AlarmOFF);
	 Monitor_Alarm_Driver_state= STATE(Monitor_Alarm_Driver_waiting);

}

int main(void) {
	GPIO_INITIALIZATION ();
	setup();

 while(1)
 {
	 Pressure_sensor_state();
	 mainAlgorithm_state();
	 Monitor_Alarm_state();
	 Monitor_Alarm_Driver_state();
 }
}
