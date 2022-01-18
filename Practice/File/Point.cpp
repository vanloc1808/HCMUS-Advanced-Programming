#include "Point.h"

void readPointStruct(PNT& M, FILE* fi) {
	fscanf(fi, "%lf%lf", &M.x, &M.y);
}

void writePointStruct(PNT M, FILE* fo) {
	fwrite(&M, sizeof(PNT), 1, fo);
}

void binaryToConsolePNT(PNT M, FILE* fsub) {
	fread(&M, sizeof(PNT), 1, fsub);
	printf("(%f, %f)", M.x, M.y);
}

bool readPointStructArray(PNT*& pointArr, int nPoiArr, FILE* fi) {
	if (!pointArr) {
		return false;
	}
	else
	{
		for (int i = 0; i < nPoiArr; i++) {
			readPointStruct(pointArr[i], fi);
		}
		return true;
	}
}

void writePointStructArray(PNT* pointArr, int nPoiArr, FILE* fo) {
	for (int i = 0; i < nPoiArr; i++) {
		writePointStruct(pointArr[i], fo);
	}
}

void binaryToConsolePArr(PNT* pointArr, int nPoiArr, FILE* fsub) {
	for (int i = 0; i < nPoiArr; i++) {
		binaryToConsolePNT(pointArr[i], fsub);
		if(i == nPoiArr - 1) {
			printf(". ");
		}
		else {
			printf(", ");
		}
	}
	printf("\n");
}

bool readPointStructMatrix(PNT**& pointMat, int& nPoRow, int& nPoCol, FILE* fi) {
	fscanf(fi, "%d%d", &nPoRow, &nPoCol);
	pointMat = (PNT**)calloc(nPoRow, sizeof(PNT*));
	if (!pointMat) {
		return false;
	}
	else {
		pointMat[0] = (PNT*)calloc(nPoRow * nPoCol, sizeof(PNT));
		if (!pointMat[0]) {
			return false;
		}
		else {
			for (int i = 1; i < nPoRow; i++) {
				pointMat[i] = pointMat[0] + i * nPoCol;
			}
			for (int i = 0; i < nPoRow; i++) {
				readPointStructArray(pointMat[i], nPoCol, fi);
			}
		}
	}
}

void writePointStructMatrix(PNT** pointMat, int nPoRow, int nPoCol, FILE* fo) {
	for (int i = 0; i < nPoRow; i++) {
		writePointStructArray(pointMat[i], nPoCol, fo);
	}
}

void binaryToConsolePMat(PNT** pointMat, int nPoRow, int nPoCol, FILE* fsub) {
	for (int i = 0; i < nPoRow; i++) {
		binaryToConsolePArr(pointMat[i], nPoCol, fsub);
	}
}