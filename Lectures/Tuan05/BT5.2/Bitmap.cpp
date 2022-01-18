#include "Bitmap.h"

int charToNumer(char* str)
{
	int len = strlen(str);
	int number = 0;
	for (int i = len - 1; i >= 0; i--)
	{
		number = 10 * number + str[i] - '0';
	}
	return number;
}

bool readBMP(char* fileName, BMP& Bitmap, int padding, int width, int height)
{
	FILE* f = fopen(fileName, "rb");
	if (!f)
	{
		printf("Error. Cannot open file.\n");
	}
	else
	{
		fseek(f, 0, SEEK_SET);
		fread(&Bitmap.Header, sizeof(BMPH), 1, f);
		fread(&Bitmap.DIBHeader, sizeof(DIBH), 1, f);
		padding = (Bitmap.DIBHeader.colorDepth) * (Bitmap.DIBHeader.imageWidth) / 8;
		padding %= 4;
		padding = (4 - padding) % 4;
		width = (Bitmap.DIBHeader.imageWidth) * (Bitmap.DIBHeader.colorDepth) / 8 + padding;
		height = Bitmap.DIBHeader.imageHeight;
		Bitmap.pixelArray = (PIXEL**)calloc(height, sizeof(PIXEL*));
		if (!(Bitmap.pixelArray))
		{
			printf("Error. Not enough memory/\n");
			return false;
		}
		else
		{
			Bitmap.pixelArray[0] = (PIXEL*)calloc(height * width, sizeof(PIXEL));
			if (!Bitmap.pixelArray[0])
			{
				printf("Error. Not enough memory.\n");
				return false;
			}
			else 
			{
				for (int i = 0; i < height; i++)
				{
					Bitmap.pixelArray[i] = Bitmap.pixelArray[0] + i * width;

				}
				for (int i = 0; i < height; i++)
				{
					fread(Bitmap.pixelArray[i], sizeof(PIXEL), width, f);
				}
			}

		}
		fclose(f);
		return true;
	}
}

bool process(char* fileName, BMP Bitmap,  BMP**& newBmp, int h, int w)
{
	FILE* f = fopen(fileName, "rb");
	if (!f)
	{
		printf("Error. Cannot open file.\n");
		return false;
	}
	else
	{
		newBmp = (BMP**)calloc(h, sizeof(BMP*));
		for (int i = 0; i < h; i++)
		{
			newBmp[i] = (BMP*)calloc(w, sizeof(BMP));
		}
		fseek(f, 54, SEEK_SET);
		/*int padding = (Bitmap.DIBHeader.colorDepth) * (Bitmap.DIBHeader.imageWidth) / 8;
		padding %= 4;
		padding = (4 - padding) % 4;
		int newWidth = (Bitmap.DIBHeader.imageWidth) * (Bitmap.DIBHeader.colorDepth) / 8 + padding;*/
		int x = Bitmap.DIBHeader.imageWidth / w, rx = Bitmap.DIBHeader.imageWidth % w;
		int y = Bitmap.DIBHeader.imageHeight / h, ry = Bitmap.DIBHeader.imageHeight % h;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				
				char *newName = (char*)calloc(strlen(fileName)+7,sizeof(char)), id[10];
				for (int i = 0; i < strlen(fileName) - 4; i++)
				{
					newName[i] = fileName[i];
				}
				sprintf(id, "%d.bmp", i * w + j);
				strcat(newName, id);

				FILE* newFile = fopen(newName, "wb");
				if (!newFile)
				{
					return false;
				}
				else
				{
					newBmp[i][j].Header = Bitmap.Header;
					newBmp[i][j].DIBHeader = Bitmap.DIBHeader;
					newBmp[i][j].DIBHeader.imageHeight = y;
					newBmp[i][j].DIBHeader.imageWidth = x;
					int rowSize = ((3 * x + 3) / 4 )* 4;
					newBmp[i][j].DIBHeader.pixelArraySize = rowSize * y;
					newBmp[i][j].Header.fileSize = newBmp[i][j].DIBHeader.pixelArraySize + 54;
					newBmp[i][j].pixelArray = (PIXEL**)calloc(y, sizeof(PIXEL*));
					fwrite(&newBmp[i][j].Header, sizeof(BMPH), 1, newFile);
					fwrite(&newBmp[i][j].DIBHeader, sizeof(DIBH), 1, newFile);
					if (!newBmp[i][j].pixelArray)
					{
						return false;
					}
					else
					{
						newBmp[i][j].pixelArray[0] = (PIXEL*)calloc(x * y, sizeof(PIXEL));
						if (!newBmp[i][j].pixelArray[0])
						{
							free(newBmp[i][j].pixelArray);
							return false;
						}
						else
						{
							uint8_t unused = 0;
							for (int k = 1; k < y; k++)
							{
								newBmp[i][j].pixelArray[k] = newBmp[i][j].pixelArray[0] + k * x;
							}
							for (int k = 0; k < h; k++)
							{
								for (int l = 0; l < w; l++)
								{
									newBmp[i][j].pixelArray[k][l] = Bitmap.pixelArray[i*x+k][j*y+l];
								}
							}
							for (int k = 0; k < y; k++)
							{
								fwrite(&newBmp[i][j].pixelArray[k], sizeof(PIXEL), x, newFile);
								fwrite(&unused, 1, rowSize - 3 * x, f);
							}
							free(newBmp[i][j].pixelArray[0]);
						}
						
					}
					fclose(newFile);
					free(newName);
				}

			}
		}
		fclose(f);
		return true;
	}
}

