#pragma once

#include <stdio.h>
#include <iostream>
#include "Stack.h"

void queens(int i, int n, int col[], int mainDiag[], int subDiag[], int& solNum, stackLL& s);