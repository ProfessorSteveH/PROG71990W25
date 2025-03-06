#include "student.h"
#include <stdio.h>
#include <stdlib.h>

// prog71990-w25 - steveh - week09

// more pointers and dynamic memory!

//  * => ' the value at (address)'
//  & => ' the address of  (value)'

// 'arrays reduce to pointer'
											//sizeof(char) == 1
//   array[0][0] == *array					char array[4]
//   array[1] == *(array + 1)
	// stride

// this is our starting point - note we write a function that
// returns a stack-located variable - this is a bad idea - please avoid!


int main(void) {

	STUDENT s = CreateStudent("stevo", 12345678);

	PrintStudent(s);
	// bad idea: printf("students name is %s\n", GetStudentName(s));

	DeleteStudent(s);
	return 0;
}

//$ make valgrind
//valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./main
//==1995070== Memcheck, a memory error detector
//==1995070== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
//==1995070== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
//==1995070== Command: ./main
//==1995070==
//STUDENT: stevo, 12345678
//==1995070==
//==1995070== FILE DESCRIPTORS: 3 open (3 std) at exit.
//==1995070==
//==1995070== HEAP SUMMARY:
//==1995070==     in use at exit: 0 bytes in 0 blocks
//==1995070==   total heap usage: 2 allocs, 2 frees, 1,030 bytes allocated
//==1995070==
//==1995070== All heap blocks were freed -- no leaks are possible
//==1995070==
//==1995070== For lists of detected and suppressed errors, rerun with: -s
//==1995070== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
