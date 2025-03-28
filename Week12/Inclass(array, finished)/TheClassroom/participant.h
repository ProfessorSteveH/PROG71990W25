#pragma once
#include "student.h"
#include "professor.h"
#include "guest.h"
#include <stdio.h>

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
PARTICIPANT CreateParticipantFromGuest(GUEST g);

//R
void PrintParticipant(PARTICIPANT p);

//U
void WriteParticipantToStream(PARTICIPANT p, FILE* stream);

PARTICIPANT ReadParticipantFromStream(FILE* stream);

//D
void DestroyParticipant(PARTICIPANT p);