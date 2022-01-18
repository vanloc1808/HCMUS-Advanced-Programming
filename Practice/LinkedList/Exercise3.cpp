#include <stdio.h>
#include <iostream>
#include "Exercise3.h"

using namespace std;

bool combineTwoLists(sList list1, sList list2, sList& listRes) {
	if (isEmpty(list1) && isEmpty(list2)) {
		return false;
	}
	if (isEmpty(list1)) {
		listRes = list2;
		return true;
	}
	if (isEmpty(list2)) {
		listRes = list1;
		return true;
	}
	listRes = list1;
	listRes.tail->next = list2.head;
	listRes.tail = list2.tail;
	return true;
}