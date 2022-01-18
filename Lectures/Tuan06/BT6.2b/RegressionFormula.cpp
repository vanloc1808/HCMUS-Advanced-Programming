#include "RegressionFormula.h"

long long combinatorics(long long n, long long k) {
	if (k == 0 || k == n) {
		return 1;
	}
	else if (k == 1 || k == n - 1) {
		return n;
	}
	else {
		return combinatorics(n - 1, k) + combinatorics(n - 1, k - 1);
	}
}

void pascalTriangle(long long n) {
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= i; j++) {
			printf("%lld ", combinatorics(i, j));
		}
		printf("\n");
	}
}