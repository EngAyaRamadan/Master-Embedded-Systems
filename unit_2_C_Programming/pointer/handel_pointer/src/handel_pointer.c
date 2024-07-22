/*
 ============================================================================
 Name        : handel_pointer.c
 Author      : Aya Ramadan
 Version     : 1
 Description : Handel the pointer
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int m=29;
	int *ab=&m;

	printf("Address of m : %p\n",&m);
	printf("Value of m : %d\n",m);

	printf("Address of pointer ab : %p\n",ab);
	printf("Content of pointer ab : %d\n",*ab);

	m=34;
	printf("Address of pointer ab : %p\n",ab);
	printf("Content of pointer ab : %d\n",*ab);

	*ab=7;
	printf("Address of m : %p\n",&m);
	printf("Value of m : %d\n",m);

	return EXIT_SUCCESS;
}
