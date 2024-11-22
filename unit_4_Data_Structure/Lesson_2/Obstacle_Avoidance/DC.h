/*
 * CA.h
 *
 *  Created on: Oct 29, 2024
 *      Author: Aya Ramadan
 */

#ifndef DC_H_
#define DC_H_

/*define states*/
enum
{
	DC_IDEAL,
	DC_BUSY
}DC_state_id;

/*declare states functions CA */
STATE_define(DC_IDEAL);
STATE_define(DC_BUSY);
void DC_init();
/* STATE pointer to function */
extern void (*DC_state) ();


#endif /* CA_H_ */
