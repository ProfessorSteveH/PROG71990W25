#pragma once
#include "globals.h"

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

//U - update


//D - delete
void DestroyProfessor(PROFESSOR Professor);

