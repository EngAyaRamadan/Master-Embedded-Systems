/*
 Name        : check_letter.c
 Author      : Aya Ramadan
 Version     : 1
 Description : this code to check the Alphabets letter (vowel or consonant
*/

#include <stdio.h>

int main(void)
{
	char letter;
  printf("Enter an alphabet:");
    fflush(stdin);fflush(stdout);
  scanf("%c",&letter);
switch(letter)
{
case 'a':
case 'A':
case 'e':
case 'E':
case 'i':
case 'I':
case 'o':
case 'O':
case 'u':
case 'U':
	printf("%c is a vowel",letter);
 break;

 default:
	 printf("%c is a consonant",letter);

}


	return 0;
}
