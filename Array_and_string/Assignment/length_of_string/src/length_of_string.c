/*
 Name        : length_of_string.c
 Author      : Aya Ramadan
 Version     : 1
 Description : this code to calculate the length of string
 */

#include <stdio.h>

int main(void)
{
	char string[100];
	int length=0;
printf("Enter an string:");
fflush(stdin);fflush(stdout);
 gets(string);

 while(string[length]!='\0')
 {
	 length++;
 }
	printf("\nLength of string= %d",length);

	return 0;
}
