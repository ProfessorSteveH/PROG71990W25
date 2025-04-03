#include "participant.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


bool CompareParticipants(PARTICIPANT lhs, PARTICIPANT rhs) {
	if (lhs.personType != rhs.personType)
		return false;

	switch (lhs.personType) {
	case STUD: return CompareStudent(
						lhs.personDetails.student, 
						rhs.personDetails.student);
		break;
	case PROF: return CompareProfessor(
						lhs.personDetails.professor, 
						rhs.personDetails.professor);
		break;
	case GUST: return CompareGuest(
						lhs.personDetails.guest, 
						rhs.personDetails.guest);
		break;
	default:	fprintf(stderr, "unhandled case");
		return false;
	}

}

PARTICIPANT CopyParticipant(PARTICIPANT src) {
	PARTICIPANT dst = { 0 };

	dst.personType = src.personType;

	switch (src.personType) {
	case PROF: dst.personDetails.professor = CopyProfessor(src.personDetails.professor);
		break;
	case STUD: dst.personDetails.student = CopyStudent(src.personDetails.student);
		break;
	case GUST: dst.personDetails.guest = CopyGuest(src.personDetails.guest);
		break;
	default: fprintf(stderr, "error comparing types\n");
		exit(EXIT_FAILURE);	//again - this is some technical debt that we have failed to eliminate
	}

	return dst;
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

PARTICIPANT ReadParticipantFromStream(FILE* stream) {
	char buf[MAX_BUF] = { 0 };
	fgets(buf, MAX_BUF, stream);
	if (strcmp(buf, "STUDENT\n") == 0) {
		STUDENT s = ReadStudentFromStream(stream);
		return CreateParticipantFromStudent(s);
	}
	else if (strcmp(buf, "PROFESSOR\n") == 0) {
		PROFESSOR p = ReadProfessorFromStream(stream);
		return CreateParticipantFromProfessor(p);
	}
	else if (strcmp(buf, "GUEST\n") == 0) {
		GUEST g = ReadGuestFromStream(stream);
		return CreateParticipantFromGuest(g);
	}
	else {
		fprintf(stderr, "there is an error in the datafile\n");
		fclose(stream);
		exit(EXIT_FAILURE);
	}
}
//D
void DestroyParticipant(PARTICIPANT p) {

}