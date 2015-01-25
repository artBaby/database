#include "reader.h"
#include "pars.h"

char *read()
{
	char buffer[MAX_STR_LENGTH];
	char *input;
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
	else return input;
}
