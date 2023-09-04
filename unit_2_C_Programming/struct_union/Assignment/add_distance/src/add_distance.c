/*
 ============================================================================
 Name        : add_distance.c
 Author      : aya ramadan
 Version     : 1
 Description : this code to add two distance using structure
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct Sdistance{
	               int feet;
	               float inch;
                };

int main(void) {
	struct Sdistance dis1,dis2,sum;
printf("Enter information for 1st distance\n");
	printf("Enter feet: ");
	  fflush(stdout);
	 scanf("%d",&dis1.feet);
	printf("Enter feet: ");
	  fflush(stdout);
	 scanf("%f",&dis1.inch);

printf("Enter information for 2st distance\n");
	 	printf("Enter feet: ");
	 	  fflush(stdout);
	 	 scanf("%d",&dis2.feet);
	 	printf("Enter feet: ");
	 	  fflush(stdout);
	 	 scanf("%f",&dis2.inch);

	sum.feet=dis1.feet+dis2.feet;
	sum.inch=dis1.inch+dis2.inch;

	if(sum.inch>12)
	{
		sum.inch-=12;
		sum.feet++;
	}
printf("sum of distances equal to : %d\'-%.1f\"",sum.feet,sum.inch);
	return EXIT_SUCCESS;
}
