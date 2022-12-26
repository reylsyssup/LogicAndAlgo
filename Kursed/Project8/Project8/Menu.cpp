#include "Sys.h"

void menu(int i, char* m)
{
	system("cls");
	m[i] = '>';
	m[i + 1] = '<';
	printf("\n\n\n\n");
	printf("      ______________            _______________            _______________      \n");
	printf("     |              |          |               |          |               |     \n");
	printf("   %c |    Играть    | %c      %c |   Настройки   | %c      %c |     Выход     | %c   \n", m[0], m[1], m[2], m[3], m[4], m[5]);
	printf("     |______________|          |_______________|          |_______________|     \n");
	printf("\n\n\n\n\n\n\n");
	printf("Стрелки - Перемещение; 1 - Выбор;");
	m[i] = ' ';
	m[i + 1] = ' ';
}

void set(int i, char* m)
{
	system("cls");
	m[i] = '>';
	m[i + 1] = '<';
	printf("\n\n\n\n");
	printf("      ______________             _______________            _______________      \n");
	printf("     |              |           |               |          |               |     \n");
	printf("   %c |    Размер    | %c       %c |   Сложность   | %c      %c |     Сброс     | %c\n", m[0], m[1], m[2], m[3], m[4], m[5], m[6], m[7]);
	printf("     |______________|           |_______________|          |_______________|     \n");
	printf("\n\n\n\n\n\n\n");
	printf("Стрелки - Перемещение; 1 - Выбор; 2 - Выход");
	m[i] = ' ';
	m[i + 1] = ' ';
}

void seti(int i, char* m)
{
	system("cls");
	m[i] = '>';
	m[i + 1] = '<';
	printf("\n\n\n\n");
	printf("      ______________            _______________            _______________      \n");
	printf("     |              |          |               |          |               |     \n");
	printf("   %c |     Легко    | %c      %c |    Нормально  | %c      %c |     Тяжело    | %c   \n", m[0], m[1], m[2], m[3], m[4], m[5]);
	printf("     |______________|          |_______________|          |_______________|     \n");
	printf("\n\n\n\n\n\n\n");
	printf("Стрелки - Перемещение; 1 - Выбор; 2 - Выход");
	m[i] = ' ';
	m[i + 1] = ' ';
}

void raz()
{
	int n;
	FILE* F;
	char name[] = "Settings.txt";

	system("cls");
	printf("Введите размер лабиринта:");
	scanf("%d", &n);

	if ((F = fopen(name, "r+")) == NULL)
	{
		F = fopen(name, "w+");
		stand();
	}
	fseek(F, 19, SEEK_SET);
	fprintf(F, "%d     ", n);

	fclose(F);
}

void dvigat_2();
void dvigat_3()
{
	char m[6] = { ' ',' ',' ',' ',' ',' ' };
	int i = 0, k = 0, n;
	seti(i, m);
	while (k == 0)
	{
		switch (_getch())
		{
		case 75: if (i != 0)
		{
			i = i - 2; 
			seti(i, m); 
			break;
		}
		case 77: if (i != 4)
		{
			i = i + 2; 
			seti(i, m); 
			break;
		}
		case 49: if (i == 0)
		{
			sloj(3);
		} 
			   if (i == 2)
			   {
				   sloj(2);
			   }
			   if (i == 4) 
			   { 
				   sloj(1); 
				   break;
			   }
		case 50: dvigat_2();
		}
	}
}

void dvigat_2()
{
	char m[8] = { ' ',' ',' ',' ',' ',' ',' ',' ' };
	int i = 0, k = 0, n;
	set(i, m);
	while (k == 0)
	{
		switch (_getch())
		{
		case 75: if (i != 0)
		{
			i = i - 2; 
			set(i, m); 
			break;
		}
		case 77: if (i != 6)
		{
			i = i + 2; 
			set(i, m); 
			break;
		}
		
		case 49: if (i == 0) 
		{ 
			raz();
		}
		if (i == 2)
		{
			dvigat_3(); 
			break;
		}
		if (i == 6) 
		{
			stand();
		}
		case 50: dvigat_1();
		}
	}
}

void dvigat_1()
{
	char m[6] = { ' ',' ',' ',' ',' ',' ' };
	int i = 0, k = 0;
	menu(i, m);
	while (k == 0)
	{
		switch (_getch())
		{
		case 75: if (i != 0)
		{
			i = i - 2; 
			menu(i, m); 
			break;
		}
		case 77: if (i != 4)
		{
			i = i + 2; 
			menu(i, m); 
			break;
		}
		case 49: if (i == 0)
		{
			start();
		}
			   if (i == 2)
		{
			dvigat_2();
		}
			   if (i == 4)
			   { 
				   exit(0); break; 
			   }
		}
	}
}
