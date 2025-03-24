#include "participant.h"
#include <stdio.h>

// steveh - prog71990w25 - week09

// participant implementation


//C
PARTICIPANT CreateParticipantFromStudent(STUDENT s) {
	PARTICIPANT p =CreateParticipantFromProfessor
}

PARTICIPANT CreateParticipantFromProfessor(PROFESSOR p) {

}

void PrintParticipant(PARTICIPANT p) {
	switch (p.personType) {
	case STUD:	PrintStudent(p.personDetails.student);
		break;
	case PROF:	PrintProfessor(p.personDetails.professor);
		break;
	case GUST:	PrintGuest(p.personDetails.guest);
		break;
	default:	fprintf(stderr, "invalid Participant type\n");
		break;
	}
}

//R

//U

//D
void DestroyParticipant(PARTICIPANT p) {

}