/*
 Name        : search_about_element.c
 Author      : Aya Ramadan
 Version     : 1
 Description : this code to search about element in Array
 */
#include <stdio.h>
int main(void)
{
	int arr[25]; //definition array
    int size,i,ele,pos,store=0;
/* enter the size of array */
  printf("Enter the size of array:");
   fflush(stdin);fflush(stdout);
  scanf("%d",&size);
/* enter the element of array */
for(i=0;i<size;i++)
   {
	  scanf("%d",&arr[i]);
   }
  printf("Enter element you want to search:");
    fflush(stdin);fflush(stdout);
  scanf("%d",&ele);
/* loop to search about element */
for(i=0;i<size;i++)
  {
	  if(ele==arr[i])
	    {
		  pos=i;
		  store=1; break;
	    }
  }

  if(store==1) // if the element is found
	 printf("Number found at the location= %d ",pos+1);
  else
	 printf(" this element is not found");
 return 0;
}
