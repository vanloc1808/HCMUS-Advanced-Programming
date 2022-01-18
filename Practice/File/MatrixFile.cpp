#include "MatrixFile.h"

bool readMatrix(int**& matrix, int& row, int& column, FILE* fi) {
	fscanf(fi, "%d%d", &row, &column);
	matrix = (int**)calloc(row, sizeof(int*));
	if (!matrix) {
		return false;
	}
	else {
		matrix[0] = (int*)calloc(row * column, sizeof(int));
		if (!matrix[0]) {
			return false;
		}
		for (int i = 1; i < row; i++) {
			matrix[i] = matrix[0] + i * column;
		}
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				fscanf(fi, "%d", &matrix[i][j]);
			}
		}
	}
	return true;
}

void writeMatrix(int** matrix, int row, int column, FILE*& fo) {
	fo = fopen("matrix.txt", "wb");
	for (int i = 0; i < row; i++) {
		fwrite(matrix[i], sizeof(int), column, fo);
	}
	fclose(fo);
}

void binaryToConsoleMT(int** matrix, int row, int column, FILE* fsub) {
	fsub = fopen("matrix.txt", "rb");
	for (int i = 0; i < row; i++) {
		fread(matrix[i], sizeof(int), column, fsub);
	}
	fclose(fsub);
	printf("The matrix is: \n");
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}

}