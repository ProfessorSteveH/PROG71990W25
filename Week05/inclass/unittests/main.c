#include "../q2/utils.h"
#include <stdio.h>

//steveh - prog71990w25 - week05
// test harness for utils.c

void testrunner(int inA, int inB, int inC, int expected) {
	int actual = get_max_of_3_ints(inA, inB, inC);
	if (actual == expected)
		printf("passed\n");
	else
		printf("failed on input %d,%d,%d expected: %d and got %d\n",
			inA, inB, inC,
			expected, actual);
}

void main(void) {

	testrunner(1, 2, 3, 3);
	testrunner(-1, 0, 1, 1);

}