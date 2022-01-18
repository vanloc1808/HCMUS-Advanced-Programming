#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>

using namespace std;

bool initMatrix(int**& a, int m, int n) {
	a = (int**)calloc(m, sizeof(int*));
	if (!a) {
		return false;
	}
	for (int i = 0; i < m; i++) {
		a[i] = (int*)calloc(n, sizeof(int));
		if (!a[i]) {
			return false;
		}
	}
	return true;
}

void freeMatrix(int**& a, int m, int n) {
	for (int i = 0; i < m; i++) {
		free(a[i]);
		a[i] = NULL;
	}
	free(a);
	a = NULL;
}

void inputMatrix(int**& a, int& m, int& n) {
	initMatrix(a, m, n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
}

void findTreasure(int** treasure, int m, int n, int**& total) {
	for (int j = 0; j < n; j++) {
		total[0][j] = treasure[0][j];
	}
	for (int i = 1; i < m; i++) {
		for (int j = 0; j < n; j++) {
			total[i][j] = total[i - 1][j];
			if ((j - 1 >= 0 && total[i - 1][j - 1] >= total[i][j])) {
				total[i][j] = total[i - 1][j - 1];
			}
			if (j + 1 < n && total[i - 1][j + 1] >= total[i][j]) {
				total[i][j] = total[i - 1][j + 1];
			}
		}
	}
	for (int i = 0; i < m; i++) {
		int maxValue = total[i][0];
		int track = 0;
		for (int j = 0; j < n; j++) {
			if (total[i][j] >= maxValue) {
				maxValue = total[i][j];
				track = j;
			}
		}
		printf("At the floor %d, visit the room %d.\n", i + 1, track + 1);
	}
}