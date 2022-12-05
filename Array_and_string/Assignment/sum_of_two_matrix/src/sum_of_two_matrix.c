/*
 Name        : sum_of_two_matrix.c
 Author      : Aya Ramadan
 Version     : 1
 Description : add two matrix
 */
#include <stdio.h>
int main(void)
{
	float a[2][2],b[2][2],z[2][2]; //definition arrays
	int r,c; //definition variable(Row,Column)
     /* Enter data of matrix one from user */
 printf("enter the element of 1st matrix:\n");
for(r=0;r<2;r++)
   for(c=0;c<2;c++)
   {
	   printf("Enter a%d%d:",r+1,c+1);
	     fflush(stdin);fflush(stdout);
	   scanf("%f",&a[r][c]);
   }
      /* Enter data of matrix two from user */
 printf("enter the element of 2nd matrix:\n");
for(r=0;r<2;r++)
  for(c=0;c<2;c++)
  {
	   printf("Enter b%d%d:",r+1,c+1);
	     fflush(stdin);fflush(stdout);
	   scanf("%f",&b[r][c]);
  }
   /* sumition of two matrix */
for(r=0;r<2;r++)
  for(c=0;c<2;c++)
  {
	z[r][c]=a[r][c]+b[r][c];
  }
 printf("sum of matrix:\n");
for(r=0;r<2;r++)
 {
	for(c=0;c<2;c++)
     {
	  printf("%.3f \t",z[r][c]);
     }
   printf("\n");
 }
	return 0;
}
