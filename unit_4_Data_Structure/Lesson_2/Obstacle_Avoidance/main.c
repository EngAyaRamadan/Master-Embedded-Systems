/*
 ============================================================================
 Name        : unit3_lesson_2_obstacle_avoidance.c
 Author      : Aya Ramadan
 Version     : 1
 ============================================================================
 */

#include"state.h"
#include "CA.h"
#include"ULS.h"
#include"DC.h"
void setup()
{
//	init all the drivers
//	init IRQ
//	init Hall US_Driver DC_Driver
//	init clock
	ULS_init();
	DC_init();
// set state pointer for each block
	CA_state= STATE(CA_waiting);
	ULS_state=STATE(ULS_BUSY);
	DC_state=STATE(DC_IDEAL);

}

int main(void) {

	setup();
 while(1)
 {
	 ULS_state();
	 CA_state();
	 DC_state();
 }
}
