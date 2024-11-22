/*
 * CA.h
 *
 *  Created on: Oct 29, 2024
 *      Author: Aya Ramadan
 */

#ifndef CA_H_
#define CA_H_

/*define states*/
enum
{
	CA_waiting,
	CA_driving
}CA_state_id;

/*declare states functions CA */
STATE_define(CA_waiting);
STATE_define(CA_driving);

/* STATE pointer to function */
extern void (*CA_state) ();


#endif /* CA_H_ */
