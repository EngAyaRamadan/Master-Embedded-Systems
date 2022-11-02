/*
 Name        : simple_calculator.c
 Author      : Aya Ramadan
 Version     : 1
 Description : this code for simple calculator
 ============================================================================
 */

#include <stdio.h>

int main(void)
{
	float num1,num2;
	char ch;
 printf("Enter operator either + or - or * or divide:");
  fflush(stdin);fflush(stdout);
 scanf("%c",&ch);
 printf("Enter two operands :");
  fflush(stdin);fflush(stdout);
 scanf("%f%f",&num1,&num2);
 switch(ch)
 {
   case '+':
	   printf("%.3f + %.3.f = %.3f",num1,num2,num1+num2);
	       break;
   case '-':
   	   printf("%.3f - %.3f = %.3f",num1,num2,num1-num2);
   	        break;
   case '*':
   	   printf("%.3f * %.3f = %.3f",num1,num2,num1*num2);
   	        break;
   case '/':
   	   printf("%.3f / %.3f = %.3f",num1,num2,num1/num2);
   	        break;
   default:
	   printf("Error! operator is not correct");
 }



	return 0;
}
