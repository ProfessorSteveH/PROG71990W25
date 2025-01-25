#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define CMS_PER_INCH		2.54

// take input from user and convert from inches to CMSs
// and print to screen
// cm = inches * 2.54

// prog71990 w25 - week3 - steveh 

// integers = negative, zero, positive
// floats = same as int plus fraction piece
// whole = 0 and greater, no decimals
// natural numbers = 1 and greater, no decimals


int main(void) {

	float inputInches;
	printf("please enter your number of inches: ");
	int numSymbols = scanf("%f", &inputInches);	//when using scanf, if asking for
			                 //  ^ ------------ // numbers add a & 
						                        // if strings no &
	// 1. takes keyboard button presses
	// 2. matches input to format specifier
	// 3.  if matches - assign input to variable and return number of matches
	//     if not match, return 0 and walk away

	//        V--- a yes or no question
	//                                         && => logical AND
	//                   V-------------------- || => logical OR
	if (numSymbols != 1 || inputInches < 0) {
		printf("this is not valid input\n");
		exit(EXIT_FAILURE);		// '=' => assignment q = 5;
								// '==' => evaluate q == 5 ?
								// and '!='  => not equal

	}


	//conversion					//transform
	float outputCMs = CMS_PER_INCH * inputInches;

	//print to screen				//output
	printf("the answer is %f\n", outputCMs);

	return 0;
}