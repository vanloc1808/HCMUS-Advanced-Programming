#include <stdio.h>
#include "Knight.h"

bool isValid(int x, int y, int n, int** position) {
	return (x >= 1 && x <= n && y >= 1 && y <= n && position[x - 1][y - 1] == 0);
}

bool knightTour(int i, int n, int x, int y, int**& position, int a[], int b[]) {
	for (int j = 0; j < 8; j++) {
		int u = x + a[j];
		int v = y + b[j];
		if (isValid(u, v, n, position)) {
			position[u - 1][v - 1] = i;
			if (i < n * n) {
				knightTour(i + 1, n, u, v, position, a, b);
			}
			else {
				return true;
			}
			position[u - 1][v - 1] = 0;
		}
	}
	return false;
}