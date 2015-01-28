#include "treap.h"
#include "main.h"
#include "memget.h"
#include "reader.h"
#include "save.h"
#include "IObin.h"
#include "open.h"


int main(int argc, char *argv[])
{
	kvp_t *database = NULL;
	BMP_HEADER *head = NULL;
	char *operation, *key, *value = NULL, *input;
	data_type_t type_input;
	int loop = 1, success = 0, quote_count;
	char *p;
	char *ptrEnd = NULL;
	treap_t *root = NULL; //treap pointer
	float *num_value = 0;
	treap_t *got_root;
	FILE *file;
	char *man = "Proposed operations:\nCreate\tRead\tUpdate\tDelete\nExample of query: create \"mykey\" \"myvalue\"\nYou can enter this types of input to 'myvalue'\n1.NUMBER (without quotes)\n2.STRING (bounded with quotes)\n3.PATH TO FILE (if PATH does not exist, it will be submitted as STRING)\n";

	printf(man);	
	while (loop)
	{
		while( !success )
		{
			input = read();
			quote_count = ident_str(input);
			p = strtok(input, " ");  //operation
			operation = p;						
			p = strtok('\0', "\""); //"key"
			key = p;		
			if (quote_count == 4) 
			{	
				p = strtok('\0', "\""); //" "
				p = strtok('\0', "\""); //"value"		
				value = p;
				file = fopen(p, "rb");
				if ( file == NULL ){
					type_input = string_data;	
				}
				else{
					type_input = binary_data;
					head = GetHeader(file);
					if (head){
						value = (char*)ReadBMP(file, head);
					}					
				}
				break;
			}		
			else if (operation == NULL)
				printf("Invalid operation\n");
			else if ( !strcmp(operation, "clear"))
			{
				system("cls");
				printf(man);
			}
			else if (quote_count == 2 && !strcmp(operation, "create"))
			{
				value = strtok ('\0', " ");
				if (value != NULL)
				{
				type_input = number_data;				
				break;
				}
				else 
				{
					printf("Value not found\n");
				}
			}
			else if (quote_count == 2 && !strcmp(operation, "read") )			
				break;		
			else if (quote_count == 2 && !strcmp(operation, "update") )
			{
				value = strtok ('\0', " ");
				type_input = number_data;
				break;
			}			
			else if (quote_count == 2 && !strcmp(operation, "delete") )
				break;
			else if (!strcmp(operation, "save") )
				break;
			else if (!strcmp(operation, "show") )
				break;
			else if ( !strcmp(operation, "open"))
				break;
			else
				printf("Syntax mistake\n");			
		}		
			success = 0;	
			
			if ( !strcmp(operation, "create") && value != NULL ) 
		{
			got_root = GetValue(key, root);
			if (! got_root)
			{
				database = memget(database, key, value, type_input, head);
				if ( database != NULL ){
					root = Insert(database, root);			
					printf("Done!\n");
				}
				else 
				{printf("Memory error\n");}			
			}
			else 
				printf("Key '%s' already exists\n", key);
		}
		if (!strcmp(operation, "read"))
		{
			got_root = GetValue(key, root);
			if (! got_root)
				printf("Key '%s' not found.\n", key);
			else PrintMe(got_root);
		}
		if (!strcmp(operation, "update"))
		{
			printf("Updating '%s'. . .", key);
			if ( !GetValue(key, root))
				printf("Key '%s' not found.\n", key);
			else
			{
				Deleting(key, &root);
				database = memget(database, key, value, type_input, head);
				if (database != NULL)
				{
					root = Insert (database, root);			
					printf("Done!\n");
				}	
				else printf("Memory error!\n");
			}
		}	
		if (!strcmp(operation,"delete"))
		{
			printf("Deleting '%s'. . . ", key);
			Deleting(key, &root);
			printf("Done!\n");
		}
		//make typedef for operations, cuz strcmp slower.
		if ( !strcmp( operation, "save")  )
		{
			if ( !key )
				{
					printf("Wrong input! arguments:\nsave [\"key\"] \"path\"\n");
			}
			else if ( key && !value )
			{
			savetofile(root, key);
			}
			else if ( key && value )
			{
				got_root = GetValue(key, root);
			if (! got_root)
				printf("Key '%s' not found.\n", key);
			else savebykey(got_root, value);
			}
		}
		/*if ( !strcmp( operation, "save") && key != NULL && value != NULL)
		{
			bmp_root = GetValue(key, root);
			SaveBMPData(value, bmp_root->key->head, (unsigned char*)bmp_root->key->data);
		}*/
		if ( !strcmp(operation, "show") ) 
			InOrder(root);
		if ( !strcmp(operation, "open"))
		root = openfromfile(key);
		key = NULL;
		value = NULL;
	}
	system("pause");
}
