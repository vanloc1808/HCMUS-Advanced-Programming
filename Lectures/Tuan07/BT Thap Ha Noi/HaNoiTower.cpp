#include <stdio.h>
#include "HaNoiTower.h"

void transfer(int n, char src, char des) {
	printf("Chuyen dia thu %d tu cot %c sang cot %c.\n", n, src, des);
}

void HaNoiTower(int n, char src, char dest, char inter) {
	if (n == 1) {
		transfer(1, src, dest);
	}
	else {
		HaNoiTower(n - 1, src, inter, dest);
		transfer(n, src, dest);
		HaNoiTower(n - 1, inter, dest, src);
	}
}