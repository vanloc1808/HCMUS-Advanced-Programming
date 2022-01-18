#include <stdio.h>
#include <iostream>
#include "SinglyList.h"

using namespace std;

bool checkEmptySList(sList List) {
	return (List.head == NULL);
}

sNode* findTailSList(sList List) {
    sNode* temp = List.head;
    if (!temp) {
        return NULL;
    }
    while (temp->next) {
        temp = temp->next;
    }
    return temp;
}

int countNodeSList(sList List) {
    if (checkEmptySList(List)) {
        return 0;
    }
    int cnt = 0;
    sNode* head = List.head;
    for (sNode* p = head; p; p = p->next) {
        cnt++;
    }
    return cnt;
}

void reverseSList(sList& List) {
    sNode* prev = NULL;
    sNode* current = List.head;
    sNode* next = NULL;
    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    List.head = prev;
}

sNode* getNodeSList(int data) {
    sNode* res = (sNode*)calloc(1, sizeof(sNode));
    if (!res) {
        return NULL;
    }
    res->data = data;
    res->next = NULL;
}

void addHeadSList(sList& List, int data) {
    if (checkEmptySList(List)) {
        return;
    }
    sNode* temp = getNodeSList(data);
    sNode* formerHead = List.head;
    temp->next = formerHead;
    List.head = temp;
}

void addTailSList(sList& List, int data) {
    if (checkEmptySList(List)) {
        return;
    }
    sNode* temp = getNodeSList(data);
    sNode* formerTail = findTailSList(List);
    if (List.head == formerTail) {
        addHeadSList(List, data);
        return;
    }
    formerTail->next = temp;
}

sNode* findTheIthSList(sList List, int i) {
    sNode* temp = List.head;
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

void addTheIthSList(sList& List, int data, int i) {
    sNode* temp = getNodeSList(data);
    sNode* formerIth = findTheIthSList(List, i);
    if (!formerIth) {
        return;
    }
    if (formerIth == List.head) {
        addHeadSList(List, data);
        return;
    }
    if (formerIth == findTailSList(List)) {
        addTailSList(List, data);
        return;
    }
    sNode* formerPrev = findTheIthSList(List, i - 1);
    formerPrev->next = temp;
    temp->next = formerIth;
}

void addKeepOrderSList(sList& List, int data) {
    if (checkEmptySList(List)) {
        return;
    }
    sNode* temp = getNodeSList(data);
    if (data <= List.head->data) {
        addHeadSList(List, data);
        return;
    }
    sNode* tail = findTailSList(List);
    if (data >= tail->data) {
        addTailSList(List, data);
        return;
    }
    int cnt = 0;
    sNode* temp = List.head;
    while (temp != NULL) {
        if (temp->data > data) {
            break;
        }
        cnt++;
        temp = temp->next;
    }
    addTheIthSList(List, data, cnt);
}