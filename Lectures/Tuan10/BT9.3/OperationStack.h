#pragma once

#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include "Stack.h"

using namespace std;

int priority(char operation);

int operations(int a, int b, char operation);

bool isDigit(char c);

int countValue(string expression);


