#include <stdio.h>

// take input from user and convert from inches to CMSs
// and print to screen
// cm = inches * 2.54

// prog71990 w25 - week2 - steveh 

// integers = negative, zero, positive
// floats = same as int plus fraction piece
// whole = 0 and greater, no decimals
// natural numbers = 1 and greater, no decimals

int main(void) {

	//get input from user			//input
		// validate input

	//conversion					//transform
	float outputCMs = 2.54 * inputInches;

	//print to screen				//output
	printf("the answer is %f\n", outputCMs);

	return 0;
}