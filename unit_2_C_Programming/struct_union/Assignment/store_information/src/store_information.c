/*
 ============================================================================
 Name        : store_information.c
 Author      : Aya Ramadan
 Version     : 1
 Description : this code for store information of a student using structure
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct Sstudent{
	              char name[20];
	              int roll;
	              float marks;
               };
int main(void) {

	struct Sstudent s ;
printf("Enter information of student:\n ");
	printf("Enter name: ");
	     fflush(stdout);
	  scanf("%s",&s.name);
	printf("Enter roll number: ");
	  	 fflush(stdout);
	  scanf("%d",&s.roll);
	printf("Enter marks: ");
	     fflush(stdout);
	  scanf("%f",&s.marks);
printf("Displaying Information \n");

		printf(" name: %s \n",s.name);
		printf(" roll: %d \n",s.roll);
		printf(" marks: %.2f \n",s.marks);

	return EXIT_SUCCESS;
}
