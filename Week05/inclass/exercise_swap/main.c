#include "../q2/utils.h"
#include <stdio.h>

// write a function that takes 2 ints and swaps them
// place this function in "utils" library
// example: 
//		given a=1, b=2, 
//		after running swap(a,b)
//		the value of a=2 and the value of b=1

// then write a main program (here) that
// exercises the function.

// finally create 'unit tests' project that can
// unit test the swap function

// steveh - prog71990 - week05

int main(void) {
	int a = 1;

	//  & => 'the address of '
	//  * => 'the value at ' 

	int a = 1;
	int b = 2;
	printf("before: a=%d, b=%d\n", a, b);
	swap(&a, &b);
	printf("after: a=%d, b=%d\n", a, b);

	return 0;
}