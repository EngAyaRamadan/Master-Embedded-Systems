/*
 Name        : prime_number.c
 Author      : Aya Ramadan
 Version     : 1
  Description : this code to print the prime number between two intervals
*/
#include <stdio.h>
#include <stdlib.h>
int check_prime_num(int num); /* function prototypy */
int main(void)
{
	 int num_1,num_2;
	printf("Enter two numbers(intervals): ");
	 fflush(stdin);fflush(stdout);
	scanf("%d%d",&num_1,&num_2);
 printf("prime number between %d and %d are: ",num_1,num_2);
   for(int i=(num_1+1);i<num_2;i++)
     {
	   int return_fun;
	   return_fun=check_prime_num(i); /* calling function */
	   if(return_fun)
		   printf("%d ",i);
     }

return 0;
}
int check_prime_num(int num) /* function definetion */
{
	int prime=1;
 for(int j=2;j<=num/2;j++)
	  {
		if(num%j==0)
		{
			prime=0;
			break;
		}
	  }
 return prime;
}


