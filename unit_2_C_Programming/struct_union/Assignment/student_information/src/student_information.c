/*
 ============================================================================
 Name        : student_information.c
 Author      : Aya Ramadan
 Version     : 1
 Description : this code to store data of 10 student and print it
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

# define size 10
struct Sstudent{
	             char name[20];
	             int roll;
	             float marks;
              };

int main(void) {

	struct Sstudent members[size];
	int i;
	printf("Enter information of students:\n");
for(i=0;i<size;i++)
	{
		printf("For roll number ");
		fflush(stdout);
		scanf("%d",&members[i].roll);

		printf("Enter name: ");
		fflush(stdout);
		scanf("%s",&members[i].name);

		printf("Enter marks: ");
		fflush(stdout);
		scanf("%f",&members[i].marks);

		printf("\n");
	}

    printf("Displaying information of students:\n");
for(i=0;i<size;i++)
{
	printf("Information for roll number %d:\n",i+1);
	printf("Name: %s\n",members[i].name);
	printf("Marks: %.2f\n",members[i].marks);

}



	return EXIT_SUCCESS;
}
