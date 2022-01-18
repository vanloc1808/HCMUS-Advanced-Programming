#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include "Stack.h"
#include "Queue.h"

using namespace std;

int main()
{
    FILE* fi = fopen("input.txt", "r");
    int userChoice = 0;
    printf("Enter 1 for stack, 2 for queue.\n");
    scanf("%d", &userChoice);
    if (userChoice == 1) {
        Stack s;
        initStack(s);
        int n = 0;
        inputAStack(s, n, fi);
        outputAStack(s, n);
    } else if(userChoice == 2) {
        Queue q;
        initQueue(q);
        int n = 0;
        inputAQueue(q, n, fi);
        outputAQueue(q);
    }
    else {
        printf("Invalid mode.\n");
    }
}

