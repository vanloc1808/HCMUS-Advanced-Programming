#pragma pack(1)
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct BITMAPHEADER
{
	uint16_t signature;
	uint32_t fileSize;
	uint16_t reserved1;
	uint16_t reserved2;
	uint32_t pixelArrayByteOffset;
} BMPH;

typedef struct DIBFORMAT
{
	uint32_t DIBsize;
	uint32_t imageWidth;
	uint32_t imageHeight;
	uint16_t colorPlane;
	uint16_t colorDepth;
	uint32_t compressionAlgorithm;
	uint32_t pixelArraySize;
	uint32_t horizontalResolution;
	uint32_t verticalResolution;
	uint32_t numberOfColors;
	uint32_t numberOfImportantColors;
} DIBH;

typedef struct PIXEL
{
	unsigned char B;
	unsigned char G;
	unsigned char R;
};

typedef struct Bitmap
{
	BMPH Header;
	DIBH DIBHeader;
	PIXEL** pixelArray;
} BMP;

int charToNumer(char* str);

bool readBMP(char* fileName, BMP& Bitmap, int padding, int width, int height);

bool process(char* fileName, BMP Bitmap, BMP**& newBmp, int h, int w);
