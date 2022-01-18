#pragma pack(1)
#pragma once

#include <stdio.h>
#include <iostream>

using namespace std;

typedef struct STUDENT {
	char id[11];
	char* fullName;
	double averPoint;
} STU;

void readStudent(STU& student, FILE* fi);

void writeStudent(STU student, FILE* fo);

void binaryToConsoleSTU(STU student, FILE* fsub);

bool readStudentArray(STU*& stuArr, int& nStuArr, FILE* fi);

void writeStudentArray(STU* stuArr, int nStuArr, FILE* fo);

void binaryToConsoleSTArr(STU* stuArr, int nStuArr, FILE* fsub);
