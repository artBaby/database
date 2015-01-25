#include "save.h"


//treap_t *Root = root;
void savetofile( treap_t *root, char* path )
{	
	FILE *file;
	double num_value;
	if ( !(file = fopen (path, "a+")) )
		{
			printf("Can not create file\n");
		}
	else 
	if (root != NULL)
	{
		savetofile (root->leftChild, path);
		switch(root->key->type) 
		{
			case 1: 
				{
					char *c = (char *)root->key->data;
					fprintf(file, "Key: '%s'\nvalue: %s\n\n", root->key->key, c); 
					
					break;
				}
			case 2: 
				{
					char *c = (char *)root->key->data;
					num_value = strtod(c,NULL);
					fprintf(file, "Key: '%s'\nvalue: %lf\n\n",root->key->key, num_value);
					break;
				}
			case 3:
				{
					char *c = (char *)root->key->data;
					fprintf(file, "Key: '%s'\nvalue: %s\n\n", root->key->key, c); 
					break;
				}
			//fprintf(file, "DATA<%s>\nDATA_LENGTH<%s>\nKEY<%s>\nKEY_LENGHT<%u>\nTYPE<%u>\n\n", root->key->data, root->key->data_length,root->key->key, root->key->key_length, root->key->type);	
		}
		savetofile (root->rightChild, path);
	fclose(file);
	}
}
	
