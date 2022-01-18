#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include "DoublyList.h"

using namespace std;

void initDoublyList(dList& List) {
	List.head = NULL;
	List.tail = NULL;
}

bool checkEmptyDList(dList List) {
	return (List.head == NULL);
}

dNode* findTheIthDList(dList List, int i) {
	if (List.head == NULL) {
		return NULL;
	}
	dNode* temp = List.head;
	int cnt = 0;
	while (temp != NULL && cnt < i) {
		temp = temp->next;
		cnt++;
	}
	if (!temp) {
		return NULL;
	}
	return temp;
}

dNode* findTheDataXDList(dList List, int x) {
	if (List.head == NULL) {
		return NULL;
	}
	dNode* temp = List.head;
	while (temp) {
		if (temp->data == x) {
			return temp;
		}
		temp = temp->next;
	}
	return NULL;
}

dNode* findTheTailDList(dList List) {
	if (List.head == NULL) {
		return NULL;
	}
	return List.tail;
}

dNode* getNodeDList(int data) {
	dNode* res = (dNode*)calloc(1, sizeof(dNode));
	if (!res) {
		return NULL;
	}
	res->data = data;
	res->next = NULL;
	res->prev = NULL;
	return res;
}

void addToHeadDList(dList& List, int data) {
	if (checkEmptyDList(List)) {
		return;
	}
	dNode* temp = getNodeDList(data);
	dNode* formerHead = List.head;
	temp->next = formerHead;
	formerHead->prev = temp;
	List.head = temp;
}

void addToTailDList(dList& List, int data) {
	if (checkEmptyDList(List)) {
		return;
	}
	dNode* temp = getNodeDList(data);
	dNode* formerTail = List.tail;
	formerTail->next = temp;
	temp->prev = formerTail;
	List.tail = temp;
}

void addToIthDList(dList& List, int data, int i) {
	if (checkEmptyDList(List)) {
		return;
	}
	dNode* temp = getNodeDList(data);
	dNode* formerIth = findTheIthDList(List, i);
	if (!formerIth) {
		return;
	}
	if (formerIth == List.head) {
		addToHeadDList(List, data);
		return;
	}
	if (formerIth == List.tail) {
		addToTailDList(List, data);
		return;
	}
	temp->prev = formerIth->prev;
	temp->next = formerIth;
	formerIth->prev = temp;
}

void removeHeadDList(dList& List) {
	if (List.head == NULL) {
		return;
	}
	if (List.head == List.tail) {
		free(List.head);
		List.head = NULL;
		return;
	}
	dNode* head = List.head;
	List.head = head->next;
	free(head);
}

void removeTailDList(dList& List) {
	if (List.head == NULL) {
		return;
	} 
	if (List.head == List.tail) {
		free(List.head);
		List.head = NULL;
		return;
	}
	dNode* tail = List.tail;
	List.tail = tail->prev;
	free(tail);
}

void removeTheIthDList(dList& List, int i) {
	if (List.head == NULL) {
		return;
	}
	dNode* toRemove = findTheIthDList(List, i);
	if (!toRemove) {
		return;
	}
	if (toRemove == List.head) {
		removeHeadDList(List);
	}
	else if (toRemove == List.tail) {
		removeTailDList(List);
	}
	else {
		dNode* tempPrev = toRemove->prev;
		dNode* tempNext = toRemove->next;
		tempPrev->next = tempNext;
		tempNext->prev = tempPrev;
		free(toRemove);
	}
}

void removeTheDataXDList(dList& List, int data) {
	if (List.head == NULL) {
		return;
	}
	dNode* toRemove = findTheDataXDList(List, data);
	if (!toRemove) {
		return;
	}
	if (toRemove == List.head) {
		removeHeadDList(List);
	}
	else if (toRemove == List.tail) {
		removeTailDList(List);
	}
	else {
		dNode* tempPrev = toRemove->prev;
		dNode* tempNext = toRemove->next;
		tempPrev->next = tempNext;
		tempNext->prev = tempPrev;
		free(toRemove);
	}
}