/*
 * main.c
 *
 *  Created on: Jun 22, 2024
 *      Author: Aya ramadan
 */


#include"StudentProject.h"

#define DPRINTF(...)    { \
		fflush(stdout);fflush(stdin);\
		printf(__VA_ARGS__);\
		fflush(stdout);fflush(stdin);}

extern  struct Sstudent* gPfriststudent;
void main()
{
	char temp_text[5];
	while(1)
	{

		DPRINTF("\n ==================")
						DPRINTF("\n\t Choose on the following options ")
						DPRINTF("\n 1: AddStudent ")
						DPRINTF("\n 2: Delete_Student ")
						DPRINTF("\n 3: View_Student ")
						DPRINTF("\n 4: DeleteAll ")
						DPRINTF("\n 5: GetNodeDataFirst ")
						DPRINTF("\n 6: GetNodeDataEnd ")
						DPRINTF("\n 7: GetMiddleData ")
						DPRINTF("\n 8: DetectLoop ")
						DPRINTF("\n 9: reverse_linked ")
						DPRINTF("\n 10: Length of linked list")
						DPRINTF("\n Enter Option number: ")

						gets(temp_text);
		DPRINTF("------------\n ")

		switch(atoi(temp_text))
		{
		case 1: addstudent();
		break;
		case 2: deleteStudent();
		break;
		case 3: view_student();
		break;
		case 4: delete_all();
		break;
		case 5:{
			int node_num;
			DPRINTF("\n Enter Node Number from first: ")
			scanf("%d",&node_num);
			Get_node_data(gPfriststudent,node_num);
		}
		break;
		case 6:{
			int node_num;
			DPRINTF("\n Enter Node Number from End: ")
			scanf("%d",&node_num);
			Get_node_data_end_2ptr(gPfriststudent,node_num);
		}
		break;
		case 7:  Get_middle_data(gPfriststudent);
			break;
		case 8:  Detect_loop(gPfriststudent);
				break;
		case 9:  reverse_linked(gPfriststudent);
				break;
		case 10: DPRINTF(" the length of linked list is %d",length_linked_recursive(gPfriststudent));
		break;

		default:
			DPRINTF("\n wrong option")
			break;

		}
	}
}
