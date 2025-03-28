#pragma once
#include "globals.h"
#include <stdio.h>

// student interface

// week06 - steveh - prog71990w25
// C#, Java, C++, Pythn ==> classes
// C ==> ADT (abstract data type)


typedef struct student {
	int studentNumber;
	char studentName[MAX_NAME];
} STUDENT;

//C - create 
STUDENT CreateStudent(const char* Name, int number);

//R - read

// this feels like an ok place to put the new function.
void PrintStudent(STUDENT Student);


//U - update

void WriteStudentToStream(STUDENT s, FILE* stream);

STUDENT ReadStudentFromStream(FILE* stream);

//D - delete
void DeleteStudent(STUDENT Student);