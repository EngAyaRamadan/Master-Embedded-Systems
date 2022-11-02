/*
 Name        : Swap_two_number.c
 Author      : Aya Raamadan
 Version     : 1
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	float a,b,temp=0;
printf("Enter value of a:");
  fflush(stdin);fflush(stdout);
scanf("%f",&a);
printf("Enter value of b:");
  fflush(stdin);fflush(stdout);
scanf("%f",&b);
  temp=a;
  a=b;
  b=temp;
printf("After swapping, value of a = %.2f \n",a);
printf("After swapping, value of b = %.1f",b);

	return 0;
}
