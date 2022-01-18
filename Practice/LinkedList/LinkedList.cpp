#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include "Exercise1.h"
#include "Exercise2.h"
#include "Exercise3.h"

using namespace std;

int main()
{
    FILE* fi = fopen("input.txt", "r");
    sNode* temp = NULL;
    char userChoice = 'y';
    do {
        int exerNumber = 0;
        printf("Please enter exercise number. Please view instruction file for more details.\n");
        scanf("%d", &exerNumber);
        if (exerNumber <= 0 || exerNumber >= 4) {
            printf("Invalid exercise number! Please try again.\n");
        }
        else if (exerNumber == 1) {
            sList list;
            int n = 0;
            inputAList(list, n, fi);
            int needToHead = 0;
            fscanf(fi, "%d", &needToHead);
            temp = addHead(list, needToHead);
            printf("After adding %d to head of list: ", needToHead);
            outputAList(list);
            int needToTail = 0;
            fscanf(fi, "%d", &needToTail);
            temp = addTail(list, needToTail);
            printf("After adding %d to tail of list: ", needToTail);
            outputAList(list);
            int iAdd = 0, toIth = 0;
            fscanf(fi, "%d%d", &toIth, &iAdd);
            addToIth(list, toIth, iAdd);
            printf("After adding %d to the position %d of list: ", toIth, iAdd);
            outputAList(list);
            int iRemove = 0;
            fscanf(fi, "%d", &iRemove);
            bool resRemove = removeTheIth(list, iRemove);
            if (!resRemove) {
                printf("Cannot remove the element of position %d", iRemove);
            }
            else {
                printf("After removing the element of position %d: ", iRemove);
                outputAList(list);
            }
            bool remove = removeAllElement(list);
            if (!remove) {
                printf("Cannot remove the list.\n");
            }
            else {
                printf("Removed the list.\n");
            }
        }
        else if (exerNumber == 2) {
            sList list;
            int n = 0;
            inputAList(list, n, fi);
            int ans = 0;
            if (!getDataFromHead(list, ans)) {
                printf("Empty list. Cannot get data\n");
            }
            else {
                printf("Data in head of list is: %d\n", ans);
            }
            if (!getDataFromTail(list, ans)) {
                printf("Empty list. Cannot get data\n");
            }
            else {
                printf("Data in tail of list is: %d\n", ans);
            }
            int i = 0;
            fscanf(fi, "%d", &i);
            if (!getDataAtIth(list, i, ans)) {
                printf("Cannot get data at position %d\n", i);
            }
            else {
                printf("Data at position %d is: %d\n", i, ans);
            }
            printf("The length of the list is %d\n", getLength(list));
            int data = 0;
            fscanf(fi, "%d", &data);
            int cnt = 0;
            sNode* res = findData(list, data, cnt);
            if (!res) {
                printf("Cannot find %d in list.\n", data);
            }
            else {
                printf("%d is found at position %d.\n", data, cnt);
            }

        }
        else if (exerNumber == 3) {
            sList list1, list2, listRes;
            int n1 = 0, n2 = 0;
            inputAList(list1, n1, fi);
            inputAList(list2, n2, fi);
            if (!combineTwoLists(list1, list2, listRes)) {
                printf("Both are empty. Cannot combine these two lists.\n");
            }
            else {
                printf("The list after combining: ");
                outputAList(listRes);
            }
        }
        printf("Do you want to continue? y for yes, n for no\n");
        scanf("\n");
        scanf("%c", &userChoice);
    } while (userChoice == 'y');
    fclose(fi);
    return 0;
}
