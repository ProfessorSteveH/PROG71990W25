#pragma once
#include "globals.h"
#include "student.h"
#include "participant.h"
#include <stdbool.h>

// steveh - prog71990 w25 - week09

// classroom interface

typedef enum status {EMPTY, FILLED} STATUS;
typedef struct classroom {
	char subject[MAX_SUBJECT];
	PARTICIPANT seats[CLASSROOM_MAX];
	STATUS seatStatus[CLASSROOM_MAX];
} CLASSROOM;


//C
CLASSROOM CreateClassroom(const char* Subject);

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

//D
void DeleteClassroom(CLASSROOM Classroom);