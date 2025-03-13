#pragma once
#include "globals.h"
#include "student.h"
#include "participant.h"
#include <stdbool.h>

// steveh - prog71990 w25 - week09

// classroom interface

typedef struct classroom {
	char subject[MAX_SUBJECT];
	PARTICIPANT seats[CLASSROOM_MAX];
} CLASSROOM;

//C
CLASSROOM CreateClassroom(const char* Subject);

//R
void PrintClassroom(CLASSROOM Classroom);

//U
bool AddParticipantToClassroom(PARTICIPANT p,  CLASSROOM* c);

//D
void DeleteClassroom(CLASSROOM Classroom);