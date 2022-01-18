#pragma once

#include "Stack.h"

struct Queue {
	sNode* head;
	sNode* tail;
};

void initQueue(Queue& q);

bool isQueueEmpty(Queue q);

bool enqueue(Queue& q, int value);

bool dequeue(Queue& q, int& value);

void inputAQueue(Queue& q, int& n, FILE* fi);

void outputAQueue(Queue q);
