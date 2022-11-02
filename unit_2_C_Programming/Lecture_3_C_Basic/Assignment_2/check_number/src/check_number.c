/*
 Name        : check_number.c
 Author      : Aya Ramadan
 Version     : 1
 Description : this code for check the number(even or odd)
 */

#include <stdio.h>

int main(void)
{
	int num;
  printf("Enter an integer you want to check:");
   fflush(stdin);fflush(stdout);
  scanf("%d",&num);
if((num%2)==0)
  printf("%d is even",num);
else
  printf("%d is odd",num);

	return 0;
}
