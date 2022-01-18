#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include "Recursion_Process.h"
#include "Recursion_ArrayProcess.h"

int main()
{
        FILE* fi = fopen("RecursionInput.txt", "r");

        int problem = 1;

        printf("Problem %d. ", problem++);
        int nFractionSum;
        fscanf(fi, "%d", &nFractionSum);
        printf("%f\n", fractionSum(nFractionSum));

        printf("Problem %d. ", problem++);
        long long nFactorial;
        fscanf(fi, "%lld", &nFactorial);
        printf("%lld\n", factorial(nFactorial));

        printf("Problem %d. ", problem++);
        double xPowerSum;
        int nPowerSum;
        fscanf(fi, "%lf%d", &xPowerSum, &nPowerSum);
        printf("%f\n", powerSum(xPowerSum, nPowerSum));

        printf("Problem %d. ", problem++);
        double xOddPowerSum;
        int nOddPowerSum;
        fscanf(fi, "%lf%d", &xOddPowerSum, &nOddPowerSum);
        printf("%f\n", oddPowerSum(xOddPowerSum, nOddPowerSum));

        printf("Problem %d. ", problem++);
        double xPowerAndFact;
        int nPowerAndFact;
        fscanf(fi, "%lf%d", &xPowerAndFact, &nPowerAndFact);
        printf("%f\n", powerAndFractorialSum(xPowerAndFact, nPowerAndFact));

        printf("Problem %d. ", problem++);
        int nSeriesNumber;
        fscanf(fi, "%d", &nSeriesNumber);
        printf("%lld\n", seriesNumber(nSeriesNumber));

        printf("Problem %d. ", problem++);
        int nDigitCount;
        fscanf(fi, "%d", &nDigitCount);
        printf("%d\n", digitCount(nDigitCount));

        printf("Problem %d. ", problem++);
        int nDigitSum;
        fscanf(fi, "%d", &nDigitSum);
        printf("%d\n", digitSum(nDigitSum));

        printf("Problem %d. ", problem++);
        int nOddDigitCount;
        fscanf(fi, "%d", &nOddDigitCount);
        printf("%d\n", oddDigitCount(nOddDigitCount));

        printf("Problem %d. ", problem++);
        int nIsAllEven;
        fscanf(fi, "%d", &nIsAllEven);
        if (isAllEven(nIsAllEven)) {
            printf("Yes.\n");
        }
        else {
            printf("No.\n");
        }

        printf("Problem %d. ", problem++);
        int nEvenSum;
        fscanf(fi, "%d", &nEvenSum);
        int* aEvenSum;
        if (!arrayInitAndInput(nEvenSum, aEvenSum, fi)) {
            printf("Error. Not enough memory.\n");
        }
        else {
            printf("%lld\n", evenSum(0, nEvenSum - 1, aEvenSum));
            free(aEvenSum);
        }


        printf("Problem %d. ", problem++);
        int nPrimeProduct;
        fscanf(fi, "%d", &nPrimeProduct);
        int* aPrimeProduct;
        if (!arrayInitAndInput(nPrimeProduct, aPrimeProduct, fi)) {
            printf("Error. Not enough memory.\n");
        }
        else {
            long long ans = primeProduct(0, nPrimeProduct - 1, aPrimeProduct);
            if (ans == 1) {
                printf("There is no prime numbers in the array.\n");
            }
            else
            {
                printf("%lld\n", ans);
            }
            free(aPrimeProduct);
        }
        
        printf("Problem %d. ", problem++);
        int nNegativeProduct;
        fscanf(fi, "%d", &nNegativeProduct);
        int* aNegativeProduct;
        if (!arrayInitAndInput(nNegativeProduct, aNegativeProduct, fi)) {
            printf("Error. Not enough memory.\n");
        }
        else {
            int cnt = 0;
            long long ans = negativeProduct(0, nNegativeProduct - 1, aNegativeProduct, cnt);
            if (cnt == 0) {
                printf("There is no negative numbers in the array.\n");
            }
            else {
                printf("%lld\n", ans);
            }
            free(aNegativeProduct);
        }

        printf("Problem %d. ", problem++);
        int nNegativeArray;
        fscanf(fi, "%d", &nNegativeArray);
        int* aNegativeArray;
        if (!arrayInitAndInput(nNegativeArray, aNegativeArray, fi)) {
            printf("Error. Not enough memory.\n");
        }
        else {
            if (isNegativeArray(0, nNegativeArray - 1, aNegativeArray)) {
                printf("Yes.\n");
            }
            else {
                printf("No.\n");
            }
            free(aNegativeArray);
        }
        
        printf("Problem %d. ", problem++);
        int nMaxArray;
        fscanf(fi, "%d", &nMaxArray);
        int* aMaxArray;
        if (!arrayInitAndInput(nMaxArray, aMaxArray, fi)) {
            printf("Error. Not enough memory.\n");
        }
        else {
            printf("%d\n", maxElement(0, nMaxArray - 1, aMaxArray));
            free(aMaxArray);
        }

        printf("Problem %d. ", problem++);
        int nFindX;
        fscanf(fi, "%d", &nFindX);
        int* aFindX;
        if (!arrayInitAndInput(nFindX, aFindX, fi)) {
            printf("Error. Not enough memory.\n");
        }
        else {
            int xToFind;
            fscanf(fi, "%d", &xToFind);
            printf("%d\n", countAnX(0, nFindX - 1, aFindX, xToFind));
            free(aFindX);
        }
        
        printf("Problem %d. ", problem++);
        int nCountPositive;
        fscanf(fi, "%d", &nCountPositive);
        int* aCountPosivite;
        if (!arrayInitAndInput(nCountPositive, aCountPosivite, fi)) {
            printf("Error. Not enough memory.\n");
        }
        else {
            printf("%d\n", countPositive(0, nCountPositive, aCountPosivite));
            free(aCountPosivite);
        }

        printf("Problem %d. ", problem++);
        int nCountDistinct;
        fscanf(fi, "%d", &nCountDistinct);
        int* aCountDistinct;
        if (!arrayInitAndInput(nCountDistinct, aCountDistinct, fi)) {
            printf("Error. Not enough memory.\n");
        }
        else {
            printf("%d\n", countDistinct(0, nCountDistinct - 1, aCountDistinct));
            free(aCountDistinct);
        }
        return 0;
}