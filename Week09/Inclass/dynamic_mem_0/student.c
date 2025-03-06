#define _CRT_SECURE_NO_WARNINGS
#include "student.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// impl for student

// steveh - prog71990w25 - week06

//C - create 
STUDENT CreateStudent(const char* Name, int Number) {
	STUDENT s = { 0 };

	int len = strlen(Name) + 1;
	s.studentName = (char*)malloc(len * sizeof(char));
	if (s.studentName == NULL) {
		fprintf(stderr, "error allocating memory\n");
		exit(EXIT_FAILURE);
	}

	s.studentNumber = Number;
	strncpy(s.studentName, Name, len);
	return s;
}

//R - read

void PrintStudent(STUDENT s) {
	printf("STUDENT: %s, %d\n", 
		s.studentName, s.studentNumber);
}

// bad practice:
//char* GetStudentName(STUDENT s) {
//	return s.studentName;
//}

//U - update

//D - delete
void DeleteStudent(STUDENT s) {
	free(s.studentName);
	//nothing to be done *for this impl*
}