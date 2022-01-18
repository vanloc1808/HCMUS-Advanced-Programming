#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include "Exercise1.h"

using namespace std;


sNode* getNode(int data) {
    sNode* res = (sNode*)calloc(1, sizeof(sNode));
    if (!res) {
        return NULL;
    }
    res->data = data;
    res->next = NULL;
    return res;
}

void inputAList(sList& list, int& n, FILE* fi) {
    fscanf(fi, "%d", &n);
    int temp;
    fscanf(fi, "%d", &temp);
    init(list);
    addHead(list, temp);
    list.tail = list.head;
    for (int i = 1; i < n; i++) {
        fscanf(fi, "%d", &temp);
        addTail(list, temp);
    }
}

void outputAList(sList list) {
    for (sNode* p = list.head; p; p = p->next) {
        printf("%d ", p->data);
    }
    printf("\n");
}

void init(sList& list) {
    list.head = NULL;
    list.tail = NULL;
}

bool isEmpty(sList list) {
    return (list.head == NULL);
}

sNode* findTheIth(sList list, int i) {
    if (isEmpty(list)) {
        return NULL;
    }
    if (i == 0) {
        return list.head;
    }
    int cnt = 0;
    sNode* res = list.head;
    while (res->next && cnt < i) {
        res = res->next;
        cnt++;
    }
    if (cnt < i) {
        return NULL;
    }
    return res;
}

sNode* addHead(sList& list, int data) {
    sNode* temp = getNode(data);
    if (isEmpty(list)) {
        list.head = list.tail = temp;
        return list.head;
    }
    temp->next = list.head;
    list.head = temp;
    return list.head;
}

sNode* addTail(sList& list, int data) {
    sNode* temp = getNode(data);
    if (isEmpty(list)) {
        list.head = list.tail = temp;
        return list.tail;
    }
    list.tail->next = temp;
    list.tail = temp;
    return list.tail;
}

sNode* addToIth(sList& list, int data, int i) {
    if (i == 0) {
        addHead(list, data);
        return list.head;
    }
    sNode* temp = getNode(data);
    sNode* formerIth = findTheIth(list, i);
    sNode* preOfIth = findTheIth(list, i - 1);
    preOfIth->next = temp;
    temp->next = formerIth;
    return temp;
}

bool removeHead(sList& list) {
    if (isEmpty(list)) {
        return false;
    }
    sNode* head = list.head;
    list.head = head->next;
    free(head);
    return true;
}

bool removeTail(sList& list) {
    if (isEmpty(list)) {
        return false;
    }
    if (list.head == list.tail) {
        free(list.head);
        return true;
    }
    sNode* tail = list.tail;
    sNode* p = NULL;
    for (p = list.head; p->next != tail; p = p->next);
    list.tail = p;
    free(tail);
    return true;
}

bool removeTheIth(sList& list, int i) {
    if (isEmpty(list)) {
        return false;
    }
    if (i == 0) {
        bool res = removeHead(list);
        return res;
    }
    sNode* toRemove = findTheIth(list, i);
    if (toRemove == list.tail) {
        bool res = removeTail(list);
        return res;
    }
    sNode* pre = findTheIth(list, i - 1);
    sNode* next = toRemove->next;
    pre->next = next;
    free(toRemove);
    return true;
}

bool removeAllElement(sList& list) {
    if (isEmpty(list)) {
        return false;
    }
    sNode* p = list.head;
    while (p) {
        sNode* temp = p;
        p = p->next;
        free(temp);
    }
    return true;
}