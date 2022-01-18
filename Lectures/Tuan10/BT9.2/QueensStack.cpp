#include "QueensStack.h"

using namespace std;

const int NMAX = 15;

void queens(int i, int n, int col[], int mainDiag[], int subDiag[], int& solNum, stackLL& s) {
	for (int j = 1; j <= n; j++) {
		if (col[j] && mainDiag[i - j + n - 1] && subDiag[i + j]) {
			pushStack(s, j);
			if (i == n) {
				solNum++;
			}
			else {
				col[j] = false;
				mainDiag[i - j + n - 1] = false;
				subDiag[i + j] = false;
				queens(i + 1, n, col, mainDiag, subDiag, solNum, s);
				int tempValue = 0;
				popStack(s, tempValue);
				col[j] = true;
				mainDiag[i - j + n - 1] = true;
				subDiag[i + j] = true;
			}
		}
	}
}