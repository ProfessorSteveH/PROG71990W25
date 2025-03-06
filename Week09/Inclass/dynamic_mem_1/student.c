#define _CRT_SECURE_NO_WARNINGS
#include "student.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// impl for student

// steveh - prog71990w25 - week06

//C - create 
STUDENT CreateStudent(const char* Name, int Number) {
    STUDENT s = { 0 };
    int len = (strlen(Name) + 1);       //calculate length 1 time and then add 1 for '\0'
    s.studentName = (char*)malloc(len);
    if (s.studentName == NULL) {
        fprintf(stderr, "error allocating memory\n");
        exit(1);
    }

    strncpy(s.studentName, Name, len);
    s.studentNumber = Number;
    return s;
}

//R - read

void PrintStudent(STUDENT s) {
    printf("STUDENT: %s, %d\n",
        s.studentName, s.studentNumber);
}

//U - update

//D - delete
void DeleteStudent(STUDENT s) {
    free(s.studentName);
}
