#pragma once

typedef struct doublyNode {
	int data;
	doublyNode* next;
	doublyNode* prev;
} dNode;

typedef struct doublyList {
	dNode* head;
	dNode* tail;
} dList;

void initDoublyList(dList& List);

bool checkEmptyDList(dList List);

dNode* findTheIthDList(dList List, int i);

dNode* findTheDataXDList(dList List, int x);

dNode* findTheTailDList(dList List);

dNode* getNodeDList(int data);

void addToHeadDList(dList& List, int data);

void addToTailDList(dList& List, int data);

void addToIthDList(dList& List, int data, int i);

void removeHeadDList(dList& List);

void removeTailDList(dList& List);

void removeTheIthDList(dList& List, int i);

void removeTheDataXDList(dList& List, int data);
