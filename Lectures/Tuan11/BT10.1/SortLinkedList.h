#pragma once

typedef struct singleNode {
	int data;
	singleNode* next;

} sNode;

typedef struct singleLinkedList {
	sNode* head;
	sNode* tail;
} sList;

bool isEmpty(sList list);

void init(sList& l);

sNode* getNode(int data);

bool addTail(sList& list, int data);

void inputASinglyList(sList& list, int n);

void outputASinglyList(sList list);

sNode* findMiddle(sList list);

void splitAList(sList l, sList& l1, sList& l2);

void mergeTwoSortedList(sList& l, sList l1, sList l2);

void mergeSort(sList& l);
