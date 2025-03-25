#pragma once
#include "globals.h"
#include <stdio.h>

// steveh - prog71990w25 - week09

// guest interface

typedef struct guest {
	char name[MAX_NAME];
} GUEST;

GUEST CreateGuest(const char* Name);

void WriteGuestToStream(GUEST g, FILE* stream);

void PrintGuest(GUEST Guest);

void DeleteGuest(GUEST Guest);