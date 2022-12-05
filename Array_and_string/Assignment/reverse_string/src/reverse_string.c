/*
 Name        : reverse_string.c
 Author      : Aya Ramadan
 Version     : 1
 Description : this code to reverse the string
 */

#include <stdio.h>

int main(void)
{
  char string[50],reverse[50];
  int length=0,i,j;
printf("Enter the string:");
fflush(stdin);fflush(stdout);
 gets(string);

 while(string[length]!='\0')
 {
	 length++;
 }
 j=length;
 reverse[length]='\0';
for(i=0;i<j;i++)
{
	reverse[length-1]=string[i];
	length--;
}
printf("reverse string is:%s ",reverse);
	return 0;
}
