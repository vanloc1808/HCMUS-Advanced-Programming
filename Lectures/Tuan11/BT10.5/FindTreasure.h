#pragma once

bool initMatrix(int**& a, int m, int n);

void freeMatrix(int**& a, int m, int n);

void inputMatrix(int**& a, int& m, int& n);

void findTreasure(int** treasure, int m, int n, int**& total);
