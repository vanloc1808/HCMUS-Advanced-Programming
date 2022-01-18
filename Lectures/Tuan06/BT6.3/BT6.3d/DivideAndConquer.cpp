#include "DivideAndConquer.h"

bool isPrime(long long n) {
	n = abs(n);
	if (n == 1) {
		return false;
	}
	else if (n == 2 || n == 3) {
		return true;
	}
	else {
		for (int i = 2; i <= sqrt(n); i++) {
			if (n % i == 0) {
				return false;
			}
		}
		return true;
	}
}

void citeThePrime(long long* a, int l, int r) {
	if (l == r) {
		if (isPrime(a[l])) {
			printf("%lld ", a[l]);
		}
	}
	else
	{
		int mid = l + (r - l) / 2;
		citeThePrime(a, l, mid);
		citeThePrime(a, mid + 1, r);
	}
}