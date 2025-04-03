#pragma once
#include "globals.h"
#include <stdio.h>
#include <stdbool.h>

// steveh - prog71990w25 - week09

// guest interface

typedef struct guest {
	char name[MAX_NAME];
} GUEST;

GUEST CreateGuest(const char* Name);

void WriteGuestToStream(GUEST g, FILE* stream);
GUEST ReadGuestFromStream(FILE* stream);


bool CompareGuest(GUEST lhs, GUEST rhs);
GUEST CopyGuest(GUEST src);

void PrintGuest(GUEST Guest);

void DeleteGuest(GUEST Guest);