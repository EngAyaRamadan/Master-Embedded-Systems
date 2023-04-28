/*
 Name        :  reverse_sentance.c
 Author      : Aya Ramadan
 Version     : 1
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse_sentance(char sentance[],int length); /* function prototypy */
int main(void)
{
	  char sentence[50];
		int length=0;
	printf("Enter sentance: ");
	 fflush(stdin);fflush(stdout);
	 gets(sentence);

	  length=strlen(sentence);
   reverse_sentance(sentence,length); /* calling function */

	return 0;
}
void reverse_sentance(char sentance[],int length) /* function definetion */
{

	if(length>=0)
	{
		fflush(stdin);fflush(stdout);
	  printf("%c",sentance[length]);
	  reverse_sentance(sentance,--length);  /* calling function (Recursion function) */
	}


}
