#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include "Recursion_ArrayProcess.h"

using namespace std;

bool arrayInitAndInput(int n, int*& a, FILE* fi) {
	a = (int*)calloc(n, sizeof(int));
	if (!a) {
		return false;
	}
	for (int i = 0; i < n; i++) {
		//scanf("%d", &a[i]);
		fscanf(fi, "%d", &a[i]);
	}
	return true;
}

long long evenSum(int left, int right, int* a) {
	if (left == right) {
		if (a[left] % 2 == 0) {
			return a[left];
		}
		return 0;
	}
	int mid = left + (right - left) / 2;
	return evenSum(left, mid, a) + evenSum(mid + 1, right, a);
}

bool isPrime(int n) {
	n = abs(n);
	if (n < 2) {
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

long long primeProduct(int left, int right, int* a) { //this function will return 1 if there is no prime numbers int tha array.
	if (left == right) {
		if (isPrime(a[left])) {
			return 1LL * a[left];
		}
		return 1LL;
	}
	int mid = left + (right - left) / 2;
	return primeProduct(left, mid, a) * primeProduct(mid + 1, right, a);
}

long long negativeProduct(int left, int right, int* a, int& cnt) {
	if (left == right) {
		if (a[left] < 0) {
			cnt++;
			return 1LL * a[left];
		}
		return 1LL;
	}
	int mid = left + (right - left) / 2;
	return negativeProduct(left, mid, a, cnt) * negativeProduct(mid + 1, right, a, cnt);
}

bool isNegativeArray(int left, int right, int* a) {
	if (left == right) {
		if (a[left] < 0) {
			return true;
		}
		return false;
	}
	int mid = left + (right - left) / 2;
	return isNegativeArray(left, mid, a) && isNegativeArray(mid + 1, right, a);
}

int maxElement(int left, int right, int* a) {
	if (left == right) {
		return a[left];
	}
	int mid = left + (right - left) / 2;
	int leftMax = maxElement(left, mid, a);
	int rightMax = maxElement(mid + 1, right, a);
	return max(leftMax, rightMax);
}

int countAnX(int left, int right, int* a, int x) {
	if (left == right) {
		return (a[left] == x);
	}
	int mid = left + (right - left) / 2;
	return countAnX(left, mid, a, x) + countAnX(mid + 1, right, a, x);
}

int countPositive(int left, int right, int* a) {
	if (left == right) {
		return (a[left] > 0);
	}
	int mid = left + (right - left) / 2;
	return countPositive(left, mid, a) + countPositive(mid + 1, right, a);
}

int countDistinct(int left, int right, int* a) {
	if (left > right) {
		return 0;
	}
	for (int i = left + 1; i <= right; i++) {
		if (a[i] == a[left]) {
			return countDistinct(left + 1, right, a);
		}
	}
	return 1 + countDistinct(left + 1, right, a);
}