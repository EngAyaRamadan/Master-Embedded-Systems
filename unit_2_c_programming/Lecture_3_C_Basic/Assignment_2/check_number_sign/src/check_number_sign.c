/*
 Name        : check_number_sign.c
 Author      : Aya Ramadan
 Version     : 1
  Description : this code to check the number sign
 */

#include <stdio.h>

int main(void)
{
	float num;
  printf("Enter a number:");
   fflush(stdin);fflush(stdout);
  scanf("%f",&num);
if(num>0)
  printf("%.3f is positive",num);
else if(num==0)
  printf("You entered zero");
else
  printf(" %.3f is Negative",num);

	return 0;
}
