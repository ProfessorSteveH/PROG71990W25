#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// prog71990w25 - week7 - steveh

// a few last items before the midterm exam
// switch - case
// command line args
// files  (and streams)
// then back to Classroom for more typedef and union

int main(void) {

	char operation;
	printf("enter the selected math operation: ");
	if (scanf("%c", &operation) != 1) {
		printf("error!\n");
		return 1;
	}

	switch (operation) {
		case('+'): {
			printf("requested addition\n");
			break;
		}
		case('-'): {
			printf("requested subtraction\n");
			break;
		}
		case('*'): {
			printf("requested multiplication\n");
			break;
		}
		case('%'):
		case('/'): {
			printf("requested division\n");
			break;
		}
		default:  // else
			printf("invalid selection\n");
			break;
	}
}