#define _CRT_SECURE_NO_WARNINGS
#include "professor.h"
#include <stdio.h>
#include <string.h>

// steveh - prog71990w25 - week09

// professor impl.
// 
//C - create
PROFESSOR CreateProfessor(char Name[], char Dept[]) {
	
	PROFESSOR newProfessor;

	strncpy(newProfessor.name, Name, MAX_NAME);
	strncpy(newProfessor.dept, Dept, MAX_DEPT);

	return newProfessor;
}

//R - read
void PrintProfessor(PROFESSOR Professor) {
	printf("PROFESSOR: %s, %s\n", Professor.name, Professor.dept);
}

//U - update


//D - delete
void DestroyProfessor(PROFESSOR Professor) {
	// in this implementation, nothing to be done
}
