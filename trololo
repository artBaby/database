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

char *get_item2(char *str) {
	char *verticalBar = strrchr(str, '|');
	if (verticalBar)
		*

}

void add_input(void) {
    char c;
    while ( scanf("%c", &c) == 1 && c!= '\n' )
		//get symbols
        ;
}

void add_input2(void) {
	char c;
	FILE *file;
	while ( fscanf(file, "%c", &c) == 1 && c!= '\t' && c!= '|' )

		;
}

int main(int argc, char *argv[])
{
	char *headerValue;
	char ***database_p;
	char ***database_p2;
	int endOfWork=0;
	int choise;
	size_t headerCount;
	size_t lengthCount;
	size_t headerCount2;
	size_t lengthCount2;
	size_t i;
	size_t j;
	char answer;
	char answer2;
	int k;
	char path[256];
	FILE *file;
	char filename[25];
	char test[20];
	

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

	switch (choise)
	{
	case 1 :
		{
			
			printf("Количество строк содаваемой БД:  ");
			scanf("%d", &lengthCount);
			printf("Количество полей (столбцов) создаваемой БД:  ");
			scanf("%d", &headerCount);		

			database_p = (char***)malloc(lengthCount * sizeof(char**));

			if (database_p != NULL)
			{
				for (i = 0; i < lengthCount; ++i)
				{
				database_p[i] = (char**)malloc(headerCount * sizeof(char*));
				}			
			}
			else {
				fprintf(stderr, "Ошибка выделения памяти\n");
				return 1;
			}
			printf("Вводите значения ячеек слева направо, сверху вниз.\n");
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
				
					printf("______________________________\n");
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
			k = 0;
			printf("TEST - %d", strlen(database_p[1][1]));
			printf("\n");
			printf("Соxранить созданную базу данных? [Y/N] ");
			scanf("%1s", &answer);
			//printf("%c", answer);
			while (k == 0)
			{
		
			if ( (answer == 'Y') || (answer == 'y') )
			{
				printf("Введите путь, заменяя \\ на \\\\ (Например, C:\\myDataBase.txt): ");
				scanf("%s", &filename);
				puts(filename);
				if ( (file = fopen (filename, "w+"))  ==  NULL)
				{
					printf("Ошибка записи в файл");
				}
				else 
				{
					fprintf(file, "%u %u\n",lengthCount, headerCount);					
					for ( i = 0; i < lengthCount; ++i ) 
					{
						fprintf(file,"|");
						for ( j = 0; j < headerCount; ++j )
						{
							fprintf(file,"\t%s\t|", database_p[i][j]);							
						}
						fprintf(file,"\n");
					}

					fclose(file);
				}
				//printf("YEEEES!!!");
				break;
			}
			else if ( (answer == 'N') || (answer == 'n') )
			{
				printf("NOOOOO!!!");
				break;
			}
			else {
				printf("\nОшибка ввода. Введите Y - yes, N - no: ");
				scanf("%1s", &answer);
			}
			
			}
			for ( i = 0; i < lengthCount; ++i ) 
			{
				for ( j = 0; j < headerCount; ++j )
					free(database_p[i][j]);
				free(database_p[i]);
			}
			free(database_p);
			printf("\n");

			break;
		}
		
	case 2:
		{
			k = 0;
			while (k == 0){
			printf("Введите путь, экранируя \\ - \\\\:	");
				scanf("%s", &path);
				printf("\npath: %s\n",path);
				//puts(path);
				if ( (file = fopen (path, "r+"))  ==  NULL)
				{
					printf("Ошибка записи в файл");
				}

				else
				{
					if ( fscanf(file,"%u %u\n", &lengthCount2, &headerCount2) != 2 )
					{
						printf("Неверный заголовок файла");
						printf("Открыть новый файл? [Y/N] ");
						scanf("%1s", &answer2);
						if ( answer2 == 'n' || answer2 == 'N' )
						break;

					}
					else
					{
						database_p2 = (char***)malloc(lengthCount2 * sizeof(char**));
						if (database_p2 != NULL)
						{
							for (i = 0; i < lengthCount2; ++i)
							{
								database_p2[i] = (char**)malloc(headerCount2 * sizeof(char*));
							}
						}
						else 
						{
							fprintf(stderr, "Ошибка выделения памяти");
							return 1;
						}

						fscanf(file,"|\t%19c\t|",&test);
						printf("\nTEST: %s", test);
						/*for ( i = 0; i < lengthCount; ++i ) 
						{
							//fscanf(file, "\n");
							for ( j = 0; j < headerCount; ++j )
							{
								fscanf(file,"|\t%s\t", database_p[i][j]);
							}
							fscanf(file,"|\n");

							/*fscanf(file, );
							fgets(buffer, 256, file);
							puts(buffer);
						}*/
							fclose(file);
						//	printf("TEST2 - %s", database_p[1][1]);
					}					
				}
			}
			for ( i = 0; i < lengthCount; ++i ) 
			{
				for ( j = 0; j < headerCount; ++j )
					free(database_p[i][j]);
				free(database_p[i]);
			}
			free(database_p);
			printf("\n");

			break;
		}
	case 3:
		{
			break;
		}

	default: printf("NO\n");
	}
	}
	
	system("pause");	
	return 0;

}
