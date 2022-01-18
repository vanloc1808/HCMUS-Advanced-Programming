#include "RegressionFormula.h"

double sumFraction(long long n) {
	if (n == 1) {
		return 1;
	}
	else if (n % 2 == 0)
	{
		return sumFraction(n - 1) + (-1.00) / n;
	}
	else {
		return sumFraction(n - 1) + (1.00) / n;
	}
}
