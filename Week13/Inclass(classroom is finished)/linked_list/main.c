#include "item.h"
#include "list.h"
#include <stdio.h>

int main(void) {

	PLISTNODE list = NULL;

	Add(&list, CreateItem(1));
	Add(&list, CreateItem(2));
	Add(&list, CreateItem(3));

	DisplayList(list);
	printf("----\n");

	Remove(&list, CreateItem(2));		//test of middle of list remove
	DisplayList(list);
	printf("----\n");


	Remove(&list, CreateItem(3));		// test of front of list remove
	DisplayList(list);
	printf("----\n");


	Remove(&list, CreateItem(1));		//test of single item in list remove
	DisplayList(list);
	printf("----\n");

	DeleteList(&list);//gone destroyed, in the past.
 

	//ITEM i = CreateItem(1);
	//PrintItem(i);
	//DeleteItem(i);

	return 0;
}
//$ make valgrind
//valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./main
//==2252061== Memcheck, a memory error detector
//==2252061== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
//==2252061== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
//==2252061== Command: ./main
//==2252061==
//ITEM: 3
//ITEM: 2
//ITEM: 1
//----
//ITEM: 3
//ITEM: 1
//----
//ITEM: 1
//----
//----
//==2252061==
//==2252061== FILE DESCRIPTORS: 3 open (3 std) at exit.
//==2252061==
//==2252061== HEAP SUMMARY:
//==2252061==     in use at exit: 0 bytes in 0 blocks
//==2252061==   total heap usage: 4 allocs, 4 frees, 1,072 bytes allocated
//==2252061==
//==2252061== All heap blocks were freed -- no leaks are possible
//==2252061==
//==2252061== For lists of detected and suppressed errors, rerun with: -s
//==2252061== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
