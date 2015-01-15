#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <stdint.h>
#include <malloc.h>
#include <string.h>

#include "treap.h"

#define MAX_STR_LENGTH ( 512 )

typedef enum types
{
	string_data,		//строковые данные
	number_data,		//число
	binary_data,		//бинарные данные

} data_type_t;




typedef struct {

	size_t key_length;  //длина ключа (4 байт)
	char* key;			//сам ключ
	data_type_t type;	//тип хранимых данных
	size_t data_length;	//длина данных (4 байт)
	void* data;			//данные

} kvp_t;

void add_input(void) {
    char c;
    while ( scanf("%c", &c) == 1 && c!= '\n' )
		//get symbols
        ;
}

char *get_str(char *str) {
    char *enter = strrchr(str, '\n');
    if (enter)
        *enter = '\0';
    return str;
}

// CRUD:
// CREATE READ UPDATE DELETE

int main(int argc, char *argv[])
{
	char operation[7];
	char key[256];
	char input_value[256];
	char *input;
	int loop = 1;
	int i;
	char buffer[MAX_STR_LENGTH];

	printf("Proposed operations:\nCreate\tRead\tUpdate\tDelete\nExample of query: create \"mykey\" \"myvalue\"\n");
	
	while (loop)
	{
		
		/*
		create "mykey" "my value"
		create "something" 42
		update "something" 49
		
		для бинарных данных:
		createbin "somethingfromfile" "c:/hello.bmp"
		writebin "somethingfromfile" "c:/hello_from_base.bmp"
		*/

		if ( ! fgets(buffer, MAX_STR_LENGTH, stdin) )
					{
						fprintf(stderr, "Невозможно считать строку\n");
						system("pause");
						return 1;
					}
		
		if ( ! ( input = _strdup(get_str(buffer)) ) ) 
					{
						fprintf(stderr, "Ошибка памяти\n");
						system("pause");
						return 1;
					}

		printf("%s\n", input);
		


		if ( !strcmp(operation, "create") ) 
		{
			//create operations
			
		}

		if (!strcmp(operation, "read"))
		{
			//read operations
		}

		if (operation == "update")
		{
			//update operations
		}
	
		if (operation == "delete")
		{
			//delete operations
		}
		
	}
	system("pause");
}



