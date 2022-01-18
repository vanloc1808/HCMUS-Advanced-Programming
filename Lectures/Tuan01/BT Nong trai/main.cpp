#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include "Farm.h"

using namespace std;

int main() {
	FILE* fi = fopen("NongTrai.in", "r");
	FILE* fo = fopen("NongTrai.out", "w");

	FARM f;
	inputAFarm(f, fi);
	int* number = NULL;
	eachTypeNumber(f, number, fo);
	double perimeter = minPerimeter(f);
	fprintf(fo, "%f\n", perimeter);
	double minLength = minPipesLength(f);
	fprintf(fo, "%f\n", minLength);

	free(f.coordinates);
	free(f.treeTypes);
	fclose(fi);
	fclose(fo);
}