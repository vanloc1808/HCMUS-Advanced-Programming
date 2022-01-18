#pragma pack(1)
#pragma once
#include <stdio.h>
#include <iostream>
#include "Point.h"

using namespace std;

typedef struct CIRCLE {
	PNT center;
	double radius;
} CIR;

void readCircle(CIR& c, FILE* fi);

void writeCircle(CIR c, FILE* fo);

void binaryToConsoleCIR(CIR c, FILE* fsub);

bool readCircleArray(CIR*& cArr, int& nCirArr, FILE* fi);

void writeCircleArray(CIR* cArr, int nCirArr, FILE* fo);

void binaryToConsoleCIRArr(CIR* cArr, int nCirArr, FILE* fsub);

bool readCircleMatrix(CIR**& cMat, int& nCirRow, int& nCirCol, FILE* fi);

void writeCircleMatrix(CIR** cMat, int nCirRow, int nCirCol, FILE* fo);

void binaryToConsoleCIRMat(CIR** cMat, int nCirRow, int nCirCol, FILE* fsub);