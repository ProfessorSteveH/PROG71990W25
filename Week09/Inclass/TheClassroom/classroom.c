#define _CRT_SECURE_NO_WARNINGS
#include "classroom.h"
#include "participant.h"
#include <string.h>

// steveh - prog71990w25 - week09

// impl of classroom



CLASSROOM CreateClassroom(const char* Subject) {
	CLASSROOM c;
	strncpy(c.subject, Subject, MAX_SUBJECT);
	

	return c;
}

void PrintClassroom(CLASSROOM c) {

}

bool AddParticipantToClassroom(PARTICIPANT p, CLASSROOM* c) {

}


void DeleteClassroom(CLASSROOM c) {
	// nothing
}