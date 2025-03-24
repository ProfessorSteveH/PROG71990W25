#include "item.h"
#include <stdio.h>

// item impl
// steveh - prog71990-w25 - week10

ITEM CreateItem(int i) {
	ITEM I = { 0 };
	I.value = i;
	return I;
}

ITEM CopyItem(ITEM src) {
	return CreateItem(src.value);
}

bool CompareItems(ITEM lhs, ITEM rhs) {
	return lhs.value == rhs.value;
}

void PrintItem(ITEM i) {
	printf("ITEM: %d\n", i.value);
}

void DeleteItem(ITEM i) {
	//nothing (yet)
}