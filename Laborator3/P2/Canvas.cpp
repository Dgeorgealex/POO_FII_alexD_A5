#include "Canvas.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

Canvas::Canvas(int width, int height)
{
	n = height;
	m = width;
	a = (char**)(malloc(n * sizeof(char*)));
	for (int i = 0; i < n; i++)
		a[i] = (char*)(malloc(m * sizeof(char)));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			a[i][j] = ' ';
}

void Canvas::Print()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << a[i][j];
		cout << '\n';
	}
}

void Canvas::Clear()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			a[i][j] = ' ';
}

void Canvas::SetPoint(int x, int y, char ch)
{
	a[x][y] = ch;
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	for(int i=0; i<n; i++)
		for (int j = 0; j < m; j++)
		{
			int ip = (i - x) * (i - x) + (j - y) * (j - y);
			if (ip >= ray * (ray - 1) && ip <= ray * (ray + 1))
				a[i][j] = ch;
		}
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	for(int i=0;i<n;i++)
		for (int j = 0; j < m; j++)
		{
			int ip = (i - x) * (i - x) + (j - y) * (j - y);
			if (ip <= ray * ray)
				a[i][j] = ch;
		}
}

void Canvas::DrawRect(int y1, int x1, int y2, int x2, char ch)
{
	for (int i = x1; i <= x2; i++)
		a[i][y1] = a[i][y2] = ch;

	for (int j = y1; j <= y2; j++)
		a[x1][j] = a[x2][j] = ch;
}

void Canvas::FillRect(int y1, int x1, int y2, int x2, char ch)
{
	for (int i = x1; i <= x2; i++)
		for (int j = y1; j <= y2; j++)
			a[i][j] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	int dx = x2 - x1;
	int dy = y2 - y1;
	//lucrez oarecum invers
	int D = 2 * dx - dy;
	int x = x1;

	for (int y = y1; y <= y2; y++)
	{
		a[x][y] = ch;
		if (D > 0)
		{
			x = x + 1;
			D = D - 2 * dy;
		}
		D = D + 2 * dx;
	}
}