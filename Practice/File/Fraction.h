#pragma pack(1)
#pragma once

#include <iostream>
#include <stdio.h>

using namespace std;

typedef struct FRACTION {
	int numerator;
	int denominator;
} FRAC;

void readFracStruct(FRAC& fr, FILE* fi);

void writeFracStruct(FRAC fr, FILE* fo);

void binaryToConSoleFR(FRAC fr, FILE* fsub);

bool readFracStructArray(FRAC*& frArr, int& nFracArr, FILE* fi);

void writeFracStructArray(FRAC* frArr, int nFracArr, FILE* fo);

void binaryToConsoleFRArr(FRAC* frArr, int nFracArr, FILE* fsub);

bool readFracStructMatrix(FRAC**& frMat, int& nRow, int& nColumn, FILE* fi);

void writeFracStructMatrix(FRAC** frMat, int nRow, int nColumn, FILE* fo);

void binaryToConsoleFRMa(FRAC** frMat, int nRow, int nColumn, FILE* fsub);
