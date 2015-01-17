#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <stdint.h>
#include <malloc.h>
#include <string.h>



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
//	data_type_t type;	//тип хранимых данных
	size_t data_length;	//длина данных (4 байт)
	void* data;			//данные

} kvp_t;

#include "treap.h"

void add_input(void) {
    char c;
	int count_quot;
	count_quot = 0;
    while ( scanf("%c", &c) == 1 /*&& c!= '\n'*/ ) {
		if ( c == '\"') count_quot++;
		if ( count_quot == 4) break;
	}  
}

int ident_str(char *str) {
	int i, count;
	count = 0;
	
	for (i = 0; i < strlen(str); ++i)
	{
		if (str[i] == '\"')
			count++;
		
	}
	if (count == 2) return 2;		//2 " - means that value is a num
	else if (count == 4) return 4;	//4 " - means that value is a str or bin_dat
	else if (count == 3) return 3;
	else return count;					//other - syntax error
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
	/*pointer for struct*/
	kvp_t *database;
	char *operation;
	char *key;
	char *value;
	char *input;
	char *copy_input;
	int loop = 1;
	int i;
	int success = 0;
	int quote_count;
	char buffer[MAX_STR_LENGTH];
	char *p;
	char *ptrEnd = NULL;
	char *lol = "12 lol";

	treap_t *root = NULL; //treap pointer
	double num_value;

	printf("Proposed operations:\nCreate\tRead\tUpdate\tDelete\nExample of query: create \"mykey\" \"myvalue\"\n");
	
	while (loop)
	{
		
		/*
		create "mykey" "my value"
		create "something" 42
		update "something" 49
		
		для бинарных данных:
		createbin "somethingfromfile" "c:/hello.bmp"
		update "somethingfromfile" "c:/hello_from_base.bmp"
		*/
		//add_input();


		while( !success )
		{

		if ( ! fgets(buffer, MAX_STR_LENGTH, stdin) )
					{
						fprintf(stderr, "Невозможно считать строку\n");
						system("pause");
						//return 1;
					}
		
		if ( ! ( input = _strdup(get_str(buffer)) ) ) 
					{
						fprintf(stderr, "Ошибка памяти\n");
						system("pause");
						//return 1;
					}

		printf("%s\n", input);
		
		/*
		if (! (operation = strtok( input, " \"")))
		{
			fprintf(stderr, "Icorrect input.");
			system("pause");
			return 1;
		}
		printf("Test: %s\n",operation);

		printf(input);
		if (! (key = strtok( input, "\"")))
		{
			fprintf(stderr, "Icorrect input.");
			system("pause");
			return 1;
		}
		printf("Test: %s",key);*/


		quote_count = ident_str(input);

		p = strtok (input, " ");  //create
		operation = p;
		
		p = strtok('\0', "\""); //"key"
		key = p;
		
		if (quote_count == 4) 
		{	
		p = strtok('\0', "\""); //" "
		p = strtok('\0', "\""); //"value"
		
		value = p;
		success = 1;
		}
		else if (quote_count == 2)
		{
			value = strtok ('\0', " ");
			num_value = strtod(value, NULL);
			//printf("TESSTS: %f\n", num_value);
			success = 1;
		}
		else 
			{
				//printf("\nTEST: %d", quote_count);
				printf("Syntax mistake\n");				
		}
	}
		//printf("Operation: %s, Key: %s, Value: %s\n", operation, key, value);
		/*for (i = 0; i< strlen(key); ++i)
			printf("%d\n", key[i]);*/ //102 117 99 107
		success = 0;

		/*
		record-> data = malloc(record-> data_length)
		*/
		

		if ( !strcmp(operation, "create") ) 
		{
			database = (kvp_t*)malloc(sizeof(kvp_t));

			printf("Creating new record...");
			database->key_length = (size_t)malloc(sizeof(size_t));
			database->key_length = strlen(key);
			// key - указатель на структуру бд ключ-значение
			database->key = (char*)malloc(database->key_length * sizeof(char));
			database->key = key;

			if (quote_count == 4)
			{
				database->data_length = strlen(value);
				database->data = (char*)malloc(database->data_length * sizeof(char));
			}

			root = Insert (database, root);
			printf("\n");
			InOrder(root);
		


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



