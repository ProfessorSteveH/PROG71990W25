#include "student.h"
#include <stdio.h>

int main(void) {

	STUDENT s = CreateStudent("billy", 12345678);

	// this following functions would be awesome,
	// so first I will add a line to the .h file
	// then i will add a small number of lines to 
	// the .c file and then test:
	PrintStudent(s);

	DeleteStudent(s);
	return 0;
}