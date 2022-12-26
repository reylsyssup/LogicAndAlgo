#include "Sys.h"

void main()
{
	setlocale(LC_ALL, "Rus");
	dvigat_1();
}

void start()
{
	int** M = NULL;
	char** L = NULL;
	int n;
	float t;
	El* Q = NULL;
	FILE* F;
	char name[] = "Settings.txt", lab[31];

	if ((F = fopen(name, "r")) == NULL)
	{
		stand();
	}
	F = fopen(name, "r");
	fseek(F, 43, SEEK_SET);
	if (fgetc(F) == '-')
	{
		fseek(F, 19, SEEK_SET);
		fscanf(F, "%d", &n);
		M = gen(n);
	}
	else
	{
		fseek(F, 43, SEEK_SET);
		fgets(lab, 30, F);
		fclose(F);
		F = fopen(lab, "r");
		fseek(F, 0, SEEK_SET);
		int i, j, N;
		fscanf(F, "%d", &N);
		M = (int**)malloc(N * sizeof(int*));
		for (i = 0; i < N; i++)
			M[i] = (int*)malloc(N * sizeof(int));

		fseek(F, 12, SEEK_SET);
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
			{
				fscanf(F, "%d", &M[i][j]);
				fseek(F, 1, SEEK_CUR);
			}
			fseek(F, 1, SEEK_CUR);
		}
		n = sqrt(N);
	}
	fclose(F);
	F = fopen(name, "r");
	fseek(F, -1, SEEK_END);
	fscanf(F, "%f", &t);
	fclose(F);
	L = Lgen(M, n);
	Q = put(M, n * n, Q);
	print_L(L, n * 2 + 1);
	HZ(L, Q, n, M, t / 2);
}
