#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <cmath>
#include "Farm.h"

using namespace std;

void inputAFarm(FARM& f, FILE* fi) {
	int n;
	fscanf(fi, "%d", &n);
	f.n = n;
	f.coordinates = (POINT*)calloc(n, sizeof(POINT));
	f.treeTypes = (int*)calloc(n, sizeof(int));
	for (int i = 0; i < n; i++) {
		fscanf(fi, "%lf%lf%d", &f.coordinates[i].x, &f.coordinates[i].y, &f.treeTypes[i]);
	}
}

void eachTypeNumber(FARM f, int*& number, FILE* fo) {
	number = (int*)calloc(3, sizeof(int));
	int n = f.n;
	int* treeTypes = f.treeTypes;
	for (int i = 0; i < n; i++) {
		number[treeTypes[i]]++;
	}
	for (int i = 0; i < 3; i++) {
		fprintf(fo, "%d ", number[i]);
	}
	fprintf(fo, "\n");
	free(number);
	number = NULL;
}

double minValue(double a, double b) {
	if (a <= b){
		return a;
	}
	return b;
}

double maxValue(double a, double b) {
	if (a >= b) {
		return a;
	}
	return b;
}

double minPerimeter(FARM f) {
	int n = f.n;
	POINT* p = f.coordinates;
	double maxX = p[0].x;
	double minX = p[0].x;
	double maxY = p[0].y;
	double minY = p[0].y;
	for (int i = 1; i < n; i++) {
		maxX = maxValue(maxX, p[i].x);
		minX = minValue(minX, p[i].x);
		maxY = maxValue(maxY, p[i].y);
		minY = minValue(minY, p[i].y);
	}
	double ans = 2 * ((maxX - minX) + (maxY - minY));
	return ans;
}

double distanceSum(POINT p, POINT* pArr, int n) {
	double ans = 0;
	for (int i = 0; i < n; i++) {
		double dx = fabs(pArr[i].x - p.x);
		double dy = fabs(pArr[i].y - p.y);
		ans += sqrt(dx * dx + dy * dy);
	}
	return ans;
}

double minPipesLength(FARM f) { //sth called geometric median
	POINT dPoint[] = { {-1.00,0.00},{1.00,0.00},{0.00,-1.00},{0.00,1.00} };
	double epsilon = 0.001;
	POINT* pArr = f.coordinates;
	int n = f.n;
	POINT pCurrent = { 0,0 };
	//now, let current be the center of gravity of the point array
	for (int i = 0; i < n; i++) {
		pCurrent.x += pArr[i].x;
		pCurrent.y += pArr[i].y;
	}
	pCurrent.x /= n;
	pCurrent.y /= n;
	double minDistance = distanceSum(pCurrent, pArr, n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n, j != i; j++) {
			POINT pNew = pArr[j];
			double newDistance = distanceSum(pNew, pArr, n);
			if (newDistance < minDistance) {
				minDistance = newDistance;
				pCurrent = pNew;
			}
		}
	}
	double testDistance = 1000;
	bool flag = false;
	while (testDistance > epsilon) {
		flag = false;
		for (int i = 0; i < 4; i++) {
			POINT pNew;
			pNew.x = pCurrent.x + testDistance * dPoint[i].x;
			pNew.y = pCurrent.y + testDistance * dPoint[i].y;
			double newDistance = distanceSum(pNew, pArr, n);
			if (newDistance < minDistance) {
				minDistance = newDistance;
				pCurrent = pNew;
				flag = true;
				break;
			}
		}
		if (!flag) {
			testDistance /= 2;
		}
	}
	return minDistance;
}