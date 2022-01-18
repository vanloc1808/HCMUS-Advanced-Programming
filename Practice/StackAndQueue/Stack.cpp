#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include "Stack.h"

using namespace std;

void initStack(Stack& s) {
	s.top = NULL;
}

bool isStackEmpty(Stack s) {
	return (s.top == NULL);
}

sNode* getNode(int value) {
	sNode* res = (sNode*)calloc(1, sizeof(sNode));
	if (!res) {
		return NULL;
	}
	res->data = value;
	res->next = NULL;
	return res;
}

bool pushStack(Stack& s, int value) {
	sNode* toPush = getNode(value);
	if (!toPush){
		return false;
	}
	if (isStackEmpty(s)) {
		s.top = toPush;
		return true;
	}
	toPush->next = s.top;
	s.top = toPush;
	return true;
}

bool popStack(Stack& s, int& value) { //pop the value stored at s.top to the variable value
	if (isStackEmpty(s)) {
		return false; //cannot pop
	}
	sNode* top = s.top;
	value = s.top->data;
	s.top = top->next;
	free(top);
	return true;
}

void inputAStack(Stack& s, int& n, FILE* fi) {
	fscanf(fi, "%d", &n);
	for (int i = 0; i < n; i++) {
		int value;
		fscanf(fi, "%d", &value);
		pushStack(s, value);
	}
}

void outputAStack(Stack& s, int n) {
	int value = 0;
	if (isStackEmpty(s)) {
		printf("There are nothing in the stack.\n");
	}
	else {
		printf("The stack is: ");
		while (!isStackEmpty(s)) {
			popStack(s, value);
			printf("%d ", value);
		}
		printf("\n");
	}
}