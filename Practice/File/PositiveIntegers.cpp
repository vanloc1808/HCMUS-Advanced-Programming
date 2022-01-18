#include "PositiveIntegers.h"

bool isPrime(int n)
{
	if (n == 1)
	{
		return false;
	}
	else if (n == 2 || n == 3)
	{
		return true;
	}
	else
	{
		for (int i = 2; i <= sqrt(n); i++)
		{
			if (n % i == 0)
			{
				return false;
			}
		}
		return true;
	}

}

void binaryToConsolePI(FILE* fsub)
{
	int n;
	int nob;
	do
	{
		nob = fread(&n, sizeof(int), 1, fsub);
		printf("%d ", n);
	} while (nob == 1);
}


void processPosInt(FILE* fi, FILE* fo)
{
	int m, n;
	fscanf(fi, "%d%d", &m, &n);
	for (int i = m; i <= n; i++)
	{
		if (isPrime(i))
		{
			fwrite(&i, sizeof(int), 1, fo);
		}
		
	}

}