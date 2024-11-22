/*
 * ULS.h
 *
 *  Created on: Oct 29, 2024
 *      Author: Aya Ramadan
 */

#ifndef ULS_H_
#define ULS_H_

/*define states*/
enum
{
	ULS_BUSY
}ULS_state_id;

/*declare states functions ULS */
STATE_define(ULS_BUSY);
void ULS_init();
/* STATE pointer to function */
extern void (*ULS_state) ();


#endif /* ULS_H_ */
