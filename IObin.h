#ifndef IOBIN_H
#define IOBIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <windows.h>
//#include "main.h"
//typedef BMP_HEADER *HEADER;

#pragma pack(push, 1)

typedef struct
{
	char signature[2];
	unsigned int fileSize;
	unsigned short int reserved1;
	unsigned short int reserved2;
	unsigned int offset;
	unsigned int headerLength;
	unsigned int width;
	unsigned int height;
	short numLayers;
	short bpp;
	unsigned int compression;
	unsigned int bitmapLength;
	unsigned int horResolution;
	unsigned int verResolution;
	unsigned int numColors;
	unsigned int numMainColors;
} BMP_HEADER;

#pragma pack(pop)

int buferr;
int realwidth(int width);
FILE* OpenF(char *filename);
BMP_HEADER *GetHeader(FILE *filename);
void LoadBMPData(unsigned char *image, unsigned int size, FILE *filename);
int SaveBMPData(char *filename, BMP_HEADER *header, unsigned char *image);
unsigned char *ReadBMP(FILE *file, BMP_HEADER *header);

#endif // !IOBIN_H
