#include <stdio.h>
#include <iostream>
#include "PrimeNumber.h"

using namespace std;

bool isPrime(int n) {
	if (n == 1) {
		return false;
	}
	if (n == 2 || n == 3) {
		return true;
	}
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

void primeSumExpression(int n, int*& value, int*& first) {
	value[0] = 0;
	value[1] = 0;
	value[2] = 1;
	value[3] = 1;
	first[0] = first[1] = 0;
	first[2] = 2;
	first[3] = 3;
		for (int i = 4; i <= n; i++) {
			if (isPrime(i)) {
				value[i] = 1;
				first[i] = i;
			}
			else {
				value[i] = INT_MAX;
				first[i] = 0;
				for (int j = 2; j <= i; j++) {
					if (i - j >= 2 && isPrime(j) && value[i] >= value[j] + 1) {
						value[i] = value[j] + 1;
						first[i] = j;
					}
				}
			}
		}
	printf("There is %d terms in the prime-sum expression of %d.\n", value[n], n);
	printf("%d = ", n);
	while (n > 1) {
		if (n - first[n] > 1) {
			printf("%d + ", first[n]);
		}
		else {
			printf("%d ", first[n]);
		}
		n -= first[n];
	}
	printf("\n");
}