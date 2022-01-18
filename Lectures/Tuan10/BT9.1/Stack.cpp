#include "Stack.h"


using namespace std;

void init(stackLL& s) {
	s.top = NULL;
}

bool isEmpty(stackLL s) {
	return (s.top == NULL);
}

sNode* getNode(int data) {
	sNode* res = (sNode*)calloc(1, sizeof(sNode));
	if (!res) {
		return NULL;
	}
	res->data = data;
	res->next = NULL;
	return res;
}

bool pushStack(stackLL& s, int data) {
	sNode* temp = getNode(data);
	if (!temp) {
		return false;
	}
	if (isEmpty(s)) {
		s.top = temp;
		return true;
	}
	temp->next = s.top;
	s.top = temp;
	return true;
}

bool popStack(stackLL& s, int& value) {
	if (isEmpty(s)) {
		return false;
	}
	sNode* top = s.top;
	value = s.top->data;
	s.top = top->next;
	free(top);
	return true;
}

bool peekStack(stackLL& s, int data, int& value) {
	if(isEmpty(s)) {
		return false;
	}
	sNode* top = s.top;
	value = top->data;
	return true;
}

void initCharStack(stackCharLL& s) {
	s.top = NULL;
}

bool isCharStackEmpty(stackCharLL s) {
	return (s.top == NULL);
}

sCharNode* getCharNode(char data) {
	sCharNode* res = (sCharNode*)calloc(1, sizeof(sCharNode));
	if (!res) {
		return NULL;
	}
	res->data = data;
	res->next = NULL;
	return res;
}

bool pushCharStack(stackCharLL& s, char data) {
	sCharNode* temp = getCharNode(data);
	if (!temp) {
		return false;
	}
	if (isCharStackEmpty(s)) {
		s.top = temp;
		return true;
	}
	temp->next = s.top;
	s.top = temp;
	return true;
}

bool popCharStack(stackCharLL& s, char& value) {
	if (isCharStackEmpty(s)) {
		return false;
	}
	sCharNode* top = s.top;
	value = top->data;
	s.top = top->next;
	free(top);
	return true;
}

bool peekCharStack(stackCharLL& s, char& value) {
	if (isCharStackEmpty(s)) {
		return false;
	}
	sCharNode* top = s.top;
	value = top->data;
	return true;
}