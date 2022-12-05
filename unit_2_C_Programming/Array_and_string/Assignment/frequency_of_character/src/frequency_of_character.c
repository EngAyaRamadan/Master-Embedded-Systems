/*
 Name        : frequency_of_character.c
 Author      :Aya Ramadan
 Version     : 1
  Description : this code to find the frequency of character in the string
 */

#include <stdio.h>
int main(void)
{
	  char string[100],ch;
	  int i=0,count=0;
	printf("Enter a string:");
	 fflush(stdin);fflush(stdout);
	gets(string);

	printf("Enter a character to find frequency:");
	 fflush(stdin);fflush(stdout);
	scanf("%c",&ch);
while(string[i]!='\0')
{
	if(ch==string[i])
		{
		count++;
		}
	i++;
}
if(count != 0)
	printf("frequency of %c=%d",ch,count);
else
   printf("the character not found in this string");
	return 0;
}
