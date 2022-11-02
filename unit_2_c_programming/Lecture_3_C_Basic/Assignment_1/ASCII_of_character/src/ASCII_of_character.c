/*
 Name        : ASCII_of_character.c
 Author      :Aya Ramadan
 Version     : 1
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char ch;
printf("Enter a character:");
  fflush(stdin);fflush(stdout);
  scanf("%c",&ch);
printf("ASCII value of %c = %d",ch,ch);

	return 0;
}
