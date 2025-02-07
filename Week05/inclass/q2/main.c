#include <stdio.h>
#include "utils.h"

// write a program to determine the max of 3 ints
// store the largest in a variable called max

//steveh - prog71990w25 - week4

int main(void) {

	//input
	int a = 1;
	int b = 3;
	int c = 2;

	//transform/calculate/do stuff
	int max = get_max_of_3_ints(a,b,c);
		
	//output
	printf("the max of %d, %d, %d is %d\n", a,b,c, max); 
	return 0;
}

