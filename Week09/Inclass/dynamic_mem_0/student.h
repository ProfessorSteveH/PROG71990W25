#pragma once

// student interface

// week06 - steveh - prog71990w25
// C#, Java, C++, Pythn ==> classes
// C ==> ADT (abstract data type)

#define MAXNAME		60

typedef struct student {
	int studentNumber;
	char* studentName;
} STUDENT;

//C - create 
STUDENT CreateStudent(const char* Name, int number);

//R - read

// this feels like an ok place to put the new function.
void PrintStudent(STUDENT s);

// bad practice (passes a stack variable)
//char* GetStudentName(STUDENT s);


//U - update

//D - delete
void DeleteStudent(STUDENT s);
