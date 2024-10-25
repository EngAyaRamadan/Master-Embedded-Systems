/*
 * StudentProject.h
 *
 *  Created on: Jun 24, 2024
 *      Author: Aya Ramadan
 */

#ifndef STUDENTPROJECT_H_
#define STUDENTPROJECT_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

/* effective data */
struct Sdata
{
	int ID;
	char name[40];
	float height;
};

/* linked list node */
struct Sstudent
{
	struct Sdata student;
	struct Sstudent * PNextstudent;
};


void addstudent();
void addstudent_nPosition( int n);
int deleteStudent();
void view_student();
void delete_all();

void Get_node_data(struct Sstudent * ptr_linkedlist,int x);
void Get_node_data_end(struct Sstudent * ptr_linkedlist,int x);
void Get_node_data_end_2ptr(struct Sstudent * ptr_linkedlist,int x);
void Get_middle_data(struct Sstudent * ptr_linkedlist);

int length_linked(struct Sstudent * ptr_linkedlist);
int length_linked_recursive(struct Sstudent * ptr_linkedlist);

void Detect_loop(struct Sstudent * ptr_linkedlist);
void reverse_linked(struct Sstudent * ptr_linkedlist);

#endif /* STUDENTPROJECT_H_ */
