/*
 ============================================================================
 Name        : area_circle.c
 Author      : Aya Ramadan
 Version     : 1
 Description : this code to claculate the aera of circle using macros
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define pi 3.1415
#define aera(r) pi*r*r

int main(void) {

	 float radius,aera=0;
	printf("Enter the radius: ");
	fflush(stdout);
	scanf("%f",&radius);

	aera=aera(radius);
	printf("Aera=%.2f",aera);

	return EXIT_SUCCESS;
}
