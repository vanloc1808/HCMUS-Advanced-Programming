#pragma once
#include <stdio.h>
#include <iostream>

struct sNode {
	int data;
	sNode* next;
};

struct stackLL {
	sNode* top;
};

struct sCharNode {
	char data;
	sCharNode* next;
};

struct stackCharLL {
	sCharNode* top;
};

void init(stackLL& s);

bool isEmpty(stackLL s);

sNode* getNode(int data);

bool pushStack(stackLL& s, int data);

bool popStack(stackLL& s, int& value);

bool peekStack(stackLL& s, int data, int& value);


void initCharStack(stackCharLL& s);

bool isCharStackEmpty(stackCharLL s);

sCharNode* getCharNode(char data);

bool pushCharStack(stackCharLL& s, char data);

bool popCharStack(stackCharLL& s, char& value);

bool peekCharStack(stackCharLL& s, char& value);

