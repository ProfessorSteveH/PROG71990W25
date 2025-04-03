#pragma once
#include "globals.h"
#include "student.h"
#include "participant.h"
#include "list.h"
#include <stdbool.h>

// steveh - prog71990 w25 - week09

// classroom interface

typedef struct classroom {
	char subject[MAX_SUBJECT];
	PLISTNODE people;
	int maxSize;
} CLASSROOM;


//C
CLASSROOM CreateClassroom(const char* Subject, int maxSize);

//R
void PrintClassroom(CLASSROOM Classroom);

int GetCurrentCapacityFromClassroom(CLASSROOM c);
int GetMaxCapacityFromClassroom(CLASSROOM c);

//U
bool AddParticipantToClassroom(PARTICIPANT p,  CLASSROOM* c);

//convenience functions:
void AddStudentToClassroom(STUDENT s, CLASSROOM* c);
void AddProfessorToClassroom(PROFESSOR p, CLASSROOM* c);
void AddGuestToClassroom(GUEST g, CLASSROOM* c);

bool WriteClassroomToFile(CLASSROOM c, char* filename);
CLASSROOM ReadClassroomFromFile(char* filename);


PARTICIPANT* SearchParticipantInClassroom(PARTICIPANT p, CLASSROOM c);
PARTICIPANT* rSearchParticipantInClassroom(PARTICIPANT p, CLASSROOM c);


//D
void DeleteClassroom(CLASSROOM Classroom);
