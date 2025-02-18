#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// prog71990w25 - week7 - steveh

// a few last items before the midterm exam
// switch - case
// command line args
// files  (and streams)
// then back to Classroom for more typedef and union

int main(int argc, char** argv) {

	if (argc != 2) {
		printf("Usage: %s <math symbol>\n", argv[0]);
		return 1;
	}
					
	char operation = argv[1][0];

	if (operation == '+')
		printf("requested addition\n");
	else if (operation == '-')
		printf("requested subtraction\n");
	else if (operation == '*')
		printf("requested multiplication \n");
	else if (operation == '/')
		printf("requested division\n");
	else
		printf("invalid selection\n");

}