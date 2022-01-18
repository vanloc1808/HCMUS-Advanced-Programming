#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include "Queue.h"

using namespace std;

void initQueue(Queue& q) {
	q.head = NULL;
	q.tail = NULL;
}

bool isQueueEmpty(Queue q) {
	return (q.head == NULL);
}

bool enqueue(Queue& q, int value) {
	sNode* toEnqueue = getNode(value);
	if (!toEnqueue) {
		return false;
	}
	if (isQueueEmpty(q)) {
		q.head = toEnqueue;
		q.tail = q.head;
		return true;
	}
	q.tail->next = toEnqueue;
	q.tail = toEnqueue;
	return true;
}

bool dequeue(Queue& q, int& value) {
	if (isQueueEmpty(q)) {
		return false;
	}
	sNode* head = q.head;
	value = head->data;
	q.head = head->next;
	free(head);
}

void inputAQueue(Queue& q, int& n, FILE* fi) {
	fscanf(fi, "%d", &n);
	for (int i = 0; i < n; i++)
	{
		int value = 0;
		fscanf(fi, "%d", &value);
		enqueue(q, value);
	}
}

void outputAQueue(Queue q) {
	int value = 0;
	if (isQueueEmpty(q)) {
		printf("There are nothing in the queue.\n");
	}
	else {
		printf("The queue is: ");
		while (!isQueueEmpty(q)) {
			dequeue(q, value);
			printf("%d ", value);
		}
		printf("\n");
	}
}