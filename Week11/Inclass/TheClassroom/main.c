#include "student.h"
#include "classroom.h"
#include <stdio.h>

int main(void) {

	CLASSROOM c = CreateClassroom("programming principles");

	STUDENT s = CreateStudent("billy", 12345678);
	PARTICIPANT p = CreateParticipantFromStudent(s);
	AddParticipantToClassroom(p, &c);

	PROFESSOR pr = CreateProfessor("steve", "acsit");
	PARTICIPANT pa = CreateParticipantFromProfessor(pr);
	AddParticipantToClassroom(pa, &c);

	PrintClassroom(c);



	// this following functions would be awesome,
	// so first I will add a line to the .h file
	// then i will add a small number of lines to 
	// the .c file and then test:
	//PrintStudent(s);

	//DeleteStudent(s);

	DeleteClassroom(c);
	return 0;
}