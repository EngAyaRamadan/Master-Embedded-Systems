/*
 ============================================================================
 Name        : reverse_pointer.c
 Author      : Aya Ramadan
 Version     : 1
 Description : reverse string using pointer
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main(void) {

	char string[30],*ptr;
	printf("Input string : ");
	fflush(stdin);fflush(stdout);
	  scanf("%s",string);
	  int size=strlen(string);
	  ptr=string+(size-1);
	  for(int i=0;i<size;i++)
	  {
		  printf("%c",*ptr);
		  --ptr;

	  }
	return EXIT_SUCCESS;
}
