#include "Sys.h"

void stand()
{
	FILE* F;
	char name[] = "Settings.txt";

	F = fopen(name, "w+");

	fprintf(F, "Размер лабиринта = %d          \n", 5);
	fprintf(F, "Лабиринт = -                                  \n");
	fprintf(F, "Сложность = %d", 1);
	fclose(F);
}

void save(char* lab, int N, int** M)
{
	FILE* F;
	int i, j, n = N * N;
	char name[] = "Settings.txt";

	F = fopen(lab, "w+");
	fprintf(F, "          \n ");
	fseek(F, 0, SEEK_SET);
	fprintf(F, "%d", n);
	fseek(F, 12, SEEK_SET);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			fprintf(F, "%d ", M[i][j]);
		}
		fprintf(F, "\n");
	}
	fclose(F);
	F = fopen(name, "r+");
	fseek(F, 43, SEEK_SET);
	fputs(lab, F);
	fclose(F);
}

void sloj(int k)
{
	FILE* F;
	char name[] = "Settings.txt";

	if ((F = fopen(name, "r")) == NULL)
	{
		stand();
	}
	F = fopen(name, "r+");
	fseek(F, -1, SEEK_END);
	fprintf(F, "%d", k);
	fclose(F);
}
