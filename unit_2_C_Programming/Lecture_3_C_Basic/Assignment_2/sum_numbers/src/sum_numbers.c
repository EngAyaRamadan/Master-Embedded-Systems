/*
 Name        : sum_numbers.c
 Author      : Aya Ramadan
 Version     : 1
 Description : this code to clculate the sum of any natural numbers
 */

#include <stdio.h>

int main(void)
{
	int n,sum=0;
 printf("Enter the number you want to sum:");
   fflush(stdin);fflush(stdout);
 scanf("%d",&n);

for(int i=1;i<=n;i++)
	{
	sum+=i;
	}
printf("sum = %d",sum);

	return 0;
}
