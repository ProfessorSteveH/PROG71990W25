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
	strncpy(s.studentName, Name, MAX_NAME);
	return s;
}

//R - read

void PrintStudent(STUDENT s) {
	printf("STUDENT: %s, %d\n", 
		s.studentName, s.studentNumber);
}

void WriteStudentToStream(STUDENT s, FILE* stream) {
	fprintf(stream, "STUDENT\n");
	fprintf(stream, "%s\n", s.studentName);
	fprintf(stream, "%d\n", s.studentNumber);
}
//U - update

//D - delete
void DeleteStudent(STUDENT s) {
	//nothing to be done *for this impl*
}