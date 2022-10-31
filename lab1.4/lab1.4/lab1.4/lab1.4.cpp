﻿// lab1.4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <locale.h>
#include <stdio.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));//Для настоящего рандома

	int i, j, rowCount, columnCount, ** matrix;

	

	printf("Введите количество строк = ");

	scanf_s("%d", &rowCount);

	printf("Введите количество столбцов = ");

	scanf_s("%d", &columnCount);


	matrix = (int**) malloc(rowCount  * sizeof(int*));

	for (int i = 0; i < columnCount; i++)
	{
		matrix[i] = (int*)malloc(columnCount * sizeof(int));
	}
	// ввод элементов массива

	for (i = 0; i < rowCount; ++i) { //цикл по строкам

		for (j = 0; j < columnCount; ++j) { //цикл по столбцам

			matrix[i][j] = rand() % 100;
		}
	}

	for (int i = 0; i < rowCount; i++)
	{
		printf("\n");
		for (int j = 0; j < columnCount; j++)
		{
			printf("\t %d", matrix[i][j]);
		}
	}
	printf("\nРезультат:\n");
	for (int i = 0; i < columnCount; i++)
	{
		int sumElem = 0;

		for (int j = 0; j < rowCount; j++)
		{
			sumElem += matrix[j][i];
			 
		}

		printf("Сумма элементов в столбце = %d\n", sumElem);
	}



}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
