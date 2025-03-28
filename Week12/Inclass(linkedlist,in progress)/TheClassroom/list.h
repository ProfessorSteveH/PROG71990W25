#pragma once
#include "participant.h"
#include <stdbool.h>

// list interface
// steveh - week10 - prog71990-w25

typedef struct listnode {
	PARTICIPANT data;
	struct listnode* next;
} LISTNODE, *PLISTNODE;

bool Add(PLISTNODE* list, PARTICIPANT p);

void Remove(PLISTNODE* list, PARTICIPANT p);

void DisplayList(PLISTNODE list);
int GetListCount(PLISTNODE list);
void WriteListToStream(PLISTNODE list, FILE* stream);

void DeleteList(PLISTNODE* list);
