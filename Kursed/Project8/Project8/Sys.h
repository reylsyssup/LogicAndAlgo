#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <math.h>

struct Node
{
	int x, y;
	Node* Next;
};

struct El
{
	int v;
	El* Next;
};


struct Och
{
	El* Head;
	El* End;
};


int** gen(int n);
char** Lgen(int** M, int n);
void print_L(char** M, int n);
El* put(int** M, int n, El* Q);
void HZ(char** L, El* Q, int n, int** M, float hod);
void dvigat_1();
void stand();
void start();
void save(char* lab, int n, int** M);
void sloj(int k);
