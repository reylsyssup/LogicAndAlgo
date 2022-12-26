#include "Sys.h"

Node* add(Node* Q, int k, int l)
{
	Node* p;
	p = (struct Node*)malloc(sizeof(struct Node));
	p->x = k;
	p->y = l;
	p->Next = Q;
	Q = p;
	return Q;
}

Node* del(Node* Q)
{
	Node* h;

	h = Q;
	Q = Q->Next;
	free(h);
	return Q;
}

void print_L(char** M, int n)
{
	int i, j;

	for (i = 0; i < n; i++)
	{
		printf("\n");
		for (j = 0; j < n; j++)
		{
			printf("%*C", 3, M[i][j]);
		}
	}
}

int** gen(int n)
{
	int i, j, k, z = 0, N = n * n;
	Node* Q = NULL;
	int** M;
	bool* m;

	m = (bool*)malloc(N * sizeof(bool));
	for (i = 0; i < N; i++)
	{
		m[i] = false;
	}

	M = (int**)malloc(N * sizeof(int*));
	for (i = 0; i < N; i++)
		M[i] = (int*)malloc(N * sizeof(int));

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			M[i][j] = 0;
		}
	}

	i = 0;
	j = 0;
	m[0] = true;
	Q = add(Q, i, j);
	srand(time(NULL));
	//srand(12);
	while (Q != NULL)
	{
		k = 0;
		if (i != n - 1)	if (m[j * n + i + 1] == false) k++;
		if (i != 0)		if (m[j * n + i - 1] == false) k++;
		if (j != n - 1)	if (m[(j + 1) * n + i] == false) k++;
		if (j != 0)		if (m[(j - 1) * n + i] == false) k++;

		if (k > 0)
		{
			k = rand() % 4;
			while (z != 4)
			{
				switch (k)
				{
				case 0:
					if (i != n - 1)
						if (m[j * n + i + 1] == false)
						{
							M[j * n + i + 1][j * n + i] = 1;
							M[j * n + i][j * n + i + 1] = 1;
							m[j * n + i + 1] = true;
							i++;
							Q = add(Q, i, j);
							k = -1;
						}
					break;
				case 1:
					if (i != 0)
						if (m[j * n + i - 1] == false)
						{
							M[j * n + i - 1][j * n + i] = 1;
							M[j * n + i][j * n + i - 1] = 1;
							m[j * n + i - 1] = true;
							i--;
							Q = add(Q, i, j);
							k = -1;
						}
					break;
				case 2:
					if (j != n - 1)
						if (m[(j + 1) * n + i] == false)
						{
							M[j * n + i][(j + 1) * n + i] = 1;
							M[(j + 1) * n + i][j * n + i] = 1;
							m[(j + 1) * n + i] = 1;
							j++;
							Q = add(Q, i, j);
							k = -1;
						}
					break;
				case 3:
					if (j != 0)
						if (m[(j - 1) * n + i] == false)
						{
							M[j * n + i][(j - 1) * n + i] = 1;
							M[(j - 1) * n + i][j * n + i] = 1;
							m[(j - 1) * n + i] = 1;
							j--;
							Q = add(Q, i, j);
							k = -1;
						}
					break;
				}
				if (k == -1) break;
				if (k == 3) k = 0;
				else k++;
				z++;
			}
			z = 0;
		}
		else
		{
			if (Q->Next == NULL)
			{
				Q = del(Q);
				break;
			}
			i = Q->Next->x;
			j = Q->Next->y;
			Q = del(Q);
		}
	}

	free(m);
	return M;
}

char** Lgen(int** M, int n)
{
	int i, j, N = n * 2 + 1, x = 0, y = 0, s = 1;
	Node* Q = NULL;
	char** L;
	bool* m;

	m = (bool*)malloc(n * n * sizeof(bool));
	for (i = 0; i < n * n; i++)
	{
		m[i] = false;
	}

	L = (char**)malloc(N * sizeof(char*));
	for (i = 0; i < N; i++)
	{
		L[i] = (char*)malloc(N * sizeof(char));
	}

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			L[i][j] = '0';
		}
	}
	i = 1;
	j = 1;
	L[i][j] = ' ';
	m[0] = true;
	Q = add(Q, i, j);
	while (s != n * n)
	{
		while (true)
		{
			if (i != N - 2)
				if (M[((j - 1) / 2) * n + (i - 1) / 2 + 1][((j - 1) / 2) * n + (i - 1) / 2] == 1 && m[((j - 1) / 2) * n + (i - 1) / 2 + 1] == false)
				{
					m[((j - 1) / 2) * n + (i - 1) / 2 + 1] = true;
					L[j][i + 1] = ' ';
					L[j][i + 2] = ' ';
					i = i + 2;
					Q = add(Q, i, j);
					s++;
					break;
				}
			if (i != 1)
				if (M[((j - 1) / 2) * n + (i - 1) / 2 - 1][((j - 1) / 2) * n + (i - 1) / 2] == 1 && m[((j - 1) / 2) * n + (i - 1) / 2 - 1] == false)
				{
					m[((j - 1) / 2) * n + (i - 1) / 2 - 1] = true;
					L[j][i - 1] = ' ';
					L[j][i - 2] = ' ';
					i = i - 2;
					Q = add(Q, i, j);
					s++;
					break;
				}
			if (j != N - 2)
				if (M[(((j - 1) / 2) + 1) * n + (i - 1) / 2][((j - 1) / 2) * n + (i - 1) / 2] == 1 && m[(((j - 1) / 2) + 1) * n + (i - 1) / 2] == false)
				{
					m[(((j - 1) / 2) + 1) * n + (i - 1) / 2] = true;
					L[j + 1][i] = ' ';
					L[j + 2][i] = ' ';
					j = j + 2;
					Q = add(Q, i, j);
					s++;
					break;
				}
			if (j != 1)
				if (M[(((j - 1) / 2) - 1) * n + (i - 1) / 2][((j - 1) / 2) * n + (i - 1) / 2] == 1 && m[(((j - 1) / 2) - 1) * n + (i - 1) / 2] == false)
				{
					m[(((j - 1) / 2) - 1) * n + (i - 1) / 2] = true;
					L[j - 1][i] = ' ';
					L[j - 2][i] = ' ';
					j = j - 2;
					Q = add(Q, i, j);
					s++;
					break;
				}
			if (Q->Next == NULL)
			{
				Q = del(Q);
				break;
			}
			i = Q->Next->x;
			j = Q->Next->y;
			Q = del(Q);
			break;
		}
	}
	free(m);
	return L;
}
