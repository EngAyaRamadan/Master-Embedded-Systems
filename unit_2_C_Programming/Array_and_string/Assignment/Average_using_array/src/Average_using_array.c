/*
 Name        : Average_using_array.c
 Author      : Aya Ramadan
 Version     : 1
 Description : calculate average of n numbers
*/

#include <stdio.h>

int main(void)
{
	float num[50],sum=0,avr;
	int n,i;
  printf("Enter the number of data you want between 1 to 50:");
	 fflush(stdin);fflush(stdout);
  scanf("%d",&n);
 for(i=0;i<n;i++)
 {
	 printf("%d.Enter the number:",i+1);
	   fflush(stdin);fflush(stdout);
	 scanf("%f",&num[i]);
	  sum+=num[i];
 }
 avr=sum/n;
 printf("Average: %.3f ",avr);
	return 0;;
}
