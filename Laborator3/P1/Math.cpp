#include "Math.h"
#include <cstdarg>
#include <cstring>

int Math::Add(int x, int y)
{
	return x + y;
}
int Math::Add(int x, int y, int z)
{
	return x + y + z;
}
int Math::Add(double x, double y)
{
	return x + y;
}
int Math::Add(double x, double y, double z)
{
	return x + y + z;
}
int Math::Mul(int x, int y)
{
	return x * y;
}
int Math::Mul(int x, int y, int z)
{
	return x * y * z;
}
int Math::Mul(double x, double y)
{
	return x * y;
}
int Math::Mul(double x, double y, double z)
{
	return x * y * z;
}
int Math::Add(int count, ...)
{
	int rez = 0;
	std::va_list arg;
	va_start(arg, count);
	for (int i = 0; i < count; i++)
	{
		rez += va_arg(arg, int);
	}
	va_end(arg);
	return rez;
}

char *Math::Add(const char *a, const char *b)
{
	char *c = new char(100);
	if (a == nullptr || b == nullptr)
		return nullptr;
	strcpy_s(c, 100, a);
	strcat_s(c, 100, b);
	return c;
}