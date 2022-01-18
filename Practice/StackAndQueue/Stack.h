#pragma once

typedef struct singleNode {
	int data;
	singleNode* next;
} sNode;

struct Stack {
	sNode* top;
};

void initStack(Stack& s);

bool isStackEmpty(Stack s);

sNode* getNode(int value);

bool pushStack(Stack& s, int value);

bool popStack(Stack& s, int& value);

void inputAStack(Stack& s, int& n, FILE* fi);

void outputAStack(Stack& s, int n);
