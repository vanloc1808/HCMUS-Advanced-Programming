#include <stdio.h>
#include "Queens.h"

void queenArrangement(int i, int n, int* queens, bool* column, bool* mainDiag, bool* subDiag, int& ans) {
	for (int j = 1; j <= n; j++) {
		if (column[j] && subDiag[i + j] && mainDiag[i - j + n - 1]) {
			queens[i] = j;
			if (i == n) {
				ans++;
			}
			else {
				column[j] = false;
				subDiag[i + j] = false;
				mainDiag[i - j + n - 1] = false;
				queenArrangement(i + 1, n, queens, column, mainDiag, subDiag, ans);
				column[j] = true;
				subDiag[i + j] = true;
				mainDiag[i - j + n - 1] = true;
			}
		}
	}
}

