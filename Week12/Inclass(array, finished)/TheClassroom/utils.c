#include "utils.h"
#include <stdio.h>
#include <string.h>

// steveh - prog71990w25 - week12
// utils interface

void RemoveNewLines(char* string) {
	for (int i = 0; i < strlen(string); i++) {
		if (string[i] == '\n')
			string[i] = '\0';
	}
}