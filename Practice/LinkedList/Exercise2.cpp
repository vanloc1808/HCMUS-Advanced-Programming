#include <stdio.h>
#include <iostream>
#include "Exercise2.h"

using namespace std;

bool getDataFromHead(sList list, int& value) {
	if (isEmpty(list)) {
		return false;
	}
	value = list.head->data;
	return true;
}

bool getDataFromTail(sList list, int& value) {
	if (isEmpty(list)) {
		return false;
	}
	value = list.tail->data;
	return true;
}

bool getDataAtIth(sList list, int i, int& value) {
	if (isEmpty(list)) {
		return false;
	}
	sNode* res = findTheIth(list, i);
	if (!res) {
		return false;
	}
	value = res->data;
	return true;
}

int getLength(sList list) {
	if(isEmpty(list)) {
		return 0;
	}
	if (list.head == list.tail) {
		return 1;
	}
	int cnt = 0;
	for (sNode* p = list.head; p; p = p->next) {
		cnt++;
	}
	return cnt;
}

sNode* findData(sList list, int data, int& cnt) {
	if (isEmpty(list)) {
		return NULL;
	}
	cnt = 0;
	for (sNode* p = list.head; p; p = p->next) {
		if (p->data == data) {
			return p;
		}
		cnt++;
	}
	return NULL;
}