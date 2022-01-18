#define _CRT_SECURE_NO_WARNINGS

#include "BinaryStack.h"
#include <math.h>

using namespace std;

void binaryType(int n) {
	stackLL s;
	bool sign;
	if (n >= 0) {
		sign = false;
	}
	else {
		sign = true;
	}
	init(s);
	if (sign) {
		n = (int)pow(2, 64) - (-n);
	}
	while (n > 0) {
		int r = n % 2;
		pushStack(s, r);
		n /= 2;
	}
	while (!isEmpty(s)) {
		int value = 0;
		popStack(s, value);
		printf("%d", value);
	}
}

