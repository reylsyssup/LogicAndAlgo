#include "Sys.h"

El* add(El* Q, int k)
{
	El* p;
	p = (struct El*)malloc(sizeof(struct El));
	p->v = k;
	p->Next = Q;
	Q = p;
	return Q;
}

El* del(El* Q)
{
	El* h;

	h = Q;
	Q = Q->Next;
	free(h);
	return Q;
}

Och* plus(Och* O, int k)
{
	El* p;

	p = (struct El*)malloc(sizeof(struct El));
	p->v = k;
	p->Next = NULL;
	O->End->Next = p;
	O->End = p;
	return O;
}

Och* min(Och* O)
{
	El* h;
	h = O->Head;
	O->Head = O->Head->Next;
	free(h);
	return O;
}

El* put(int** M, int n, El* Q)
{
	Och* O;
	int i, j;
	int* m;

	m = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++)
	{
		m[i] = -1;
	}

	O = (struct Och*)malloc(sizeof(struct Och));
	O->Head = (struct El*)malloc(sizeof(struct El));
	O->End = O->Head;

	plus(O, 0);
	m[0] = 0;
	while (O->End != O->Head)
	{
		j = O->Head->Next->v;
		min(O);
		for (i = 0; i < n; i++)
		{
			if (M[j][i] == 1 && m[i] == -1)
			{
				m[i] = m[j] + 1;
				plus(O, i);
			}
		}
		if (m[n - 1] != -1) break;
	}
	free(O->Head);
	free(O);

	int v = n - 1;
	Q = add(Q, v);
	while (v != 0)
	{
		for (i = 0; i < n; i++)
		{
			if (M[i][v] == 1 && m[i] == m[v] - 1)
			{
				v = i;
				Q = add(Q, v);
			}
		}
	}

	return Q;
}

void HZ(char** L, El* Q, int n, int** M, float hod)
{
	int i = 0, j = 0, x = 1, y = 1, N = n * 2 + 1, win = 0;
	clock_t S, E = 0;
	char name[31];
	FILE* F;

	Q = del(Q);
	L[N - 2][N - 2] = '$';
	while (Q != NULL)
	{
		system("cls");
		L[y][x] = '#';
		print_L(L, n * 2 + 1);
		L[(Q->v / n) * 2 + 1][(Q->v % n) * 2 + 1] = '+';
		if (L[j * 2 + 1][i * 2 + 1] != '#')
		{
			L[j * 2 + 1][i * 2 + 1] = ' ';
		}
		j = Q->v / n;
		i = Q->v % n;
		Q = del(Q);
		S = clock();
		while (float(E - S) / CLK_TCK < hod)
		{
			E = clock();
			if (_kbhit() == 1)
				switch (_getch())
				{
				case 72: if (L[y - 1][x] != '0')
				{
					if (L[y][x] != '+') L[y][x] = ' ';
					y = y - 1;
					L[y][x] = '#';
					system("cls");
					print_L(L, n * 2 + 1);
					if (L[N - 2][N - 2] == '#')
					{
						win = 1;
						break;
					}
				} break;
				case 75: if (L[y][x - 1] != '0')
				{
					if (L[y][x] != '+') L[y][x] = ' ';
					x = x - 2;
					L[y][x] = '#';
					system("cls");
					print_L(L, n * 2 + 1);
					if (L[N - 2][N - 2] == '#')
					{
						win = 1;
						break;
					}
				}
				break;
				case 80: if (L[y + 1][x] != '0')
				{
					if (L[y][x] != '+') L[y][x] = ' ';
					y = y + 2;
					L[y][x] = '#';
					system("cls");
					print_L(L, n * 2 + 1);
					if (L[N - 2][N - 2] == '#')
					{
						win = 1;
						break;
					}
				}
				break;
				case 77: if (L[y][x + 1] != '0')
				{
					if (L[y][x] != '+') L[y][x] = ' ';
					x = x + 2;
					L[y][x] = '#';
					system("cls");
					print_L(L, n * 2 + 1);
					if (L[N - 2][N - 2] == '#')
					{
						win = 1;
						break;
					}
				} 
				
				
				break;
				}
		}
		if (win == 1)
		{
			break;
		}
	}
	system("cls");
	print_L(L, n * 2 + 1);
	printf("\n\n");
	if (win == 1) 
	{
		printf("Вы победили");
	}
	else
	{
		printf("Вы не победили");
	}
	
}
