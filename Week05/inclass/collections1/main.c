#include <stdio.h>


// steveh - prog71990w25 - week5
// some stuff about collections.

// collection:  a bunch of related things (same type) 

int main(void) {

	int array[] = { 1,2,3,4,5 };

	for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
		printf("%d\n", array[i]);

	

	//strings in C are defined as:
	// 1. array of chars
	// 2. \0 (NULL or end of string)



	return 0;
}