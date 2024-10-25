/*
 * StudentProject.c
 *
 *  Created on: Jun 24, 2024
 *      Author: Aya Ramadan
 */



#include"StudentProject.h"

#define DPRINTF(...)    { \
		fflush(stdout);fflush(stdin);\
		printf(__VA_ARGS__);\
		fflush(stdout);fflush(stdin);}

struct Sstudent* gPfriststudent=NULL;

/* Add 	New Student and its Data */
void addstudent()
{
	struct Sstudent* Pnewstudent;
	struct Sstudent* Plaststudent;
	char temp_text[10];
	/* frist student */
	if(gPfriststudent == NULL)
	{
		Pnewstudent=(struct Sstudent* )malloc(sizeof(struct Sstudent));
		gPfriststudent= Pnewstudent;
	}
	/* not frist  */
	else
	{
		Plaststudent = gPfriststudent;
		while(Plaststudent->PNextstudent!= NULL)
		{
			Plaststudent=Plaststudent->PNextstudent;
		}
		Pnewstudent=(struct Sstudent* )malloc(sizeof(struct Sstudent));
		if(Pnewstudent == NULL)
		{
			DPRINTF(" There is no memory")
									return ;
		}
		Plaststudent->PNextstudent=Pnewstudent;
	}
	/*fill data*/

	DPRINTF("\nEnter the name: ")
	gets(Pnewstudent->student.name);
	DPRINTF("\nEnter the ID: ")
	gets(temp_text);
	Pnewstudent->student.ID=atoi(temp_text);
	DPRINTF("\nEnter the height: ")
	gets(temp_text);
	Pnewstudent->student.height=atof(temp_text);
	/* null last next */
	Pnewstudent->PNextstudent=NULL;

}
/*Delete Student  From The List*/
int deleteStudent()
{
	char temp_text[10];
	int selected_id;
	DPRINTF("\n Enter the selected ID to be delete: ")
	gets(temp_text);
	selected_id=atoi(temp_text);
	/* not empty */
	if(gPfriststudent)
	{
		struct Sstudent* Pselectstudent=gPfriststudent;
		struct Sstudent* Ppriviousstudent=NULL;
		while(Pselectstudent != NULL)
		{
			if(Pselectstudent->student.ID == selected_id)
			{
				if(Ppriviousstudent !=NULL)
				{
					Ppriviousstudent->PNextstudent=Pselectstudent->PNextstudent;
				}

				else
				{
					gPfriststudent=Pselectstudent->PNextstudent;
				}
				free(Pselectstudent);
				return 1;
			}

			Ppriviousstudent=Pselectstudent;
			Pselectstudent=Pselectstudent->PNextstudent;
		}
	}
	DPRINTF("\ncannot find student ID.")

	return 0;
}
/*Show The Student Data In The List*/
void view_student()
{
	struct Sstudent* Pcurrentstudent=gPfriststudent;
	int count=0;
	if(gPfriststudent == NULL)
	{
		DPRINTF("\n Empty list")
	}
	else
	{
		while(Pcurrentstudent != NULL)
		{

			DPRINTF("\n Record Number %d :",count+1)
			DPRINTF("\n \t Name: %s",Pcurrentstudent->student.name)
			DPRINTF("\n \t ID  : %d",Pcurrentstudent->student.ID)
			DPRINTF("\n \t height: %f",Pcurrentstudent->student.height)
			
			Pcurrentstudent = Pcurrentstudent->PNextstudent;
			count++;
		}
	}
}
/*Delete The Student Data In The List*/
void delete_all()
{
	struct Sstudent* Pcurrentstudent=gPfriststudent;
	if(gPfriststudent == NULL)
	{
		DPRINTF("\n Empty list")
	}
	else
	{
		while(Pcurrentstudent != NULL)
		{
			struct Sstudent* Ptempstudent=Pcurrentstudent;
			Pcurrentstudent = Pcurrentstudent->PNextstudent;
			free( Ptempstudent);
		}
		gPfriststudent=NULL;
	}
}
/*Show The Selected Student Data */
void Get_node_data(struct Sstudent * ptr_linkedlist,int index)
{
	if(ptr_linkedlist == NULL)
	{
		DPRINTF("\n Empty list")
	}
	else
	{
		int count=0;
		struct Sstudent* Ptempstudent=ptr_linkedlist;
		while(count != index)
		{
			Ptempstudent=Ptempstudent->PNextstudent;
			if(Ptempstudent == NULL )
			{
				DPRINTF("\n the list dose not include this node number")
									return ;
			}
			count++;
		}
		DPRINTF("\n node Number %d :",count)
		DPRINTF("\n \t Name: %s",Ptempstudent->student.name)
		DPRINTF("\n \t ID  : %d",Ptempstudent->student.ID)
		DPRINTF("\n \t height: %f",Ptempstudent->student.height)
	}
}
/*Get The Length of List*/
int length_linked(struct Sstudent * ptr_linkedlist)
{
	if( ptr_linkedlist== NULL)
		return 0;
	else
	{
		int count=0;
		struct Sstudent* Ptempstudent=ptr_linkedlist;
		while(Ptempstudent)
		{
			count++;
			Ptempstudent=Ptempstudent->PNextstudent;
		}
		return count;
	}
}

/*Get The Length of List using Recursive */
int length_linked_recursive(struct Sstudent * ptr_linkedlist)
{
	if( ptr_linkedlist == NULL)
		return 0;
	else
	{
		return 1+length_linked_recursive(ptr_linkedlist->PNextstudent);
	}

}
/*Show The Selected Student Data from The End */
void Get_node_data_end(struct Sstudent * ptr_linkedlist,int index)
{
	if(ptr_linkedlist == NULL)
	{
		DPRINTF("\n Empty list")
	}
	else
	{
		int count=1;
		int num_end=((length_linked(ptr_linkedlist))-index+1);
		struct Sstudent* Ptempstudent=ptr_linkedlist;
		while(count !=num_end )
		{
			Ptempstudent=Ptempstudent->PNextstudent;
			if(Ptempstudent == NULL )
			{
				DPRINTF("\n the list dose not include this node number")
								return ;
			}
			count++;
		}

		DPRINTF("\n node Number %d :",count)
		DPRINTF("\n \t Name: %s",Ptempstudent->student.name)
		DPRINTF("\n \t ID  : %d",Ptempstudent->student.ID)
		DPRINTF("\n \t height: %f",Ptempstudent->student.height);
	}
}
/*Show The Selected Student Data from The End using Two Pointer */
void Get_node_data_end_2ptr(struct Sstudent * ptr_linkedlist,int index)
{
	if(ptr_linkedlist == NULL)
	{
		DPRINTF("\n Empty list")
	}
	else
	{
		struct Sstudent* laststudent=ptr_linkedlist,* nodestudent=ptr_linkedlist;
		int count=1;
		while(laststudent->PNextstudent)
		{
			laststudent=laststudent->PNextstudent;
			if(count<index)
				count++;
			else if(count>=index)
				nodestudent=nodestudent->PNextstudent;
		}

		DPRINTF("\n node Number %d from End:",count)
		DPRINTF("\n \t Name: %s",nodestudent->student.name)
		DPRINTF("\n \t ID  : %d",nodestudent->student.ID)
		DPRINTF("\n \t height: %f",nodestudent->student.height)
	}
}
/*Show The Middle Student Data  */
void Get_middle_data(struct Sstudent * ptr_linkedlist)
{
	if(ptr_linkedlist == NULL)
	{
		DPRINTF("\n Empty list")
	}
	else
	{
		struct Sstudent* Faststudent=ptr_linkedlist,*middlestudent=ptr_linkedlist;
		while(Faststudent->PNextstudent)
		{
			Faststudent=Faststudent->PNextstudent->PNextstudent;
			middlestudent=middlestudent->PNextstudent;
			if(Faststudent->PNextstudent != NULL && Faststudent->PNextstudent->PNextstudent == NULL)
			{
				middlestudent=middlestudent->PNextstudent;
				break;
			}
		}

		DPRINTF("\n Middle node:")
		DPRINTF("\n \t Name: %s",middlestudent->student.name)
		DPRINTF("\n \t ID  : %d",middlestudent->student.ID)
		DPRINTF("\n \t height: %f",middlestudent->student.height)
	}
}
/*Check if The List Is loop Or Not */
void Detect_loop(struct Sstudent * ptr_linkedlist)
{
	if(ptr_linkedlist == NULL)
	{
		DPRINTF("\n Empty list")
	}
	else
	{
		struct Sstudent* Faststudent=ptr_linkedlist,*slowstudent=ptr_linkedlist;
		while(Faststudent->PNextstudent && Faststudent->PNextstudent->PNextstudent )
		{
			Faststudent=Faststudent->PNextstudent->PNextstudent;
			slowstudent=slowstudent->PNextstudent;
			if(Faststudent == slowstudent)
			{
				DPRINTF("\nThe loop is found");
				return;
			}
		}
		DPRINTF("\nThe loop is not found");

	}
}
/*Reverse the Student Data  */
void reverse_linked(struct Sstudent * ptr_linkedlist)
{
	if( ptr_linkedlist== NULL)
	{
		DPRINTF("\n No Reverse>> Empty list")
	}
	else if( ptr_linkedlist->PNextstudent == NULL)
	{
		return ;
	}
	else
	{
		struct Sstudent* Previousstudent=NULL;
		struct Sstudent* Pcurrentstudent=ptr_linkedlist;
		struct Sstudent* pnextstudent=Pcurrentstudent->PNextstudent;

		while(pnextstudent)
		{
			pnextstudent=Pcurrentstudent->PNextstudent;
			Pcurrentstudent->PNextstudent=Previousstudent;
			Previousstudent=Pcurrentstudent;
			Pcurrentstudent=pnextstudent;
		}
		gPfriststudent=Previousstudent;
	}
}











