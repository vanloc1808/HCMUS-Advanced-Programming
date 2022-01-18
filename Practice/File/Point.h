#pragma pack(1)
#pragma once

#include <iostream>
#include <stdio.h>

using namespace std;

typedef struct POINT {
	double x;
	double y;
} PNT;

void readPointStruct(PNT& M, FILE* fi);

void writePointStruct(PNT M, FILE* fo);

void binaryToConsolePNT(PNT M, FILE* fsub);

bool readPointStructArray(PNT*& pointArr, int nPoiArr, FILE* fi);

void writePointStructArray(PNT* pointArr, int nPoiArr, FILE* fo);

void binaryToConsolePArr(PNT* pointArr, int nPoiArr, FILE* fsub);

bool readPointStructMatrix(PNT**& pointMat, int& nPoRow, int& nPoCol, FILE* fi);

void writePointStructMatrix(PNT** pointMat, int nPoRow, int nPoCol, FILE* fo);

void binaryToConsolePMat(PNT** pointMat, int nPoRow, int nPoCol, FILE* fsub);