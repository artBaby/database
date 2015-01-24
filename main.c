
#include "treap.h"
#include "main.h"

// CRUD:
// CREATE READ UPDATE DELETE

int main(int argc, char *argv[])
{
	/*pointer for struct*/
	kvp_t *database;
	char *operation;
	char *key;
	char *value;
	data_type_t type_input;
	char *input;
	char *copy_input;
	int loop = 1;
	int i;
	int success = 0;
	int quote_count;
	char buffer[MAX_STR_LENGTH];
	char *p;
	char *ptrEnd = NULL;
	treap_t *root = NULL; //treap pointer
	float *num_value = 0;
	double *num_value_ptr;
	treap_t *got_root;

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
					}		
			if ( ! ( input = _strdup(get_str(buffer)) ) ) 
					{
						fprintf(stderr, "Ошибка памяти\n");
						system("pause");
					}		
			quote_count = ident_str(input);
			p = strtok (input, " ");  //operation
			operation = p;						
			p = strtok('\0', "\""); //"key"
			key = p;		
			if (quote_count == 4) 
			{	
				p = strtok('\0', "\""); //" "
				p = strtok('\0', "\""); //"value"		
				value = p;
				type_input = string_data;
				break;
			}		
			else if (quote_count == 2 && !strcmp(operation, "create"))
			{
				value = strtok ('\0', " ");
				//num_value = strtod(value, NULL);
				//num_value_ptr = &num_value;
			//	printf("TESSTS: %f\n", num_value);
				type_input = number_data;				
				break;
			}
			else if (quote_count == 2 && !strcmp(operation, "read"))			
				break;		
			else if (quote_count == 2 && !strcmp(operation, "update") )
			{
				value = strtok ('\0', " ");
				//num_value_ptr = &num_value;
				//*num_value = strtod(value, NULL);
			//	printf("TESSTS: %f\n", num_value);
				type_input = number_data;
				break;
			}
			//черти как присваиваются num_value и value.
			else if (quote_count == 2 && !strcmp(operation, "delete") )
				break;	
			else if (!strcmp(operation, "show"))
				break;
			else
				printf("Syntax mistake\n");			
		}		
			success = 0;	
			/*
			record-> data = malloc(record-> data_length)
			*/	
		if ( !strcmp(operation, "create") ) 
		{
			// добавить проверки на выделение памяти
			printf("Creating new record . . .\n");
			database = (kvp_t*)malloc(sizeof(kvp_t));			
			//database->key_length = (size_t)malloc(sizeof(size_t));
			database->key_length = strlen(key);
			database->key = (char*)malloc(database->key_length * sizeof(char)); // key - указатель на ключ
			database->key = key;
			database->data_length = strlen(value);
			//database->type = (data_type_t*)malloc(sizeof(data_type_t));
			//добавить флаг, чтобы в read проверять, было ли что-то вообще занесено или проверять это в treap.h
			database->data = malloc(database->data_length);
			database->data = value;
			database->type = type_input;
			
			/*if (quote_count == 4)
			{				
				//database->data = malloc(database->data_length); // value - указатель на значение
				//database->data = value;
				//database->type = type_input;
			}
			if (quote_count == 2)
			{				
				//database->data = malloc(database->data_length*sizeof(double));
				database->data = malloc(database->data_length*sizeof(float));
				database->data = num_value;
				database->type = type_input;
			}*/

			root = Insert (database, root);			
			printf("Completed!\n");
			//InOrder(root); - вывод дерева
		}
		if ( !strcmp(operation, "show") ) 
			InOrder(root);

		if (!strcmp(operation, "read"))
		{
			got_root = GetValue(key, root);
			if (! got_root)
				printf("Key '%s' not found.\n", key);
			else PrintMe(got_root);
		}

		if (!strcmp(operation, "update"))
		{
			printf("Updating '%s'. . .\n", key);
			if ( !GetValue(key, root))
				printf("Key '%s' not found.\n", key);
			else
			{
				Deleting(key, &root);
				database = (kvp_t*)malloc(sizeof(kvp_t));			
				//database->key_length = (size_t)malloc(sizeof(size_t));
				database->key_length = strlen(key);
				database->key = (char*)malloc(database->key_length * sizeof(char)); // key - указатель на ключ
				database->key = key;
				database->data_length = strlen(value);
				//database->type = (data_type_t*)malloc(sizeof(data_type_t));
				//добавить флаг, чтобы в read проверять, было ли что-то вообще занесено или проверять это в treap.h
				database->data = malloc(database->data_length); // value - указатель на значение
				database->data = value;
				database->type = type_input;
				/*if (quote_count == 4)
				{				
					database->data = (char*)malloc(database->data_length); // value - указатель на значение
					database->data = value;
					database->type = type_input;
				}
				if (quote_count == 2)
				{				
					database->data = malloc(database->data_length*sizeof(double));
					database->data = num_value_ptr;
					database->type = type_input;
				}*/
				root = Insert (database, root);			
				printf("Completed!\n");	
				}
			}
	
		if (!strcmp(operation,"delete"))
		{
			printf("delete '%s'", key);
			Deleting(key, &root);
			printf("\n");
			InOrder(root);
		}				
	}
	system("pause");
}



