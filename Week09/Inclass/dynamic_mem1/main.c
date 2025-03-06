#include "student.h"
#include <stdio.h>

// prog7199-w25 - steveh - week09

// main for student implemented ntirely on heap

int main(void) {

    PSTUDENT s = CreateStudent("stevo", 12345678);

    PrintStudent(s);

    DeleteStudent(s);

    return 0;
}

//$ make valgrind
//valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./main
//==1995268== Memcheck, a memory error detector
//==1995268== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
//==1995268== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
//==1995268== Command: ./main
//==1995268==
//STUDENT: stevo, 12345678
//==1995268==
//==1995268== FILE DESCRIPTORS: 3 open (3 std) at exit.
//==1995268==
//==1995268== HEAP SUMMARY:
//==1995268==     in use at exit: 0 bytes in 0 blocks
//==1995268==   total heap usage: 2 allocs, 2 frees, 1,088 bytes allocated
//==1995268==
//==1995268== All heap blocks were freed -- no leaks are possible
//==1995268==
//==1995268== For lists of detected and suppressed errors, rerun with: -s
//==1995268== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
