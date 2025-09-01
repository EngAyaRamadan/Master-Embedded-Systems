/*
 * Pressure_sensor_driver.h
 *
 *  Created on: November 22, 2024
 *      Author: Aya Ramadan
 */

#ifndef PRESSURE_SENSOR_DRIVER_H_
#define PRESSURE_SENSOR_DRIVER_H_

/*define states*/
enum
{
	Pressure_sensor_readflag,
	Pressure_sensor_waiting
	
}Pressure_sensor_state_id;

/*declare states functions Pressure_sensor */
STATE_DEFINE(Pressure_sensor_readflag);
STATE_DEFINE(Pressure_sensor_waiting);

void Pressure_sensor_init();
/* STATE pointer to function */
extern void (*Pressure_sensor_state) ();


#endif 
