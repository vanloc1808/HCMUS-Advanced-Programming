#pragma once

struct POINT {
	double x;
	double y;
};

struct FARM {
	int n; //the number of trees
	POINT* coordinates;
	int* treeTypes;
};

void inputAFarm(FARM& f, FILE* fi);

void eachTypeNumber(FARM f, int*& number, FILE* fo);

double minPerimeter(FARM f);

double minPipesLength(FARM f);