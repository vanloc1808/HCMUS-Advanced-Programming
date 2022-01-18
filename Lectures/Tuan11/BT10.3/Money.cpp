#include <stdio.h>
#include <iostream>
#include "Money.h"

using namespace std;

void minPieceNumber(int m, int* money, int n, int*& number, int*& first) {
	number[0] = 0; //there is no way to form the sum 0 form that pieces of money
	for (int i = 1; i <= m; i++) {
		number[i] = INT_MAX;
		for (int j = 0; j < n; j++) {
			int value = money[j];
			if (i - value >= 0 && number[i - value] + 1 < number[i]) {
				number[i] = number[i - value] + 1;
				first[i] = value;
			}
		}
	}
	printf("The minimum number of pieces needed is: %d.\n", number[m]);
	printf("The pieces we need are:\n");
	while (m > 0) {
		printf("%d ", first[m]);
		m -= first[m];
	}
	printf("\n");
}