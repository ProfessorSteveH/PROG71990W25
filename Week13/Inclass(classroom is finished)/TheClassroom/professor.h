#pragma once
#include "globals.h"
#include <stdio.h>
#include <stdbool.h>

// prog71990-w25 - steveh - week09

// professor interface

typedef struct professor {		
	char name[MAX_NAME];		
	char dept[MAX_DEPT];
} PROFESSOR;

//C - create
PROFESSOR CreateProfessor(char Name[], char Dept[]);

//R - read
void PrintProfessor(PROFESSOR Professor);

bool CompareProfessor(PROFESSOR lhs, PROFESSOR rhs);
PROFESSOR CopyProfessor(PROFESSOR src);

//U - update
void WriteProfessorToStream(PROFESSOR p, FILE* stream);
PROFESSOR ReadProfessorFromStream(FILE* stream);

//D - delete
void DestroyProfessor(PROFESSOR Professor);

