#include "memget.h"
#include "IObin.h"


kvp_t *memget(kvp_t *db_pointer, char* key, char* value, data_type_t type_input, size_t data_length)
{
	kvp_t *database = db_pointer;
	printf("Creating new record . . .\n");
	database = (kvp_t*)malloc(sizeof(kvp_t));
	if (database != NULL)
	{
		database->key_length = strlen(key);
		database->key = (char*)malloc(database->key_length * sizeof(char));
		database->key = key;
		if (data_length)
		{
			database->data_length = data_length;
			database->data = malloc(data_length);
		}
		else
		{
			database->data_length = strlen(value);
			database->data = malloc(database->data_length);
		}		
		database->data = value;
		database->type = type_input;		
		return database;
	}
	else return NULL;
}
