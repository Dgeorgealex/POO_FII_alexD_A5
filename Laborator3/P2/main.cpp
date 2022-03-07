#include "Canvas.h"
#include <iostream>


using namespace std;
int n, m;
int main()
{
	Canvas c(40, 30);
	
	c.DrawCircle(10, 15, 5, '*');
	c.Print();
	c.Clear();

	c.FillCircle(10, 15, 5, '*');
	c.Print();
	c.Clear();

	c.DrawRect(10, 10, 35, 20, '*');
	c.Print();
	c.Clear();

	c.FillRect(10, 10, 35, 20, '*');
	c.Print();
	c.Clear();

	c.SetPoint(25, 35, '*');
	c.Print();
	c.Clear();

	c.DrawLine(1, 0, 8, 20, '*');
	c.Print();
	c.Clear();
}