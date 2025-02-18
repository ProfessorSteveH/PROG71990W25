#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// prog71990w25 - week7 - steveh

// a few last items before the midterm exam
// switch - case
// command line args
// files  (and streams)
// then back to Classroom for more typedef and union

#define BUF_SIZE	80

int main(void) {

	FILE* fp = fopen("input.dat", "r");
	if (fp == NULL) {
		fprintf(stderr, "error opening file\n");
		return 1;
	}

	char buffer[BUF_SIZE] = { 0 };
	fgets(buffer, BUF_SIZE, fp);
	fclose(fp);

	char operation = buffer[0];
	// 3 standard streams
		// stdin => the keydboard
		// stdout => the screen
		// stderr => (default forward to stdout)

	fp = fopen("output.dat", "w");
	if (fp == NULL) {
		fprintf(stderr, "error opening file for writing\n");
		return 1;
	}

	if (operation == '+')
		fprintf(fp,"requested addition\n");
	else if (operation == '-')
		fprintf(fp, "requested subtraction\n");
	else if (operation == '*')
		fprintf(fp, "requested multiplication \n");
	else if (operation == '/')
		fprintf(fp, "requested division\n");
	else
		fprintf(fp, "invalid selection\n");

	fclose(fp);

}