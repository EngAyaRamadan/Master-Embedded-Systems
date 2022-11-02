/*
 Name        : factorial_number.c
 Author      : Aya Ramadan
 Version     : 1
 Description : this code to caculate the factorial of any positive number
 */

#include <stdio.h>

int main(void)
{
	int num;
    unsigned long int fact=1;
 printf("Enter an integer number:");
  fflush(stdin);fflush(stdout);
 scanf("%d",&num);
if(num>=0)
 {
	if(num==0)
	  {
		printf("factorial = 1");
	  }
	else
	{
		for(int i=1;i<=num;i++)
		{
			fact*=i;
		}
	 printf("Factorial= %lu",fact);
	}

 }
else
  printf("Error!!! Factorial of negative number doesn't exist");

	return 0;
}
