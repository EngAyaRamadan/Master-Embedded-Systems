/*
 ============================================================================
 Name        : array_of_pointer.c
 Author      : Aya Ramadan
 Version     : 1
 Description : pointer to array that each element ia pointer to structure
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
typedef struct
{
	char* name;
	int id;
}Sstudent;
int main(void)
{
	 Sstudent s1={"aya",1},s2={"mohammed",2},s3={"ahmed",3};
	 Sstudent (*arr[3])={&s1,&s2,&s3};
	 Sstudent (*(*pt)[3])=&arr;

	printf("Name of student_2 : %s\n ",(**(*pt+1)).name);
	printf("Name of student_2 : %d\n ",(**(*pt+1)).id);

	return EXIT_SUCCESS;
}
