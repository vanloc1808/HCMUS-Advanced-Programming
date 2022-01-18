#pragma once

struct sNode {
    int data;
    sNode* next;
};

struct sList {
    sNode* head;
    sNode* tail;
};

sNode* getNode(int data);


void inputAList(sList& list, int& n, FILE* fi);

void outputAList(sList list);

void init(sList& list);

bool isEmpty(sList list);

sNode* findTheIth(sList list, int i);

sNode* addHead(sList& list, int data);

sNode* addTail(sList& list, int data);

sNode* addToIth(sList& list, int data, int i);

bool removeHead(sList& list);

bool removeTail(sList& list);

bool removeTheIth(sList& list, int i);

bool removeAllElement(sList& list);