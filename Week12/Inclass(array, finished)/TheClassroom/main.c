#include "student.h"
#include "professor.h"
#include "guest.h"
#include "classroom.h"
#include <stdio.h>

// this is our classroom main - used to exercise our new
// functions as well as provide high level structure for
// the program
// steveh - prog71990w25 - week6-14

// week 12 - todo:  file i/o, convert to linked list

int main(void) {

	CLASSROOM c = CreateClassroom("programming principles");

//---
	//option 1
	PARTICIPANT p = CreateParticipantFromStudent(CreateStudent("billy", 12345678));
	AddParticipantToClassroom(p, &c);

	//option 2 - using a convenience function
	AddStudentToClassroom(CreateStudent("jane", 12345678), &c);
//---
	// and option 1 again:
	PROFESSOR pr = CreateProfessor("steve", "acsit");
	PARTICIPANT pp = CreateParticipantFromProfessor(pr);
	AddParticipantToClassroom(pp, &c);

	//and option 2 again:
	AddProfessorToClassroom(CreateProfessor("jill", "acsit"), &c);
//---
	// and option 1 (last time):
	PARTICIPANT pg = CreateParticipantFromGuest(CreateGuest("the Dept Chair"));
	AddParticipantToClassroom(pg, &c);

	// and option 2 (last time)
	AddGuestToClassroom(CreateGuest("Ministry Auditor"), &c);
//---

	PrintClassroom(c);
	WriteClassroomToFile(c, "classroom.dat");


	printf("------\n");
	CLASSROOM d = ReadClassroomFromFile("classroom.dat");
	PrintClassroom(d);

	DeleteClassroom(c);
	return 0;
}