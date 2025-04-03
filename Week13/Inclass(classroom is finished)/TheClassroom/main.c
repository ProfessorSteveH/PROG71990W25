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

	CLASSROOM c = CreateClassroom("programming principles", 40);

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
	//                or rSearchParticipantInClassroom(pp, c);
    PARTICIPANT* found = SearchParticipantInClassroom(pp, c);
    if (found) {
        printf("Search, found entry: ");
        PrintParticipant(*found);
    }
    else {
        printf("search failed\n");
    }


	printf("------\n");
	CLASSROOM d = ReadClassroomFromFile("classroom.dat");
	PrintClassroom(d);

	DeleteClassroom(c);
	DeleteClassroom(d);
	return 0;
}

//valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./main
//==159941== Memcheck, a memory error detector
//==159941== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
//==159941== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
//==159941== Command: ./main
//==159941==
//Subject: programming principles
//Max Size: 40
//Current Size: 6
//GUEST: Ministry Auditor
//GUEST: the Dept Chair
//PROFESSOR: jill, acsit
//PROFESSOR: steve, acsit
//STUDENT: jane, 12345678
//STUDENT: billy, 12345678
//------
//Subject: programming principles
//Max Size: 40
//Current Size: 6
//STUDENT: billy, 12345678
//STUDENT: jane, 12345678
//PROFESSOR: steve, acsit
//PROFESSOR: jill, acsit
//GUEST: the Dept Chair
//GUEST: Ministry Auditor
//==159941==
//==159941== FILE DESCRIPTORS: 3 open (3 std) at exit.
//==159941==
//==159941== HEAP SUMMARY:
//==159941==     in use at exit: 0 bytes in 0 blocks
//==159941==   total heap usage: 17 allocs, 17 frees, 19,984 bytes allocated
//==159941==
//==159941== All heap blocks were freed -- no leaks are possible
//==159941==
//==159941== For lists of detected and suppressed errors, rerun with: -s
//==159941== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
