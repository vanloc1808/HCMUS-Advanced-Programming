#include <iostream>
#include "Processing.h"
#include "Status.h"

using namespace std;



int main(int argc, char** argv)
{
	bool check = false;
	if (argc == 1)
	{
		noInpNoti();
	}
	else if (argc == 3)
	{
		if (argv[2][strlen(argv[2]) - 1] == '\\')
		{
			for (int i = 0; i < strlen(argv[2]); i++)
			{
				if (argv[2][i] == '\\')
				{
					argv[2][i] = '/';
				}
			}
			char dest[1000];
			strcpy(dest, argv[2]);
			strcat(dest, argv[1]);
			check = copyFile(argv[1], dest);
		}
		else
		{
			check = copyFile(argv[1], argv[2]);
		}
	}
	else if (argc == 2)
	{
		char c[] = "/?";
		if (strcmp(argv[1], c) == 0)
		{
			showInstruction();
			check = true;
		}
		else
		{
			errorNoti();
		}			
	}
	else if (argc == 5)
	{
		if (strcmp(argv[2], "+") == 0)
		{
			check = combineFile(argv[1], argv[3], argv[4]);
		}
		else
		{
			errorNoti();
		}
	}
	else
	{
		errorNoti();
	}
	statusNoti(check);
	return 0;
}