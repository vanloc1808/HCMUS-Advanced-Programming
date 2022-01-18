#include "DivideAndConquer.h"

int searchForX(long long* a, long long x, int l, int r) {
	if (l <= r) {
		int mid = l + (r - l) / 2;
		if (a[mid] == x) {
			return mid;
		}
		else if (a[mid] > x) {
			return searchForX(a, x, l, mid - 1);
		}
		else
		{
			return searchForX(a, x, mid + 1, r);
		}
	}
	return -1;
}
