#pragma once
#include <stdbool.h>

// item interface
// week10 - steveh - prog71990-w25

typedef struct item {
	int value;
} ITEM;


ITEM CreateItem(int i);

ITEM CopyItem(ITEM src);

bool CompareItems(ITEM lhs, ITEM rhs);

void PrintItem(ITEM i);

void DeleteItem(ITEM i);