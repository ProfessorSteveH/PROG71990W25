#pragma once
#include "item.h"

// list interface
// steveh - week10 - prog71990-w25

typedef struct listnode {
	ITEM data;
	struct listnode* next;
} LISTNODE, *PLISTNODE;

void Add(PLISTNODE* list, ITEM i);

void Remove(PLISTNODE* list, ITEM i);

void DisplayList(PLISTNODE list);

void DeleteList(PLISTNODE* list);
