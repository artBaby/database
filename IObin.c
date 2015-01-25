#include "IObin.h"
#include <malloc.h>


unsigned char *ReadBMP(FILE* file)
{	
	//FILE* file;					
	BMP_HEADER header;
	unsigned char* image;

	char *filename_c="flipped_by_C.bmp";
	char *filename_ASM="flipped_by_ASM.bmp";
	char *filename_MMX="flipped_by_MMX.bmp";

	image = NULL;
	//file=OpenF(filename);

	//if (!file) { printf("Error opening file\n"); return NULL; }

	header=GetHeader(file);

	if (header.signature[0] != 'B' && header.signature[1] != 'M')
	{
		printf("bad file structure! \n");
		fclose(file);
		return NULL;
	}

	if (header.bpp != 24)
	{
		printf("bpp!=24\n");
		fclose(file);
		return NULL;
	}

	image = (unsigned char*)malloc(header.bitmapLength);
	LoadBMPData(image, header.bitmapLength, file);
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

BMP_HEADER GetHeader(FILE *filename)
{
	BMP_HEADER header;
	fread(&header, sizeof(BMP_HEADER), 1, filename);
	return header;
}

void LoadBMPData(unsigned char *image, unsigned int size, FILE *filename)
{
	fread(image, sizeof(unsigned char), size, filename);
}


int SaveBMPData(char *filename, BMP_HEADER header, unsigned char *image)
{
	int s;
	FILE *file;
	file = fopen(filename, "w+b");
	if (file == NULL)
	{
		printf("Could not create new file \n");
		return 1;
	}
	s = fwrite(&header, sizeof(header), 1, file);
	if (s != 1)
	{
		fclose(file);
		printf("Could not write header to file \n");
		return 1;
	}

	s=fwrite(image, sizeof(unsigned char), header.bitmapLength, file);
	if (s != header.bitmapLength)
	{
		fclose(file);
		printf("Could not write data to file \n");
		return 1;
	}

	fclose(file);
	return 0;
}


	/*if (SaveBMPData(filename_c, header, c_image) != 0)
	{
		printf("ERROR on save \n");
	}
	else	
	printf("flipping image with mmx method... \n");
	printf("BMP saved to new file %s \n", filename_c);

	if (SaveBMPData(filename_ASM, header, c_image) != 0)
	{
		printf("ERROR on save \n");
	}

	else
	printf("BMP saved to new file %s \n", filename_ASM);
	printf("flipping image with mmx method... \n");

	flipHor(image, c_image, &header, &flipASM_MMX);
	if (SaveBMPData(filename_MMX, header, c_image) != 0)
	{
		printf("ERROR on save \n");
	}
	else	printf("BMP saved to new file %s \n", filename_MMX);

	free(image);
	free(c_image);
	printf("END \n");
	getchar();

	return 0;
}
*/
