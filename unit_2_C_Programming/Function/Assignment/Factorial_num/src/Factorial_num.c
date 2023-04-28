/*
 Name        : Factorial_num.c
 Author      : Aya Ramadan
 Version     : 1
  Description : this code to calculate the factorial of any number using recursion
*/

#include <stdio.h>
#include <stdlib.h>

int calc_factorial(int num); /* function prototypy */

int main(void)
{
	 int num,fact;
	printf("Enter an positive integer: ");
	 fflush(stdin);fflush(stdout);
	scanf("%d",&num);
	fact=calc_factorial( num); /* calling function */
	printf("Factorial of %d = %d",num,fact);


return 0;
}

int calc_factorial(int num)  /* function definetion */
{
	int fact=1;
	 if(num!=1)
		 return fact*=num*calc_factorial( num-1);   /* calling function (Recursion function) */

}
