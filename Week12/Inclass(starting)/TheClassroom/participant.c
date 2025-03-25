#include "participant.h"
#include <stdio.h>

// steveh - prog71990w25 - week09

// participant implementation


//C
PARTICIPANT CreateParticipantFromStudent(STUDENT s) {
	PARTICIPANT p = { 0 };
	p.personType = STUD;
	p.personDetails.student = s;
	return p;
}

PARTICIPANT CreateParticipantFromProfessor(PROFESSOR prof) {
	PARTICIPANT p = { 0 };
	p.personType = PROF;
	p.personDetails.professor = prof;
	return p;
}

PARTICIPANT CreateParticipantFromGuest(GUEST g) {
	PARTICIPANT p = { 0 };
	p.personType = GUST;
	p.personDetails.guest = g;
	return p;
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
void WriteParticipantToStream(PARTICIPANT p, FILE* stream) {
	switch (p.personType) {
	case STUD:	WriteStudentToStream(p.personDetails.student, stream);
		break;
	case PROF: WriteProfessorToStream(p.personDetails.professor, stream);
		break;
	case GUST: WriteGuestToStream(p.personDetails.guest, stream);
		break;
	default: fprintf(stderr, "unknown participnat type\n");
		break;
	}
}
//D
void DestroyParticipant(PARTICIPANT p) {

}