#include "DivideAndConquer.h"

long long evenSum(long long* a, int l, int r) {
	if (l == r) {
		if (a[l] % 2 == 0) {
			return a[l];
		}
		else {
			return 0;
		}
	}
	else {
		int mid = l + (r - l) / 2;
		long long sum1 = evenSum(a, l, mid);
		long long sum2 = evenSum(a, mid + 1, r);
		return sum1 + sum2;
	}
}
