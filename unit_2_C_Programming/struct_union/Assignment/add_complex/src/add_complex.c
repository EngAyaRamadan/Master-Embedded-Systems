/*
 ============================================================================
 Name        : add_complex.c
 Author      : Aya Ramadan
 Version     : 1
 Description : this code to add two complex numbers using structure that passing to function
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct Scomplex{
	               double real;
	               double imaginary;
               };
  /*function prototype*/
struct Scomplex add_complex(struct Scomplex num1,struct Scomplex num2);
int main(void) {

	struct Scomplex complex_1,complex_2,addition;
  printf("For 1st complex number \n");
  printf("Enter real and imaginary respectively : ");
    fflush(stdout);
   scanf("%lf%lf",&complex_1.real,&complex_1.imaginary);

   printf("For 2st complex number \n");
   printf("Enter real and imaginary respectively : ");
     fflush(stdout);
    scanf("%lf%lf",&complex_2.real,&complex_2.imaginary);

    addition=add_complex(complex_1,complex_2);
    fflush(stdout);
    printf("%.1lf+%.1lfi",addition.real,addition.imaginary);

	return EXIT_SUCCESS;
}
/* function to add two complex number */
struct Scomplex add_complex(struct Scomplex num1,struct Scomplex num2)
{
	struct Scomplex sum;
	 sum.real=num1.real+num2.real;
	 sum.imaginary=num1.imaginary+num2.imaginary;

return sum;
}
