#pragma once

bool initArray(int*& a, int n);

void inputAnArray(int*& a, int& n);

void outputAnArray(int* a, int n);

void freeArray(int*& a);

int maxValue(int a, int b);

void findLongestSubsequence(int* a, int n, int*& L, int*& track, int*& res);
