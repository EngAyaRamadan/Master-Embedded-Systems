/*
 ============================================================================
 Name        : alphabets_pointer.c
 Author      : Aya Ramadan
 Version     : 1
 Description : print alphabets using pointer
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	char alphabet[27]; // last character for null
	char *ptr;
	ptr=alphabet;
	for(int i=0;i<26;i++)
	{
		*ptr='A'+i;
		++ptr;
	}
	ptr=alphabet;
	printf("The alphabets are : \n");
	for(int i=0;i<26;i++)
		{
			printf("%c ",*ptr);
			++ptr;
		}
	return EXIT_SUCCESS;
}
