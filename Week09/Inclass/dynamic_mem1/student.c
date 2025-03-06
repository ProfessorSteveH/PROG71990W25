#define _CRT_SECURE_NO_WARNINGS
#include "student.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// impl for student

// steveh - prog71990w25 - week06

//C - create 
PSTUDENT CreateStudent(const char* Name, int Number) {
	PSTUDENT s = (PSTUDENT)malloc(sizeof(STUDENT));
	if (s == NULL) {
		fprintf(stderr, "error allocating mem\n");
		exit(EXIT_FAILURE);
	}
	s->studentNumber = Number;
	strncpy(s->studentName, Name, MAXNAME);
	return s;
}

//R - read

void PrintStudent(PSTUDENT s) {
	printf("STUDENT: %s, %d\n", 
		s->studentName, s->studentNumber);
}

//U - update

//D - delete
void DeleteStudent(PSTUDENT s) {
	free(s);
}