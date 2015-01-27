#include "save.h"
#include "IObin.h"


//treap_t *Root = root;
void savetofile( treap_t *root, char* directory )
{	
	FILE *file;
	double num_value;
	char *source_dir = directory;
	char *dir = directory;
	if ( !(file = fopen (dir, "a+")) )
		{
			printf("Can not create file\n");
		}
	else 
	if (root != NULL)
	{
		savetofile (root->leftChild, directory);
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
					char *c = directory;
					strncat(c, root->key->key,5);
					strncat(c, ".bmp",4);
					SaveBMPData(c, root->key->head, (unsigned char*)root->key->data);
					fprintf(file, "Key: '%s'\nvalue: %s\n\n", root->key->key, c); 
					break;
				}
		}
		savetofile (root->rightChild, directory);
	fclose(file);
	}
}
	
