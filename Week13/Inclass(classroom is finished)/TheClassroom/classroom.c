#define _CRT_SECURE_NO_WARNINGS
#include "list.h"
#include "classroom.h"
#include "participant.h"
#include "utils.h"
#include <string.h>
#include <stdlib.h>

// steveh - prog71990w25 - week09

// impl of classroom



CLASSROOM CreateClassroom(const char* Subject, int MaxSize) {
	CLASSROOM c = { 0 };
	strncpy(c.subject, Subject, MAX_SUBJECT);
	c.maxSize = MaxSize;
	c.people = NULL;

	return c;
}

void PrintClassroom(CLASSROOM c) {
	printf("Subject: %s\n", c.subject);
	int max = GetMaxCapacityFromClassroom(c);
	printf("Max Size: %d\n", max);
	int count = GetCurrentCapacityFromClassroom(c);
	printf("Current Size: %d\n", count );
	DisplayList(c.people);
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

	WriteListToStream(c.people, fp);

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

	int maxSize;
	fscanf(fp, "%d\n", &maxSize);
	CLASSROOM s = CreateClassroom(buf, maxSize);

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
	return c.maxSize;
}

int GetCurrentCapacityFromClassroom(CLASSROOM c) {
	return GetListCount(c.people);
}

bool AddParticipantToClassroom(PARTICIPANT p, CLASSROOM* c) {
	if (GetCurrentCapacityFromClassroom(*c) >= GetMaxCapacityFromClassroom(*c))
		return false;

	return Add(&(c->people), p);
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


PARTICIPANT* SearchParticipantInClassroom(PARTICIPANT p, CLASSROOM c) {
	return FindParticipantInList(c.people, p);

}

PARTICIPANT* rSearchParticipantInClassroom(PARTICIPANT p, CLASSROOM c) {
	return rFindParticipantInList(c.people, p);
}




void DeleteClassroom(CLASSROOM c) {
    DeleteList(&(c.people)); 
}
