#include <iostream>
#include <stdio.h>
#include "Bitmap.h"

using namespace std;

#define _CRT_SECURE_NO_WARNINGS

int main(int argc, char** argv)
{
	char* fileName = argv[1];
	BMP Bitmap;
	int padding = 0, height = 0, width = 0;
	int h, w;
	BMP** newBmp = NULL;
	if (argc == 6)
	{
		h = charToNumer(argv[3]);
		w = charToNumer(argv[5]);
	}
	else if (argc == 4 && strcmp(argv[2], "-h") == 0)
	{
		w = 1;
		h = charToNumer(argv[3]);
	}
	else
	{
		h = 1;
		w = charToNumer(argv[3]);
	}
	if (readBMP(fileName, Bitmap, padding, width, height) == false)
	{
		printf("Error.\n");
	}
	else
	{
		if (process(fileName, Bitmap, newBmp, h, w) == false)
		{
			printf("Error.");
		}
		else
		{
			printf("Success.\n");
		}
	}
	return 0;
}