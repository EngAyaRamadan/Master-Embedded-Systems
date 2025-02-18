/*

 * Student_Managment_System.c
 *
 *  Created on: Dec 9, 2024
 *      Author: Aya Ramadan
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Student_Managment_System.h"

FILE *student_data_file;
static int SearchRoll(FIFO_Buf_t* StudentBuffer,int Roll);
FIFO_status FIFO_enqueue (FIFO_Buf_t* StudentBuffer, Sstudent_node newstudent  );
FIFO_status FIFO_dequeue (FIFO_Buf_t* StudentBuffer, Sstudent_node student );

FIFO_status StudentBuffer_inti (FIFO_Buf_t* StudentBuffer,Sstudent_node* student  ,int length)
{
	FIFO_status status;
	if(StudentBuffer== NULL || student==NULL )
	{
		DPRINTF("Initialization failed")																																																												status= FIFO_NULL;
	}
	else{
		StudentBuffer->base=student;
		StudentBuffer->head=student;
		StudentBuffer->tail=student;
		StudentBuffer->count=0;
		StudentBuffer->length=length;
	}

	return status;
}

void AddStudentFile(FIFO_Buf_t* StudentBuffer)
{
	Sstudent_node new_Student;
	int i;
	/* Open a file , Mode>>>> read */
	student_data_file=fopen("C:\\Users\\QUADRO\\workspace\\C_Programming\\Student_Managment_System\\src\\student_file.txt","r");
	/* Check if the file is not empty to access it */
	if( student_data_file == NULL)
	{
		DPRINTF("\n [ERROR] student_data_file.txt file is empty. \n")
		DPRINTF("\n [ERROR] Adding students from file >>> failed. \n")
		return;
	}

	while(!feof(student_data_file))
	{
		/* Reading roll number */
		fscanf(student_data_file, "%d",&new_Student.Roll);
		/* Reading data >>> first name, last name and GPA */
		fscanf(student_data_file, "%s", new_Student.Fname);
		fscanf(student_data_file, "%s", new_Student.Lname);
		fscanf(student_data_file, "%f", &new_Student.GPA);
		/* Reading course IDs */
		for ( i = 0; i<Courses_number; ++i)
		{
			fscanf(student_data_file, "%d", &new_Student.Courses[i]);
		}
		if( FIFO_enqueue ( StudentBuffer, new_Student  ) == FIFO_NO_ERROR )
		{
			DPRINTF("\n[INFO]student Details is added successfully  \n")
		}
		else
		{
			DPRINTF("\n[ERROR] Adding students by file failed\n")
					return;
		}
	}
	DPRINTF("\n[INFO] Students details are saved successfully\n")
	/* Close the file */
	fclose(student_data_file);
}

void AddStudentManually(FIFO_Buf_t* StudentBuffer)
{
	if(StudentBuffer->count == StudentBuffer->length)
	{
		DPRINTF("\n[ERROR] Adding students manually failed no size\n")
        		return ;
	}

	Sstudent_node new_Student;

	DPRINTF("Enter The Student Details:\n ")
	DPRINTF("Enter Roll Number: ")
	scanf("%d", &new_Student.Roll);

	if(SearchRoll(StudentBuffer,new_Student.Roll) )
	{
		DPRINTF("\n[ERROR] Roll number %d is already taken\n", new_Student.Roll)
	    DPRINTF("\n[ERROR] Adding student manually failed\n")
		return;
	}
	else
	{
		DPRINTF("Enter First Name: ")
    	scanf("%s", &new_Student.Fname);
		DPRINTF("Enter Last Name: ")
		scanf("%s", &new_Student.Lname);
		DPRINTF("Enter GPA: ")
		scanf("%f", &new_Student.GPA);
		DPRINTF("Enter Courses :\n ")
		for(int i=0;i<(sizeof(new_Student.Courses)/4);i++)
		{
			DPRINTF("> Enter Courses Number '/%d/' : ",i+1)																																																									scanf("%d", &new_Student.Courses[i]);
		}

		if( FIFO_enqueue ( StudentBuffer, new_Student  ) == FIFO_NO_ERROR )
		{
			DPRINTF("\n[INFO]student Details is added successfully  \n")
		}
		else
		{
			DPRINTF("\n[ERROR] Adding students manually failed\n")
		}
	}
}
void FindByRoll(FIFO_Buf_t* StudentBuffer)
{
	int roll;
	DPRINTF("Enter The Roll Number of the student: \n")
	scanf("%d",&roll);

	int i;
	Sstudent_node *temp=StudentBuffer->tail,*Fstudent=NULL;
	for(i=0;i<StudentBuffer->count;i++)
	{
		if(temp->Roll == roll)
		{
			Fstudent=temp;
			break;
		}
		// circular queue
		if( temp == (StudentBuffer->base)+ (StudentBuffer->length * sizeof(Sstudent_node)))
			temp=StudentBuffer->base;
		else
			temp++;
	}
	if(Fstudent == NULL )
	{
		DPRINTF("\n[ERROR] Roll Number %d not found \n",roll)
	}
	else
	{
		DPRINTF("The Student Details are \n")
		DPRINTF("The First Name is %s \n",Fstudent->Fname)
		DPRINTF("The Last Name is %s \n",Fstudent->Lname)
		DPRINTF("The GPA is %f \n",Fstudent->GPA)
		DPRINTF("The Courses are: \n")
		for(int i=0;i<(sizeof(Fstudent->Courses)/4);i++)
		{
			DPRINTF("The Course ID is : %d \n",Fstudent->Courses[i])
		}
	}
}

void FindByFrist(FIFO_Buf_t* StudentBuffer)
{
	char name[name_length];
	DPRINTF("Enter The First Name of the student: \n")
	scanf("%s",&name);

	int i;
	Sstudent_node *temp=StudentBuffer->tail,*Fstudent=NULL;
	for(i=0;i<StudentBuffer->count;i++)
	{
		if(strcmp( temp->Fname , name) == 0)
		{
			Fstudent=temp;
			break;
		}
		// circular queue
		if( temp == (StudentBuffer->base)+ (StudentBuffer->length * sizeof(Sstudent_node)))
			temp=StudentBuffer->base;
		else
			temp++;
	}
	if(Fstudent == NULL )
	{
		DPRINTF("\n[ERROR] First Name  %s not found \n",name)
	}
	else
	{
		DPRINTF("The Student Details are \n")
	    DPRINTF("The First Name is %s \n",Fstudent->Fname)
		DPRINTF("The Last Name is %s \n",Fstudent->Lname)
		DPRINTF("The GPA is %f \n",Fstudent->GPA)
		DPRINTF("The Courses are: \n")
		for(int i=0;i<(sizeof(Fstudent->Courses)/4);i++)
		{
			DPRINTF("The Course ID is : %d \n",Fstudent->Courses[i])
		}
	}
}
void FindStudentInCources(FIFO_Buf_t* StudentBuffer)
{
	int ID_course,i,num_student=0;
	DPRINTF("Enter The Course ID: ")
	scanf("%d",&ID_course);
	if(ID_course > Courses_number)
	{
		DPRINTF("\n[ERROR] Course ID %d not found \n",ID_course)
	    		return ;
	}

	Sstudent_node *temp=StudentBuffer->tail,*Fstudent=NULL;
	for(i=0;i<StudentBuffer->count;i++)
	{
		for(int j=0;j<(sizeof(Fstudent->Courses)/4);j++)
		{
			if( temp->Courses[j] == ID_course )
			{
				++num_student;
				DPRINTF("\nThe Student Details are \n")
				DPRINTF("The First Name is %s \n",temp->Fname)
				DPRINTF("The Last Name is %s \n",temp->Lname)
				DPRINTF("The GPA is %f \n",temp->GPA)
				break;
			}
		}
		// circular queue
		if( temp == (StudentBuffer->base)+ (StudentBuffer->length * sizeof(Sstudent_node)))
			temp=StudentBuffer->base;
		else
			temp++;
	}
	DPRINTF("[INFO] Total Number of Students Enrolled : %d \n",num_student);
}

void TotalStudent(FIFO_Buf_t* StudentBuffer)
{
	DPRINTF("\n[INFO] Total Number of students is : %d  \n",StudentBuffer->count);
	DPRINTF("[INFO] You Can Add up to %d Student \n",StudentBuffer->length);
	DPRINTF("[INFO] You Can Add %d More Student \n",StudentBuffer->length-StudentBuffer->count);
}

void DeleteStudentByRoll(FIFO_Buf_t* StudentBuffer)
{
	int roll,flag=0,i=0;
	Sstudent_node student,*temp=StudentBuffer->base;

	if(StudentBuffer->count == 0)
	{
		printf("\n[ERROR] Delete student by roll number failed No Student\n");
		return;
	}
	DPRINTF("Enter The Roll Number Which you want to delete: \n")
	scanf("%d",&roll);

	for(i=0;i<StudentBuffer->count;++i)
	{
		if(temp->Roll == roll)
		{
			flag=1;
			/* Deleting student */
			 FIFO_dequeue ( StudentBuffer, student );
			break;
		}
		++temp;
	}

	if(flag == 0 )
	{
		DPRINTF("\n[ERROR] This Roll Number %d not found \n",roll)
	}
	else
	{
		DPRINTF("\n[INFO] The Roll Number is removed successfully\n")
	}
}
void UpdateStudentByRoll(FIFO_Buf_t* StudentBuffer)
{
	int roll,i;
	Sstudent_node *temp=StudentBuffer->tail,*Fstudent=NULL;
	DPRINTF("Enter The Roll Number to update the entry: \n")
	scanf("%d",&roll);
	for(i=0;i<StudentBuffer->count;i++)
	{
		if(temp->Roll == roll)
		{
			Fstudent=temp;
			break;
		}
		// circular queue
		if( temp == (StudentBuffer->base)+ (StudentBuffer->length * sizeof(Sstudent_node)))
			temp=StudentBuffer->base;
		else
			temp++;
	}
	if(Fstudent == NULL )
	{
		DPRINTF("\n[ERROR] Roll Number %d not found \n",roll)
	}
	else
	{
		int select;
		DPRINTF("1- First Name\n")
		DPRINTF("2- Last Name\n")
		DPRINTF("3- roll no\n")
		DPRINTF("4- GPA\n")
		DPRINTF("5- Courses\n")
		scanf("%d",&select);
		switch(select)
		{
		case 1:
		{
			DPRINTF("Enter the new first name: ")
									scanf("%s",&Fstudent->Fname);
			DPRINTF("[INFO] UPDATED SUCCESSFULLY \n")

		}
		break;
		case 2:
		{
			DPRINTF("Enter the new last name: ")
									scanf("%s",&Fstudent->Lname);
			DPRINTF("[INFO] UPDATED SUCCESSFULLY \n")

		}break;
		case 3:
		{
			DPRINTF("Enter the new Roll Number: ")
		    			scanf("%d",&roll);
			if(SearchRoll(StudentBuffer,roll) )
			{
				DPRINTF("\n[ERROR] Roll number %d is already taken\n", roll)
					    		DPRINTF("\n[ERROR] Update student failed\n")
								return;
			}
			Fstudent->Roll=roll;
			DPRINTF("[INFO] UPDATED SUCCESSFULLY \n")

		}break;
		case 4:
		{
			DPRINTF("Enter the new GPA: ")
									scanf("%f",&Fstudent->GPA);
			DPRINTF("[INFO] UPDATED SUCCESSFULLY \n")

		}break;
		case 5:
		{
			DPRINTF("Enter the new courses ID:\n")
		    						for(int i=0;i<(sizeof(Fstudent->Courses)/4);i++)
		    						{
		    							DPRINTF("The Course ID %d :  ",i+1)
		    						scanf("%d",&Fstudent->Courses[i]);
		    						}
			DPRINTF("[INFO] UPDATED SUCCESSFULLY \n")

		}break;
		}
	}
}

void ShowAllINformation(FIFO_Buf_t* StudentBuffer)
{
	Sstudent_node *temp=StudentBuffer->tail;
	int i;
	if(StudentBuffer->count == 0)
	{
		DPRINTF("\n[ERROR] Show students info failed\n")
			   return;
	}
	else
	{
		DPRINTF("\nAll Students\n\n")
		for(i=0;i<StudentBuffer->count;i++)
		{
			DPRINTF("\nThe Student Details are \n")
		    DPRINTF("The First Name is %s \n",temp->Fname)
			DPRINTF("The Last Name is %s \n",temp->Lname)
			DPRINTF("The Roll Number is %d \n",temp->Roll)
			DPRINTF("The GPA is %f \n",temp->GPA)
			DPRINTF("The Courses are: \n")
			for(int j=0;j<(sizeof(temp->Courses)/4);j++)
			{
				DPRINTF("\tCourse %d id: %d\n", j + 1, temp->Courses[j])
			}
			// circular queue
			if( temp == (StudentBuffer->base)+ (StudentBuffer->length * sizeof(Sstudent_node)))
				temp=StudentBuffer->base;
			else
				temp++;
		}
	}
}

/*------------------------------------------------------------------*/
static int SearchRoll(FIFO_Buf_t* StudentBuffer,int Roll)
{
	int i,result=0;
	if(StudentBuffer->count == 0)
		result= 0;
	else
	{
		Sstudent_node  *temp=StudentBuffer->tail;
		for(i=0;i<StudentBuffer->count;i++)
		{
			if(temp->Roll == Roll)
			{
				result= 1;
				break;
			}
			// circular queue
			if( temp == (StudentBuffer->base)+ (StudentBuffer->length * sizeof(Sstudent_node)))
				temp=StudentBuffer->base;
			else
				temp++;
		}
	}
	return result;
}

FIFO_status FIFO_enqueue (FIFO_Buf_t* StudentBuffer, Sstudent_node newstudent  )
{
	if( StudentBuffer->count == StudentBuffer->length )
		return FIFO_full;
	*(StudentBuffer->head) = newstudent;
	StudentBuffer->count++;

	// circular queue
	if( StudentBuffer->head == (StudentBuffer->base)+ (StudentBuffer->length * sizeof(Sstudent_node)))
		StudentBuffer->head=StudentBuffer->base;
	else
		StudentBuffer->head++;

	return FIFO_NO_ERROR;
}

FIFO_status FIFO_dequeue (FIFO_Buf_t* StudentBuffer, Sstudent_node student )
{
	if(!StudentBuffer->base || !StudentBuffer->head || !StudentBuffer->tail)
		return FIFO_NULL;
	if(StudentBuffer->count == 0)
		return FIFO_empty;

	StudentBuffer->count--;
	// circular queue
	if(StudentBuffer->tail== (StudentBuffer->base)+ (StudentBuffer->length * sizeof(student)))
		StudentBuffer->tail=StudentBuffer->base;
	else
		StudentBuffer->tail++;

	return FIFO_NO_ERROR;
}
