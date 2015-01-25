#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <stdint.h>
#include <malloc.h>
#include <string.h>
#include <time.h>
#include "pars.h"
#include "IObin.h"

#define MAX_STR_LENGTH ( 1024 )

typedef enum types
{
	string_data = 1,		//строковые данные
	number_data = 2,		//число
	binary_data = 3,		//бинарные данные
} data_type_t;

typedef BMP_HEADER* HEADER;

typedef struct 
{
	HEADER head;
	size_t key_length;  //длина ключа (4 байт)
	char* key;			//сам ключ
	data_type_t type;	//тип хранимых данных
	size_t data_length;	//длина данных (4 байт)
	void* data;			//данные
} kvp_t;

/*
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
*/

#endif
