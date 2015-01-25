#include "memget.h"


kvp_t *memget(kvp_t *db_pointer, char* key, char* value, data_type_t type_input)
{
	kvp_t *database = db_pointer;
	printf("Creating new record . . .\n");
	database = (kvp_t*)malloc(sizeof(kvp_t));
	if (database != NULL)
	{
		//database->key_length = (size_t)malloc(sizeof(size_t));
		database->key_length = strlen(key);
		database->key = (char*)malloc(database->key_length * sizeof(char)); // key - указатель на ключ
		database->key = key;
		database->data_length = strlen(value);
		//добавить флаг, чтобы в read проверять, было ли что-то вообще занесено или проверять это в treap.h
		database->data = malloc(database->data_length);
		database->data = value;
		database->type = type_input;
		return database;
	}
	else return NULL;
}
