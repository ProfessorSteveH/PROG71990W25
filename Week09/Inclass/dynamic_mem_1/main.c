#include "student.h"
#include <stdio.h>
#include <stdlib.h>

// prog71990-w25 - steveh - week09



// this is our first step - replace the char array with a dynamic (heap)
// based name string.


int main(void) {

	STUDENT s = CreateStudent("stevo", 12345678);

	PrintStudent(s);

	DeleteStudent(s);
	return 0;
}