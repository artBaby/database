#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
	int endOfWork=0;
	int choise;
	

	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода	
	/* 3 типа работы: ввод, отображение, поиск */	

	while (endOfWork == 0){

	printf("Выберите нужный пункт\n");
	printf("1 - создание новой БД\n2 - вывод существующей БД\n3 - поиск в БД\n");	
	scanf("%d", &choise);
	printf("Выбранный пункт: %d\n", choise);

	if (choise == 1)
	{
		printf("Get\n");
		endOfWork = 1;
	}
	else printf("NO\n");
	}
	system("pause");

	
	return 0;

}
