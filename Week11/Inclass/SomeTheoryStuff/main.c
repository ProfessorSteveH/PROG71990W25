#include <stdio.h>


// week 11 - steveh - prog71990W25

// some theory stuff
// important to know and use, less important to have 
// the words memorized.

// storage classes

// variable duration, scope, linkage

//duration - how long it lives - shorter is better
//scope - how visible - smaller is better
//linkage - 
//	- no linkage
//  - internal linkage -- requires 'static' on the variable that have internal linkage
//	- external linkage -- requires 'extern' on all using variable declarations

// type qualifiers
//  - register - back in th day, a massive performance boost.  now not.
//  - volatile - shared memory, memory optimization, safety
//  - const  - constants
//  - restrict

// other memory allocators

extern int external_linkage;

void func(fghfhgfdhd) {
	fileNo = 1;
	int block_scope = 12;
	external_linkage = 12;
}

int loop(const int count) {
	for (register int i = 0; i < count; i++)
		operation(i);
}

int main(void) {

	volatile char buffer[64] = { 0 };

	get_password_fromUser(buffer);

	cookie = authorize(server, username, buffer);

	memset(buffer, 0, sizeof(buffer));



	int block_scope = 1;
	func();

	return 0;



	func(int* in1, int* in2, int* out) {
	
		if &in1 and &out are same

		out1 = trans(in1)
	}


}
