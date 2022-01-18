#pragma once

bool arrayInitAndInput(int n, int*& a, FILE* fi);

long long evenSum(int left, int right, int* a);

bool isPrime(int n);

long long primeProduct(int left, int right, int* a);

long long negativeProduct(int left, int right, int* a, int& cnt);

bool isNegativeArray(int left, int right, int* a);

int maxElement(int left, int right, int* a);

int countAnX(int left, int right, int* a, int x);

int countPositive(int left, int right, int* a);

int countDistinct(int left, int right, int* a);