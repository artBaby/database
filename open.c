#include "open.h"

char *readstrfromfile(FILE *file)
{
	char buffer[MAX_STR_LENGTH];
	char *input;
	
	if ( ! fgets(buffer, MAX_STR_LENGTH, file) )
		{
			return NULL;
		}		
	if ( ! ( input = _strdup(get_str(buffer)) ) ) 
		{
			fprintf(stderr, "Ошибка памяти\n");
			system("pause");
		}
	else return input;
}
char *parsestr(FILE* file)
{
	char *input, *p;
	input = readstrfromfile(file);
	p = strtok(input, "\'");
	p = strtok('\0', "\'");
	return p;

}

treap_t *openfromfile(char *path)
{
	FILE *file, *filebin;
	treap_t *root = NULL;
	kvp_t *database = NULL;
	BMP_HEADER *head;
	data_type_t type_input;
	int converted_type;
	char *input, *p, *key, *value, *type;
	//double num_value;
	//char *source_dir = directory;
	//char *dir = directory;
	if ( !(file = fopen (path, "r")) )
		{
			printf("Can not open file\n");
			return NULL;
		}
	else 
	{
		do
		{
		if(!(key = parsestr(file)))
			break;
		
		value = parsestr(file);
		type = parsestr(file);

		filebin = fopen(value, "rb");
			//if path doesn't exist then string_data
			if ( filebin == NULL )
			{
				converted_type = atoi(type);
				switch (converted_type)
				{
					case 1: type_input = string_data;
					case 2: type_input = number_data;
					case 3: type_input = string_data;
				}
			}
			//else binary
			else
			{
				type_input = binary_data;
				head = GetHeader(filebin);
				if (head)
				{
					value = (char*)ReadBMP(filebin, head);
				}				
			}
		database = memget(database,key,value,type_input, head);
		root = Insert(database, root);
		fscanf(file, "\n");
		}
		while (key);
		printf("Done!\n");
		return root;

	}
}


