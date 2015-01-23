#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <stdint.h>
#include <malloc.h>
#include <string.h>
#include <time.h>

#define MAX_STR_LENGTH ( 512 )

typedef enum types
{
	string_data = 1,		//строковые данные
	number_data = 2,		//число
	binary_data = 3,		//бинарные данные
} data_type_t;

typedef struct 
{
	size_t key_length;  //длина ключа (4 байт)
	char* key;			//сам ключ
	data_type_t type;	//тип хранимых данных
	size_t data_length;	//длина данных (4 байт)
	void* data;			//данные
} kvp_t;

void add_input(void);
int ident_str(char *str);
char *get_str(char *str);

#endif
