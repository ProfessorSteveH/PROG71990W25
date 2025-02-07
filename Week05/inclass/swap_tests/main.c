#include "../q2/utils.h"
#include <stdio.h>

// unit tests for swap

// steveh - prog7990w25 - week05

void test_runner(int inA, int inB) {
	// actual, expected
	int expectedA = inA;
	int expectedB = inB;
	int actualA = inA;
	int actualB = inB;
	swap(&actualA, &actualB);
	if (expectedA == actualB && expectedB == actualA)
		printf("passed\n");
	else
		printf("failed\n");

}

int main(void) {
	test_runner(1, 2);
}