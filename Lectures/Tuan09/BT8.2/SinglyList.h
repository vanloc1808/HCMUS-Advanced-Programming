#pragma once

typedef struct singlyNode {
	int data;
	singlyNode* next;
} sNode;

typedef struct singlyList {
	sNode* head;
} sList;


