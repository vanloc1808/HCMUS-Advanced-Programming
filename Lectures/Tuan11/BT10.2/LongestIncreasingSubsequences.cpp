#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include "LongestIncreasingSubsequences.h"

using namespace std;

bool initArray(int*& a, int n) {
	a = (int*)calloc(n, sizeof(int));
	if (!a) {
		return false;
	}
	return true;
}

void inputAnArray(int*& a, int& n) {
	if (!initArray(a, n)) {
		return;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
}

void outputAnArray(int* a, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

void freeArray(int*& a) {
	free(a);
	a = NULL;
}

int maxValue(int a, int b) {
	if (a >= b) {
		return a;
	}
	return b;
}

void findLongestSubsequence(int* a, int n, int*& L, int*& track, int*& res) {
	L[0] = 1;
	track[0] = -1;
	for (int i = 0; i < n; i++) {
		L[i] = 1;
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i]) {
				if (L[i] <= L[j] + 1) {
					L[i] = L[j] + 1;
					track[i] = j;
				}
			}
		}
	}
	int maxVal = L[0];
	int index = 0;
	for (int i = 0; i < n; i++) {
		if (maxVal <= L[i]) {
			maxVal = L[i];
			index = i;
		}
	}
	initArray(res, maxVal);
	printf("The length of the longest increasing subsequence is: %d.\n", maxVal);
	int i = 0;
	while (index >= 0) {
		res[i++] = a[index];
		index= track[index];
	}
	printf("The longest increasing subsequence is: \n");
	for (int i = maxVal - 1; i >= 0; i--) {
		printf("%d ", res[i]);
	}
}