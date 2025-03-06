#pragma once

// student interface

// week06 - steveh - prog71990w25
// C#, Java, C++, Pythn ==> classes
// C ==> ADT (abstract data type)

#define MAXNAME		60

typedef struct student {
	int studentNumber;
	char studentName[MAXNAME];
} STUDENT, *PSTUDENT;

// PSTUDENT ==> STUDENT*
// PSTUDENT*  ==> STUDENT**


//C - create 
PSTUDENT CreateStudent(const char* Name, int number);

//R - read

// this feels like an ok place to put the new function.
void PrintStudent(PSTUDENT s);



//U - update

//D - delete
void DeleteStudent(PSTUDENT s);
