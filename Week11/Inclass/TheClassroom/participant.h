#pragma once
#include "student.h"
#include "professor.h"
#include "guest.h"
// steveh - prog71990w25 - week09

// participant interface


typedef union component {
	STUDENT student;
	PROFESSOR professor;
	GUEST guest;
} COMPONENT;

typedef enum type { STUD, PROF, GUST} TYPE;

typedef struct participant  {
	TYPE personType;
	COMPONENT personDetails;
} PARTICIPANT;

//C
PARTICIPANT CreateParticipantFromStudent(STUDENT s);
PARTICIPANT CreateParticipantFromProfessor(PROFESSOR p);

//R
void PrintParticipant(PARTICIPANT p);

//U

//D
void DestroyParticipant(PARTICIPANT p);