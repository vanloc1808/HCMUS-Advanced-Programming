#include "Backtracking.h"

void findCombinatorics(char* a, char* toPrint, int k, int n, int i, int pre) {
	for (int j = pre + 1; j < n; j++) {
		toPrint[i] = a[j];
		if (i == k - 1) {
			printf("%s\n", toPrint);
		}
		else {

			findCombinatorics(a, toPrint, k, n, i + 1, j);
		}
	}
}