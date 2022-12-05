/*
 Name        : transpose_matrix.c
 Author      : Aya Ramadan
 Version     : 1
 Description : find transpose of matrix
 */
#include <stdio.h>
int main(void)
{
	 int row,col,r,c; //defination variable
  printf("Enter the row and column of matrix:");
	 fflush(stdin);fflush(stdout);
  scanf("%d%d",&row,&col);
     int matrix[row][col],transpose[col][row]; // defination tow matrix
  /* Enter matrix from user */
  printf("Enter element of matrix:\n");
for(r=0;r<row;r++)
	for(c=0;c<col;c++)
	{
		 printf("Enter element matrix%d%d:",r+1,c+1);
			 fflush(stdin);fflush(stdout);
		   scanf("%d",&matrix[r][c]);
	}
 /*  loop to transpose matrix */
for(r=0;r<row;r++)
	for(c=0;c<col;c++)
	{
		transpose[c][r]=matrix[r][c];
	}
 /* matrix before transpose */
printf("Enterd matrix:\n");
for(r=0;r<row;r++)
    {
		for(c=0;c<col;c++)
		{
			printf("%d\t",matrix[r][c]);
		}
	   printf("\n");
	}
 /* matrix After transpose */
printf("transpose of matrix:\n");
for(r=0;r<col;r++)
    {
		for(c=0;c<row;c++)
		{
			printf("%d\t",transpose[r][c]);
		}
	   printf("\n");
	}
	return 0;
}
