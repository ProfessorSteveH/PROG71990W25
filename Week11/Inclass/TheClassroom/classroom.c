#define _CRT_SECURE_NO_WARNINGS
#include "classroom.h"
#include "participant.h"
#include <string.h>

// steveh - prog71990w25 - week09

// impl of classroom



CLASSROOM CreateClassroom(const char* Subject) {
	CLASSROOM c;
	strncpy(c.subject, Subject, MAX_SUBJECT);
	for (int i = 0; i < GetCurrentCapacityFromClassroom(c); i++)
		c.seatStatus[i] = EMPTY;

	return c;
}

void PrintClassroom(CLASSROOM c) {
	printf("Subject: %s\n", c.subject);
	int count = GetCurrentCapacityFromClassroom(c);
	printf("Size: %d\n", count );
	for(int i =0; i < count; i++) {
		if(c.seatStatus[i] == FILLED)
			PrintParticipant(c.seats[i]);
	}
}

int GetMaxCapacityFromClassroom(CLASSROOM c) {
	return CLASSROOM_MAX;
}

int GetCurrentCapacityFromClassroom(CLASSROOM c) {
	int count = 0;
	for (int i = 0; i < GetMaxCapacityFromClassroom(c); i++) {
		if (c.seatStatus[i] == FILLED)
			count++;
	}
	return count;
}

bool AddParticipantToClassroom(PARTICIPANT p, CLASSROOM* c) {
	if (GetCurrentCapacityFromClassroom(*c) >= GetMaxCapacityFromClassroom(*c))
		return false;

	int index = 0;
	while (c->seatStatus[index] != EMPTY) {
		index++;
	}
	c->seats[index] = p;
	c->seatStatus[index] = FILLED;

	return true;
}

void AddStudentToClassroom(STUDENT s, CLASSROOM* c) {
	PARTICIPANT p = CreateParticipantFromStudent(s);
	AddParticipantToClassroom(p, c);
}

void DeleteClassroom(CLASSROOM c) {
	// nothing
}