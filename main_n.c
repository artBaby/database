#include "newmain.h"

#define CMD_BUF_SIZE 2048

typedef int bool_t;
#define TRUE 1
#define FALSE 0

typedef struct {
    char const*  name;					//название
    size_t arg_count;					//количество аргументов
	bool_t (*handler)(stringarray_t);		//обработчик
} command_t;						//команда

void stringarray_destroy( stringarray_t* arr ) {
    size_t i;
    for( i = 0; i < arr->size; i++)
        free( arr->items[i] );
}

treap_t *root = NULL; 

bool_t handler_create(stringarray_t args) {
	char *type;
	kvp_t *database = NULL;
	size_t data_length = 0;
	char *buf = NULL;
	treap_t *got_root; 
	data_type_t type_input;
	FILE *file;
	char *path;
	char *key;
	type = args.items[2];
	key = args.items[1];

	if (!strcmp(type, "str")){
		type_input = string_data;

		got_root = GetValue(key, root);
			if (! got_root){
				database = memget(database, key, args.items[3], type_input, data_length);
				if ( database != NULL ){root = Insert(database, root);			
					printf("Done!\n");
				}
				else {printf("Memory error\n");}			
			}
			else printf("Key '%s' already exists\n", args.items[1]);	
	}

	else if (!strcmp(type, "num")){
		type_input = number_data;
		got_root = GetValue(args.items[1], root);
			if (! got_root){
				database = memget(database, args.items[1], args.items[3], type_input, data_length);
				if ( database != NULL ){root = Insert(database, root);printf("Done!\n");}
				else {printf("Memory error\n");}			
			}else printf("Key '%s' already exists\n", args.items[1]);		
	}


	else if (!strcmp(type, "bin")){
		type_input = binary_data;
		path = args.items[3];
		args.items[3] = ReadBin(path, buf);
		if (args.items[3]) {
			data_length = GetSize(path);
		got_root = GetValue(args.items[1], root);
			if (! got_root){
				database = memget(database, args.items[1], args.items[3], type_input, data_length);
				if ( database != NULL ){root = Insert(database, root);printf("Done!\n");}
				else {printf("Memory error\n");}			
			}else printf("Key '%s' already exists\n", args.items[1]);	
		}else printf("Invalid path\n");
	}
	else {printf("Unknown type\n");}

}

bool_t handler_read(stringarray_t args){
	treap_t *got_root; 
	got_root = GetValue(args.items[1], root);
			if (! got_root)
				printf("Key '%s' not found.\n", args.items[1]);
			else PrintMe(got_root);
}

bool_t handler_update(stringarray_t args){
	char *key = args.items[1];
	char *type = args.items[2];
	char *value = args.items[3];
	data_type_t type_input;
	size_t data_length = 0;
	kvp_t *database;
	printf("Updating '%s'. . .", key);
	if (strcmp(type, "str")) type_input = string_data;
	else if (strcmp(type, "num")) type_input = number_data;
	else if (strcmp(type, "bin")) type_input = binary_data;
			if ( !GetValue(key, root))
				printf("Key '%s' not found.\n", key);
			else
			{
				Deleting(key, &root);
				database = memget(database, key, value, type_input, data_length);
				if (database != NULL)
				{
					root = Insert (database, root);			
					printf("Done!\n");
				}	
				else printf("Memory error!\n");
			}
}

bool_t handler_delete(stringarray_t args){
	char *key = args.items[1];
	printf("Deleting '%s'. . . ", key);
			Deleting(key, &root);
			printf("Done!\n");
}

bool_t handler_show(stringarray_t args){
	if (root == NULL) printf("Database is empty.\n");
	else InOrder(root);
}

bool_t handler_save(stringarray_t args){
	char *key = args.items[1];
	printf("Saving. . . ");
	savetofile(root, key);
	printf("Done!\n");
}


bool_t try_execute(stringarray_t parts, command_t const* command) {
    if ( 0 == strcmp( parts.items[0], command->name ) && command->arg_count == parts.size - 1 ) 
    {
        command->handler( parts );
        return TRUE;
    }
    else return FALSE;
}



const command_t commands[] = {
    { "create", 3, handler_create },
	{ "read", 1, handler_read },
	{ "update", 3, handler_update},
	{ "delete", 1, handler_delete},
	{ "show", 0, handler_show},
	{ "save", 2, handler_save}	
};

int main(int argc, char** argv) {
	char read_buf[CMD_BUF_SIZE]={0}; 
    while(1) 
	{
        size_t i;
        stringarray_t tokenized;
		fgets(read_buf, CMD_BUF_SIZE, stdin);
		tokenized = split(read_buf); 
        for(i = 0; i < sizeof(commands)/sizeof(command_t); i++) 
            if( try_execute(tokenized, commands + i ) ) break;

       stringarray_destroy( &tokenized );
    }

    return 0;

}
