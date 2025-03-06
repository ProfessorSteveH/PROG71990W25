#pragma once
#include "globals.h"

// student interface

// week06 - steveh - prog71990w25
// C#, Java, C++, Pythn ==> classes
// C ==> ADT (abstract data type)


typedef struct student {
	int studentNumber;
	char studentName[MAX_NAME];
} STUDENT;

//C - create 
STUDENT CreateStudent(char* Name, int number);

//R - read

// this feels like an ok place to put the new function.
void PrintStudent(STUDENT Student);


//U - update

//D - delete
void DeleteStudent(STUDENT Student);