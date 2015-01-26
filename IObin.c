#include "IObin.h"
#include <malloc.h>


unsigned char *ReadBMP(FILE* file, BMP_HEADER *header)
{	
	//FILE* file;					
	//BMP_HEADER header;
	BMP_HEADER *head = header;
	unsigned char* image;
	char *filename_c="flipped_by_C.bmp";
	char *filename_ASM="flipped_by_ASM.bmp";
	char *filename_MMX="flipped_by_MMX.bmp";
	image = NULL;

	//file=OpenF(filename);

	//if (!file) { printf("Error opening file\n"); return NULL; }

	//head=GetHeader(file);

	/*if (head->signature[0] != 'B' && head->signature[1] != 'M')
	{
		printf("bad file structure! \n");
		fclose(file);
		return NULL;
	}

	if (head->bpp != 24)
	{
		printf("bpp!=24\n");
		fclose(file);
		return NULL;
	}*/

	image = (unsigned char*)malloc(head->bitmapLength);
	LoadBMPData(image, head->bitmapLength, file);
	return image;

}

FILE* OpenF(char *filename)
{
	FILE *file;
	printf("open filename =  %s \n", filename);	
	file = fopen(filename, "r+b");
	if (file == NULL)
	{
		printf("Could not open file \n");
		
		return NULL;
	}
	return file;
}

BMP_HEADER *GetHeader(FILE *file)
{
	//BMP_HEADER header;
	BMP_HEADER *head;

	if ( ! (head = (BMP_HEADER *)malloc(sizeof(BMP_HEADER))) )
		{
			printf("Allocating error\n");
			return NULL;
	}
	fread(head, sizeof(BMP_HEADER), 1, file);
	if (head->signature[0] != 'B' && head->signature[1] != 'M')
	{
		printf("bad file structure! \n");
		fclose(file);
		return NULL;
	}

	if (head->bpp != 24)
	{
		printf("bpp!=24\n");
		fclose(file);
		return NULL;
	}
	
	printf("width %u", head->width);
	return head;
}

void LoadBMPData(unsigned char *image, unsigned int size, FILE *filename)
{
	fread(image, sizeof(unsigned char), size, filename);
}


int SaveBMPData(char *filename, BMP_HEADER *header, unsigned char *image)
{
	int s;
	FILE *file;
	file = fopen(filename, "w+b");
	if (file == NULL)
	{
		printf("Could not create new file \n");
		return 1;
	}
	s = fwrite(header, sizeof(BMP_HEADER), 1, file);
	if (s != 1)
	{
		fclose(file);
		printf("Could not write header to file \n");
		return 1;
	}

	s=fwrite(image, sizeof(unsigned char), header->bitmapLength, file);
	if (s != header->bitmapLength)
	{
		fclose(file);
		printf("Could not write data to file \n");
		return 1;
	}

	fclose(file);
	return 0;
}
