#pragma pack(1)
#pragma once

#include <iostream>
#include <stdio.h>

using namespace std;

bool readMatrix(int**& matrix, int& row, int& column, FILE* fi);

void writeMatrix(int** matrix, int row, int column, FILE*& fo);

void binaryToConsoleMT(int** matrix, int row, int column, FILE* fsub);
