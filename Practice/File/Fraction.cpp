#include "Fraction.h"

void readFracStruct(FRAC& fr, FILE* fi) {
	
	fscanf(fi, "%d %d", &fr.numerator, &fr.denominator);
}

void writeFracStruct(FRAC fr, FILE* fo) {
	
	fwrite(&fr, sizeof(FRAC), 1, fo);
	
}

void binaryToConSoleFR(FRAC fr, FILE* fsub) {
	
	fread(&fr, sizeof(FRAC), 1, fsub);
	printf("%d/%d", fr.numerator, fr.denominator);
	
}

bool readFracStructArray(FRAC*& frArr, int& nFracArr, FILE* fi) {
	
	if (!frArr) {
		printf("Error. Not enough memory.\n");
		return false;
	}
	else {
		for (int i = 0; i < nFracArr; i++) {
			readFracStruct(frArr[i], fi);
		}
		return true;
	}
}

void writeFracStructArray(FRAC* frArr, int nFracArr, FILE* fo) {
	for (int i = 0; i < nFracArr; i++) {
		writeFracStruct(frArr[i], fo);
	}
}

void binaryToConsoleFRArr(FRAC* frArr, int nFracArr, FILE* fsub) {
	for (int i = 0; i < nFracArr; i++) {
		binaryToConSoleFR(frArr[i], fsub);
		printf(" ");
	}
	printf("\n");
}

bool readFracStructMatrix(FRAC**& frMat, int& nRow, int& nColumn, FILE* fi) {
	fscanf(fi, "%d%d", &nRow, &nColumn);
	frMat = (FRAC**)calloc(nRow, sizeof(FRAC*));
	if (!frMat) {
		return false;
	}
	else {
		frMat[0] = (FRAC*)calloc(nRow * nColumn, sizeof(FRAC));
		if (!frMat[0]) {
			return false;
		}
		else {
			for (int i = 1; i < nRow; i++) {
				frMat[i] = frMat[0] + i * nColumn;
			}
			for (int i = 0; i < nRow; i++) {
				readFracStructArray(frMat[i], nColumn, fi);
			}
			return true;
		}
	}
}

void writeFracStructMatrix(FRAC** frMat, int nRow, int nColumn, FILE* fo) {
	for (int i = 0; i < nRow; i++) {
		writeFracStructArray(frMat[i], nColumn, fo);
	}
}

void binaryToConsoleFRMa(FRAC** frMat, int nRow, int nColumn, FILE* fsub) {
	for (int i = 0; i < nRow; i++) {
		binaryToConsoleFRArr(frMat[i], nColumn, fsub);
	}
}