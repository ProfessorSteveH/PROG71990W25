#define _CRT_SECURE_NO_WARNINGS
#include "professor.h"
#include <stdio.h>
#include <string.h>

// steveh - prog71990w25 - week09

// professor impl.

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
void WriteProfessorToStream(PROFESSOR p, FILE* stream) {
	fprintf(stream, "PROFESSOR\n");
	fprintf(stream, "%s\n", p.name);
	fprintf(stream, "%s\n", p.dept);
}

PROFESSOR ReadProfessorFromStream(FILE* stream) {
	char name[MAX_BUF] = { 0 };
	fgets(name, MAX_BUF, stream);
	RemoveNewLines(name);

	char dept[MAX_BUF] = { 0 };
	fgets(dept, MAX_BUF, stream);
	RemoveNewLines(dept);

	return CreateProfessor(name, dept);
}

//D - delete
void DestroyProfessor(PROFESSOR Professor) {
	// in this implementation, nothing to be done
}
