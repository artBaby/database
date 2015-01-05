#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <stdint.h>
#include <malloc.h>
#include <string.h>

#define SCREEN_WIDTH (80)
#define MAX_STR_LENGTH (256)

char *get_item(char *str) {
    char *enter = strrchr(str, '\n');
    if (enter)
        *enter = '\0';
    return str;
}

void add_input(void) {
    char c;
    while ( scanf("%c", &c) == 1 && c!= '\n' )
		//get symbols
        ;
}

int main(int argc, char *argv[])
{
	char *headerValue;
	char ***database_p;
	int endOfWork=0;
	int choise;
	size_t headerCount;
	size_t lengthCount;
	size_t i;
	size_t j;
	int k;

	char buffer[MAX_STR_LENGTH];



	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода	
	/* 3 типа работы: ввод, отображение, поиск */	

	while (endOfWork == 0){
	//system("cls");
	printf("Выберите нужный пункт\n");
	printf("1 - создание новой БД\n2 - вывод существующей БД\n3 - поиск в БД\n");	
	scanf("%d", &choise);
	printf("Выбранный пункт: %d\n", choise);

	if (choise == 1)
	{
		printf("Количество строк содаваемой БД:  ");
		scanf("%d", &lengthCount);
		printf("Количество полей (столбцов) создаваемой БД:  ");
		scanf("%d", &headerCount);		

		database_p = (char***)malloc(lengthCount * sizeof(char**));

		if (database_p != NULL)
		{
			for (i = 0; i < lengthCount; i++)
			{
			database_p[i] = (char**)malloc(headerCount * sizeof(char*));
			}			
		}
		else {
			fprintf(stderr, "Ошибка выделения памяти\n");
			return 1;
		}
		
		add_input();
		for ( i = 0; i < lengthCount; ++i )
		{
			for ( j = 0; j < headerCount; ++j )
			{
				printf("Строка: %u, Ряд: %u, Значение:  ", i+1, j+1);
				if ( ! fgets(buffer, MAX_STR_LENGTH, stdin) )
				{
					fprintf(stderr, "Невозможно считать строку\n");
					system("pause");
					return 1;
				}
				if ( ! ( database_p[i][j] = _strdup(get_item(buffer)) ) ) 
				{
					fprintf(stderr, "Ошибка памяти\n");
					system("pause");
					return 1;
				}
        }
    }
		
		printf("Результат:\n");
		
		for ( i = 0; i < lengthCount; ++i ) 
		{
			for ( j = 0; j < headerCount; ++j )
			{
				printf("%-*s", SCREEN_WIDTH / headerCount, database_p[i][j]);
			}

        printf("\n");
		}

		for ( i = 0; i < lengthCount; ++i ) {
			for ( j = 0; j < headerCount; ++j )
				free(database_p[i][j]);
			free(database_p[i]);
    }
		free(database_p);
    printf("\n");

	}
	else printf("NO\n");
	}
	
	system("pause");	
	return 0;

}
