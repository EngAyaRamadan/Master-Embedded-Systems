/*
 * mainAlgorithm.h
 *
 *  Created on: November 22, 2024
 *      Author: Aya Ramadan
 */

#ifndef MAIN_ALGORITHM_H_
#define MAIN_ALGORITHM_H_

/*define states*/
enum
{
	mainAlgorithm_High_pressure_Detect
	
}mainAlgorithm_state_id;

/*declare states functions ULS */
STATE_DEFINE(mainAlgorithm_High_pressure_Detect);

/* STATE pointer to function */
extern void (*mainAlgorithm_state) ();

#endif 
