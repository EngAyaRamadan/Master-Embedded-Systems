/*
 Name        : multiply_floating.c
 Author      : Aya Ramadan
 Version     : 1
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	float num1,num2;
printf("Enter two number:");
  fflush(stdin);fflush(stdout);
scanf("%f",&num1);
scanf("%f",&num2);
printf("product: %f",num1*num2);

	return 0;
}
