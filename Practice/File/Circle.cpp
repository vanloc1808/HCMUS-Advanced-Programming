#include "Circle.h"

void readCircle(CIR& c, FILE* fi) {
	fscanf(fi, "%lf%lf%lf", &c.center.x, &c.center.y, &c.radius);
}

void writeCircle(CIR c, FILE* fo) {
	fwrite(&c, sizeof(CIR), 1, fo);
}

void binaryToConsoleCIR(CIR c, FILE* fsub) {
	fread(&c, sizeof(CIR), 1, fsub);
	printf("(%f, %f), R = %f", c.center.x, c.center.y, c.radius);
}

bool readCircleArray(CIR*& cArr, int& nCirArr, FILE* fi) {
	if (!cArr) {
		return false;
	}
	else
	{
		for (int i = 0; i < nCirArr; i++) {
			readCircle(cArr[i], fi);
		}
		return true;
	}
}

void writeCircleArray(CIR* cArr, int nCirArr, FILE* fo) {
	for (int i = 0; i < nCirArr; i++) {
		writeCircle(cArr[i], fo);
	}
}

void binaryToConsoleCIRArr(CIR* cArr, int nCirArr, FILE* fsub) {
	for (int i = 0; i < nCirArr; i++) {
		binaryToConsoleCIR(cArr[i], fsub);
		if (i == nCirArr - 1) {
			printf(".");
		}
		else
		{
			printf("; ");
		}
	}
	printf("\n");
}

bool readCircleMatrix(CIR**& cMat, int& nCirRow, int& nCirCol, FILE* fi) {
	fscanf(fi, "%d%d", &nCirRow, &nCirCol);
	cMat = (CIR**)calloc(nCirRow, sizeof(CIR*));
	if (!cMat) {
		return false;
	}
	else {
		cMat[0] = (CIR*)calloc(nCirRow * nCirCol, sizeof(CIR));
		if (!cMat[0]) {
			return false;
		}
		else
		{
			for (int i = 1; i < nCirRow; i++) {
				cMat[i] = cMat[0] + i * nCirCol;
			}
			for (int i = 0; i < nCirRow; i++) {
				readCircleArray(cMat[i], nCirCol, fi);
			}
		}
	}
}

void writeCircleMatrix(CIR** cMat, int nCirRow, int nCirCol, FILE* fo) {
	for (int i = 0; i < nCirRow; i++) {
		writeCircleArray(cMat[i], nCirCol, fo);
	}
}

void binaryToConsoleCIRMat(CIR** cMat, int nCirRow, int nCirCol, FILE* fsub) {
	for (int i = 0; i < nCirRow; i++) {
		binaryToConsoleCIRArr(cMat[i], nCirCol, fsub);
	}
}