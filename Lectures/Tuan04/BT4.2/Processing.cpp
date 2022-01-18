#include <iostream>
#include "Processing.h"
#include "Status.h"

using namespace std;

bool copyFile(char* src, char* dest)
{
	FILE* f1 = fopen(src, "rb");
	FILE* f2 = fopen(dest, "wb");
	if (!f1 || !f2)
	{
		fileErNoti();
		return false;
	}
	int nob;
	do
	{
		char x;
		nob = fread(&x, 1, 1, f1);
		fwrite(&x, 1, 1, f2);
	} while (nob == 1);
	fclose(f1);
	fclose(f2);
	return true;
}

bool combineFile(char* src1, char* src2, char* dest)
{
	FILE* fsrc1 = fopen(src1, "rb");
	FILE* fsrc2 = fopen(src2, "rb");
	FILE* fdest = fopen(dest, "wb");
	if (!fsrc1 || !fsrc2 || !fdest)
	{
		fileErNoti();
		return false;
	}

	int nob;
	do
	{
		char x;
		nob = fread(&x, 1, 1, fsrc1);
		fwrite(&x, 1, 1, fdest);
	} while (nob == 1);
	do
	{
		char x;
		nob = fread(&x, 1, 1, fsrc2);
		fwrite(&x, 1, 1, fdest);
	} while (nob == 1);
	fclose(fsrc1);
	fclose(fsrc2);
	fclose(fdest);
	return true;
}

void showInstruction()
{
	cout << "-------- This is the program to copy/combine file. --------\n";
	cout << "If you want to copy and have another name, the syntax is: copy <source file> <destination file>.\n";
	cout << "If you want to copy and remain the same name, the syntax is: copy <source file> <path> \\ (The path must NOT contain a space)" << "\n";
	cout << "If you want to combine two files, the syntax is: copy <source file 1> + <source file 2> <destination file>\n";
	cout << "If you want to show instructions, the syntax is: copy /?\n";
	cout << "------------------ Thank you------------------ \n";
}

