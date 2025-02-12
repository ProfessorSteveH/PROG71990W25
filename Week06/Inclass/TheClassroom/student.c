#define _CRT_SECURE_NO_WARNINGS
#include "student.h"
#include <stdio.h>
#include <string.h>

// impl for student

// steveh - prog71990w25 - week06

//C - create 
STUDENT CreateStudent(const char* Name, int Number) {
	STUDENT s = { 0 };
	s.studentNumber = Number;
	strncpy(s.studentName, Name, MAXNAME);
	return s;
}

//R - read

void PrintStudent(STUDENT s) {
	printf("STUDENT: %s, %d\n", 
		s.studentName, s.studentNumber);
}
//Free Tip Friday:
// if I wanted to print an array of Students, I
// would either pass the array size as a param
// or I would #define a standard size for the array
// I have a favorite, but either option is ok.
// then, my print array function would for loop
// the elements of the array from 0 to size.

//U - update

//D - delete
void DeleteStudent(STUDENT s) {
	//nothing to be done *for this impl*
}