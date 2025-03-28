#define _CRT_SECURE_NO_WARNINGS
#include "guest.h"
#include <stdio.h>
#include <string.h>

// steveh - prog71990w25 - week09

// guest impl.


GUEST CreateGuest(const char* Name) {
	GUEST g = { 0 };
	strncpy(g.name, Name, MAX_NAME);
	return g;
}

void WriteGuestToStream(GUEST g, FILE* stream) {
	fprintf(stream, "GUEST\n");
	fprintf(stream, "%s\n", g.name);
}

GUEST ReadGuestFromStream(FILE* stream) {
	char buf[MAX_BUF] = { 0 };
	fgets(buf, MAX_BUF, stream);
	RemoveNewLines(buf);

	return CreateGuest(buf);
}

void PrintGuest(GUEST g) {
	printf("GUEST: %s\n", g.name);
}

void DeleteGuest(GUEST g) {
	// nothing in this impl.
}
