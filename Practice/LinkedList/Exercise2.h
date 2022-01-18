#pragma once
#include "Exercise1.h"

bool getDataFromHead(sList list, int& value);

bool getDataFromTail(sList list, int& value);

bool getDataAtIth(sList list, int i, int& value);

int getLength(sList list);

sNode* findData(sList list, int data, int& cnt);
