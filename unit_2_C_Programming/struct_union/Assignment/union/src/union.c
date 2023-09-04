/*
 ============================================================================
 Name        : union.c
 Author      : Aya Ramdan
 Version     : 1
 Description : this code to print the size of structure and union which have the same member
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

union jop{
	char name[32];
	float salary;
	int worker_no;
}u;

struct jop1{
	char name[32];
	float salary;
	int worker_no;
}s;
int main(void) {

	printf("size of union=%d\n",sizeof(u));
	printf("size of structure=%d",sizeof(s));
	return EXIT_SUCCESS;
}
