/*
 Name        : insert_element.c
 Author      : Aya Ramadan
 Version     : 1
 Description : insert element in array
 */
#include <stdio.h>
int main(void)
{
	  int arr[25]; // definition array
	  int size,i,ele,pos; // definition variable
  /* Enter the size of array */
	printf("Enter no of element: ");
	 fflush(stdin);fflush(stdout);
	scanf("%d",&size);
 /* Enter the element of array */
for(i=0;i<size;i++)
   {
     scanf("%d",&arr[i]);
   }
   printf("Enter the element you want to insert:");
    fflush(stdin);fflush(stdout);
   scanf("%d",&ele);
   printf("Enter the position:");
      fflush(stdin);fflush(stdout);
     scanf("%d",&pos);
  /* loop to move elements */
for(i=size;i>=(pos-1);i--)
      {
        arr[i+1]=arr[i];
      }
   arr[pos-1]=ele;
   size++; // increase size after insert the element
for(i=0;i<size;i++)
      {
        printf("%d ",arr[i]);
      }
	return 0;
}
