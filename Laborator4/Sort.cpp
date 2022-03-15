#define _CRT_SECURE_NO_WARNINGS
#include "Sort.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <stdarg.h>
#include <cstring>


using namespace std;

int Sort::GetElementsCount()
{
	return n;
}

int Sort::GetElementFromIndex(int index)
{
	return v[index];
}

void Sort::Print()
{
	for (int i = 0; i < n; i++)
		cout << v[i] << ' ';
	
	cout << '\n';
}

bool Sort::cmp(int a, int b, bool ascendent)
{
	if (ascendent)
		return a > b;
	return a < b;
}

void Sort::InsertSort(bool ascendent)
{
	for (int i = 0; i < n; i++)
	{
		int j = i;
		while (j > 0 && cmp(v[j - 1], v[j], ascendent))
		{
			swap(v[j - 1], v[j]);
			j--;
		}
	}
}

void Sort::BubbleSort(bool ascendent)
{
	bool ok = 1;
	while (ok)
	{
		ok = 0;
		for (int i = 0; i < n - 1; i++)
			if (cmp(v[i], v[i + 1], ascendent))
			{
				swap(v[i], v[i + 1]);
				ok = 1;
			}
	}
}

int Sort::partition(int st, int dr, bool ascendent)
{
	int pivot = v[dr];
	int poz = st;
	for(int i=st; i<dr;i++)
		if (!cmp(v[i], pivot, ascendent))
		{
			swap(v[i], v[poz]);
			poz++;
		}
	swap(v[poz], v[dr]);
	return poz;
}

void Sort::quick(int st, int dr, bool ascendent)
{
	if (st > dr)
		return;
	int p = partition(st, dr, ascendent);
	quick(st, p - 1, ascendent);
	quick(p + 1, dr, ascendent);
}
void Sort::QuickSort(bool ascendent)
{
	quick(0, n-1, ascendent);
}


//Constructorii
Sort::Sort() : v(new int[6]{ 1, 2, 3, 4, 5, 6 }), n(6) {}

Sort::Sort(int n, int min, int max)
{
	srand(time(NULL));
	this->n = n;
	v = new int[n];
	for (int i = 0; i < n; i++)
		v[i] = rand() % max + min;
}

Sort::Sort(int n, ...)
{
	this->n = n;
	this->v = new int[n];
	va_list v;
	va_start(v, n);
	for (int i = 0; i < n; i++)
		this->v[i] = va_arg(v, int);
	va_end(v);
}

Sort::Sort(char* c)
{
	int lg = strlen(c), k = 0;
	for (int i = 0; i < lg; i++)
		if (c[i] == ',')
			n++;
	n++;
	v = new int[n];
	char* p = strtok(c, ",");
	while (p != NULL)
	{
		v[k++] = atoi(p);
		p = strtok(NULL, ",");
	}
}
Sort::Sort(int n, int* v)
{
	this->n = n;
	this->v = new int[n];
	for (int i = 0; i < n; i++)
		this->v[i] = v[i];
}