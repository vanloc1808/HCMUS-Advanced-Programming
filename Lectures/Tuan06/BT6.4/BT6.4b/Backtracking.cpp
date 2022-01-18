#include "Backtracking.h"

void findArrangement(char* a, bool* chk, char* toPrint, int k, int n, int i) {
	for (int j = 0; j < n; j++) {
		if (chk[j]) {
			toPrint[i] = a[j];
			if (i == k - 1) {
				printf("%s\n", toPrint);
			}
			else {
				chk[j] = false;
				findArrangement(a, chk, toPrint, k, n, i + 1);
				chk[j] = true;
			}
		}
	}
}
