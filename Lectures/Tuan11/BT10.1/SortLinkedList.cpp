#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include "SortLinkedList.h"

using namespace std;

bool isEmpty(sList list) {
	return (list.head == NULL);
}

void init(sList& l) {
	l.head = NULL;
	l.tail = NULL;
}

sNode* getNode(int data) {
	sNode* temp = (sNode*)calloc(1, sizeof(sNode));
	if (!temp) {
		return NULL;
	}
	temp->data = data;
	temp->next = NULL;
	return temp;
}

bool addTail(sList& list, int data) {
	sNode* toAdd = getNode(data);
	if (!toAdd) {
		return false;
	}
	if (isEmpty(list)) {
		list.head = toAdd;
		list.tail = toAdd;
		return true;
	}
	list.tail->next = toAdd;
	list.tail = toAdd;
	return true;
}

void inputASinglyList(sList& list, int n) {
	int data;
	scanf("%d", &data);
	sNode* temp = getNode(data);
	if (!temp) {
		return;
	}
	list.head = temp;
	list.tail = temp;
	for (int i = 1; i < n; i++) {
		scanf("%d", &data);
		addTail(list, data);
	}
}

void outputASinglyList(sList list) {
	sNode* head = list.head;
	for (sNode* p = head; p; p = p->next) {
		printf("%d ", p->data);
	}
	printf("\n");
}

sNode* findMiddle(sList list) {
	if (isEmpty(list)) {
		return NULL;
	}
	sNode* head = list.head;
	if (head->next == NULL) {
		return head;
	}
	sNode* slow = head;
	sNode* fast = head;
	while (fast->next && fast->next->next) {
		slow = slow->next;
		fast = (fast->next)->next;
	}
	return slow;
}

void splitAList(sList l, sList& l1, sList& l2) {
	if (isEmpty(l)||l.head->next == NULL) {
		return;
	}	
	sNode* middle = findMiddle(l);
	l1.head = l.head;
	l1.tail = middle;
	l2.head = middle->next;
	l2.tail = l.tail;
	l1.tail->next = NULL;
}
void mergeTwoSortedList(sList& l, sList l1, sList l2) {
	int data;
	if (isEmpty(l1) && isEmpty(l2)) {
		return;
	}
	else if (isEmpty(l1)) {
		data = l2.head->data;
		addTail(l, data);
		l2.head = l2.head->next;
		mergeTwoSortedList(l, l1, l2);
	} else if (isEmpty(l2)) {
		data = l1.head->data;
		addTail(l, data);
		l1.head = l1.head->next;
		mergeTwoSortedList(l, l1, l2);
	}
	else {
		if (l1.head->data <= l2.head->data) {
			data = l1.head->data;
			addTail(l, data);
			l1.head = l1.head->next;
		}
		else {
			data = l2.head->data;
			addTail(l, data);
			l2.head = l2.head->next;
		}
		mergeTwoSortedList(l, l1, l2);
	}
}

void mergeSort(sList& l) {
	sNode* head = l.head;
	if (head == NULL || head->next == NULL) {
		return;
	}
	sList l1, l2;
	splitAList(l, l1, l2);
	mergeSort(l1);
	mergeSort(l2);
	init(l);
	mergeTwoSortedList(l, l1, l2);
}
