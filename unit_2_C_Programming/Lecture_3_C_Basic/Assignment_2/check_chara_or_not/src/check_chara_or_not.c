/*
 Name        : check_chara_or_not.c
 Author      : Aya Ramadan
 Version     : 1
 Description : this code to check the character that enter from user is that alphabet or not
*/

#include <stdio.h>

int main(void)
{
	char ch;
 printf("Enter a character:");
  fflush(stdin);fflush(stdout);
 scanf("%c",&ch);
if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') )
   printf("%c is an alphabet",ch);
else
   printf("%c is not an alphabet",ch);

	return 0;
}
