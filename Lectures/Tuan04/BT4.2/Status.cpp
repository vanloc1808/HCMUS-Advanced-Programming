#include <iostream>
#include "Status.h"

using namespace std;

void noInpNoti()
{
	cout << "Error. No input argument.";
}

void errorNoti()
{
	cout << "Invalid argument.\n";
}

void fileErNoti()
{
	cout << "Error. Cannot open file.\n";
}

void statusNoti(bool check)
{
	if (check)
	{
		cout << "Succeeded.\n";
	}
	else
	{
		cout << "Failed.\n";
	}
}