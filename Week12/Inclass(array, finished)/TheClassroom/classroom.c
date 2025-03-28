#define _CRT_SECURE_NO_WARNINGS
#include "classroom.h"
#include "participant.h"
#include "utils.h"
#include <string.h>

// steveh - prog71990w25 - week09

// impl of classroom



CLASSROOM CreateClassroom(const char* Subject) {
	CLASSROOM c = { 0 };
	strncpy(c.subject, Subject, MAX_SUBJECT);
	for (int i = 0; i < GetMaxCapacityFromClassroom(c); i++)
		c.seatStatus[i] = EMPTY;  // yes this is redundant :)

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

bool WriteClassroomToFile(CLASSROOM c, char* filename) {
	FILE* fp = fopen(filename, "w");
	if (fp == NULL) {
		fprintf(stderr, "unable to pen file for write\n");
		return false;
	}
	fprintf(fp, "%s\n", c.subject);
	int max = GetMaxCapacityFromClassroom(c);
	fprintf(fp, "%d\n", max);
	int current = GetCurrentCapacityFromClassroom(c);
	fprintf(fp, "%d\n", current);
	for (int i = 0; i < max; i++) {
		if (c.seatStatus[i] == FILLED)
			WriteParticipantToStream(c.seats[i], fp);
	}
	fclose(fp);
	return true;
}
CLASSROOM ReadClassroomFromFile(char* filename) {
	FILE* fp = fopen(filename, "r");
	if (fp == NULL) {
		fprintf(stderr, "unable to open file for reading\n");
		exit(1);
	}

	char buf[MAX_BUF] = { 0 };
	fgets(buf, MAX_BUF, fp);
	RemoveNewLines(buf);

	CLASSROOM s = CreateClassroom(buf);

	int maxSize;
	fscanf(fp, "%d\n", &maxSize);

	int currentSize;
	fscanf(fp, "%d\n", &currentSize);

	for (int i = 0; i < currentSize; i++) {
		PARTICIPANT p = ReadParticipantFromStream(fp);
		AddParticipantToClassroom(p, &s);
	}

	fclose(fp);

	return s;
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

// convenience function
void AddStudentToClassroom(STUDENT s, CLASSROOM* c) {
	PARTICIPANT p = CreateParticipantFromStudent(s);
	AddParticipantToClassroom(p, c);
}

// convenience function
void AddProfessorToClassroom(PROFESSOR prof, CLASSROOM* c) {
	PARTICIPANT p = CreateParticipantFromProfessor(prof);
	AddParticipantToClassroom(p, c);
}

// convenience function
void AddGuestToClassroom(GUEST g, CLASSROOM* c) {
	PARTICIPANT p = CreateParticipantFromGuest(g);
	AddParticipantToClassroom(p, c);
}


void DeleteClassroom(CLASSROOM c) {
	// nothing
}