#include <stdio.h>
#include "Recursion_Process.h"
#include <math.h>

double fractionSum(int n) {
	if (n == 1) {
		return 1.0;
	} 
	return fractionSum(n - 1) + (1.0) / n;
}

long long factorial(long long n) {
	if (n == 0) {
		return 1LL;
	}
	return n * factorial(n - 1);
}

double powerSum(double x, int n) {
	if (n == 1) {
		return x;
	}
	return powerSum(x, n - 1) + pow(x, n * 1.0);
}

double oddPowerSum(double x, int n) {
	if (n == 0) {
		return x;
	}
	return oddPowerSum(x, n - 1) + pow(x, 2.0 * n + 1);
}

double powerAndFractorialSum(double x, int n) {
	if (n == 1) {
		return x;
	} return powerAndFractorialSum(x, n - 1) + pow(x, n * 1.0) / factorial(n);
}

long long seriesNumber(int n) {
	if (n == 0 || n == 1)
	{
		return 1;
	} 
	long long S = 0;
	for (int i = 0; i <= n - 2; i++) {
		S += (2 * n - 1 - 2 * i) * seriesNumber(i) * 1LL;
	}
	return 2LL * seriesNumber(n - 1) + S;
}

int digitCount(int n) {
	if (n < 10) {
		return 1;
	} 
	return 1 + digitCount(n / 10);
}

int digitSum(int n) {
	if (n < 10) {
		return n;
	}
	return n % 10 + digitSum(n / 10);
}

int oddDigitCount(int n) {
	if (n < 10) {
		return n % 2;
	}
	return (n % 10) % 2 + oddDigitCount(n / 10);
}

bool isAllEven(int n) {
	if (n < 10) {
		return !(n % 2);
	}
	return !(n % 2) && isAllEven(n / 10);
}
