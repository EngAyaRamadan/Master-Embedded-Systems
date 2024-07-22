/*
 ============================================================================
 Name        : array_reverse.c
 Author      : Aya Ramadan
 Version     : 1
 Description : print the reverse array using pointer
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int arr[5],*ptr;
    int i;
    printf("Input 5 number of elements in array :\n");
    for(i=0;i<5;i++)
    {
    	printf("element- %d: ",i+1);
    	 fflush(stdin);fflush(stdout);
    	 scanf("%d",&arr[i]);
    }
    ptr=arr+4;
    printf("The elements of array in reverse order :\n");
    for(i=4;i>=0;--i)
      {
      	printf("element- %d: %d\n",i+1,*ptr);
      	--ptr;
      }
	return EXIT_SUCCESS;
}
