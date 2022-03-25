#include "Number.h"
#include <cstring>
#include <iostream>

using namespace std;

Number :: ~Number()
{
	delete[] c;
	c = nullptr;
}

Number::Number(const char* value, int base)
{
	n = strlen(value);
	c = new char[n];
	b = base;
	for (int i = 0; i < n; i++)
		c[i] = value[i];
}

int Number::GetDigitsCount()
{
	return n;
}

int Number::GetBase()
{
	return b;
}

char Number::operator[](int index)
{
	return c[index];
}

void Number::Print()
{
	for (int i = 0; i < n; i++)
		cout << c[i];
	cout << '\n';
}



void Number::SwitchBase(int base)
{
	if (b == base)
		return;

	if (n == 1 && c[0] == '0')
	{
		b = base;
		return;
	}
	
	long long x = tozece();
	b = base;
	fromzece(x);
}

/// constructor copiere
Number::Number(const Number& a)
{
	n = a.n;
	b = a.b;
	c = new char[n];
	memcpy(c, a.c, a.n);
}

/// constructor move
Number::Number(Number&& a)
{
	n = a.n;
	b = a.b;
	c = a.c;
	a.c = nullptr;
}
Number::Number(int a)
{
	c = nullptr;
	b = 10;
	fromzece(a);
}

/// egal copy
Number& Number::operator=(const Number& a)
{
	n = a.n;
	b = a.b;
	delete[] c;
	c = new char[n];
	memcpy(c, a.c, a.n);
	return(*this);
}
// egal move
Number& Number::operator=(Number&& a)
{
	n = a.n;
	b = a.b;
	c = a.c;
	a.c = nullptr;
	return(*this);
}

Number& Number::operator=(int a)
{
	fromzece(a);
	return (*this);
}

Number& Number::operator+=(Number a)
{
	long long tzece = this->tozece(), azece = a.tozece();
	b = max(b, a.b);
	fromzece(tzece+azece);
	return (*this);
}

Number& Number::operator=(const char* a)
{
	n = strlen(a);
	delete[] c;
	c = new char[n];
	for (int i = 0; i < n; i++)
		c[i] = a[i];
	return (*this);
}

//add function (friend)
Number operator+(Number a, Number b)
{
	Number s;
	s.b = max(a.b, b.b);
	long long azece = a.tozece(), bzece=b.tozece();
	long long rez = azece + bzece;
	s.fromzece(azece + bzece);
	return s;
}

//minus function (friend)
Number operator-(Number a, Number b)
{
	Number s;
	s.b = max(a.b, b.b);
	long long azece = a.tozece(), bzece = b.tozece();
	long long rez = azece - bzece;
	rez = min(rez, (long long)0);
	s.fromzece(rez);
	return s;
}

long long Number::tozece()
{
	long long p = 1, nr = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		if (isdigit(c[i]))
			nr = nr + p * (c[i] - '0');
		else
			nr = nr + p * (c[i] - 'A' + 10);
		p = p * b;
	}
	return nr;
}

void Number::fromzece(long long x)
{
	long long aux = x;
	n = 0;
	while (aux)
	{
		aux /= b;
		n++;
	}

	delete[]c;
	c = new char[n];

	int k = n;
	while (x)
	{
		int r = x % b;
		if (r > 9)
			c[--k] = 'A' + r - 10;
		else c[--k] = '0' + r;
		x = x / b;
	}
}

void Number::operator--()
{
	if (n == 1)
		return;
	n--;
	for (int i = 0; i < n; i++)
		c[i] = c[i + 1];
}

void Number::operator--(int val)
{
	if (n == 1)
		return;
	n--;
}

// Operatori compare
bool Number::operator==(Number& a)
{
	if (a.tozece() == this->tozece())
		return 1;
	return 0;
}
bool Number::operator<(Number& a)
{
	if (a.tozece() > this->tozece())
		return 1;
	return 0;
}
bool Number::operator>(Number& a)
{
	if (a.tozece() < this->tozece())
		return 1;
	return 0;
}