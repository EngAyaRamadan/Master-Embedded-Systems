/*
 * Student_Managment_System.h
 *
 *  Created on: Dec 9, 2024
 *      Author: Aya Ramadan
 */

#ifndef STUDENT_MANAGMENT_SYSTEM_H_
#define STUDENT_MANAGMENT_SYSTEM_H_


#define DPRINTF(...)    { \
		fflush(stdout);fflush(stdin);\
		printf(__VA_ARGS__);\
		fflush(stdout);fflush(stdin);}

#define name_length    50
#define Courses_number 4

typedef struct  {
	char Fname[name_length ];
	char Lname[name_length ];
	int Roll;
	float GPA;
	int Courses[Courses_number];
}Sstudent_node;

typedef struct
{
	unsigned int length;
	unsigned int count;
	Sstudent_node *base,*head,*tail;
}FIFO_Buf_t;

typedef enum{
	FIFO_NO_ERROR,
	FIFO_full,
	FIFO_empty,
	FIFO_NULL

}FIFO_status;

FIFO_status StudentBuffer_inti (FIFO_Buf_t* StudentBuffer,Sstudent_node* student  ,int length);
void AddStudentFile(FIFO_Buf_t* StudentBuffer);
void AddStudentManually(FIFO_Buf_t* StudentBuffer);
void FindByRoll(FIFO_Buf_t* StudentBuffer);
void FindByFrist(FIFO_Buf_t* StudentBuffer);
void FindStudentInCources(FIFO_Buf_t* StudentBuffer);
void TotalStudent(FIFO_Buf_t* StudentBuffer);
void DeleteStudentByRoll(FIFO_Buf_t* StudentBuffer);
void UpdateStudentByRoll(FIFO_Buf_t* StudentBuffer);
void ShowAllINformation(FIFO_Buf_t* StudentBuffer);





#endif /* STUDENT_MANAGMENT_SYSTEM_H_ */
