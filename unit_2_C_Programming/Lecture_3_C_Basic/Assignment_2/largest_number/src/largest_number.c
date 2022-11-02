/*
 Name        : largest_number.c
 Author      : Aya Ramadan
 Version     : 1
 Description : this code to calculate the largest number Among three number
*/

#include <stdio.h>

int main(void)
{
	float num1,num2,num3;
 printf("Enter three number:");
  fflush(stdin);fflush(stdout);
 scanf("%f%f%f",&num1,&num2,&num3);

if(num1>num2 && num1>num3)
  printf("largest number = %.3f",num1);
else if(num2>num1 && num2>num3)
  printf("largest number = %.3f",num2);
else
  printf("largest number = %.3f",num3);

	return 0;
}
