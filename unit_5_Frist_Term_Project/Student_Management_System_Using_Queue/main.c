/*
 ============================================================================
 Name        : Student_Managment_System.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Student_Managment_System.h"



int main(void) {
	FIFO_Buf_t Student_Data;
	Sstudent_node Student_arr[50];
   int choose=1;
	StudentBuffer_inti ( &Student_Data, Student_arr  ,50);

	DPRINTF("------Welcome to the Student Management System------- \n")
	while(1)
	{
		DPRINTF("\n------Choose The Task That You Want To Perform-------- \n")
		DPRINTF("1-Add Student Manually \n")
		DPRINTF("2-Add Student From The Text File \n")
		DPRINTF("3-Find Student By Roll Number\n")
		DPRINTF("4-Find Student By Frist Name\n")
		DPRINTF("5-Find Student By Course \n")
		DPRINTF("6-Find Total Number Of Student  \n")
		DPRINTF("7-Delete Student By Roll Number \n")
		DPRINTF("8-Update Student By Roll Number \n")
		DPRINTF("9-Show All Information \n")
		DPRINTF("10-To Exit \n")
		DPRINTF("Enter Your Choose To Perform Task >>> ")
         scanf("%d",&choose);

		switch(choose)
		{
		case 1:
			AddStudentManually(&Student_Data); break;
		case 2:
			AddStudentFile(&Student_Data); break;
		case 3:
			FindByRoll(&Student_Data);break;
		case 4:
			FindByFrist(&Student_Data);break;
		case 5:
			FindStudentInCources(&Student_Data);break;
		case 6:
			TotalStudent(&Student_Data);break;
		case 7:
			DeleteStudentByRoll(&Student_Data);break;
		case 8:
			UpdateStudentByRoll(&Student_Data);break;
		case 9:
			ShowAllINformation(&Student_Data); break;
		case 10:
		{
			DPRINTF(" Exit \n");
			return 0;
		}
		}
	}

	return EXIT_SUCCESS;
}
