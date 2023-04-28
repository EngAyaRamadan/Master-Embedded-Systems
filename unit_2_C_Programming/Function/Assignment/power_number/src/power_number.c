/*
 Name        : power_number.c
 Author      : Aya Ramadan
 Version     : 1
  Description : this code to calculate the power of any number using recursion
*/
#include <stdio.h>
#include <stdlib.h>
int calc_power(int base,int power); /* function prototypy */
int main(void)
{
	int base,power;
	printf("Enter base number: ");
	fflush(stdin);fflush(stdout);
		scanf("%d",&base);
	printf("Enter power number(positive integer): ");
	fflush(stdin);fflush(stdout);
		scanf("%d",&power);

	printf("%d^%d=%d",base,power,calc_power( base, power));

return 0;
}

int calc_power(int base,int power) /* function definetion */
{
	int result=1;
	if(power!=0)
		return result= base*calc_power( base,power-1);
	else
		return result;

}


