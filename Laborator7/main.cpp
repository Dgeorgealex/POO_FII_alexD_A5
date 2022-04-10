#include <iostream>
#include "tvector.h"

using namespace std;

float operator"" _Kelvin(unsigned long long x) 
{
	return (float)x - 273.15f;
}
float operator""_Farenheit(unsigned long long x)
{
	return ((float)x - 32.0f) / 1.8f;
}


int main()
{
	float a = 300_Kelvin;
	float b = 120_Farenheit;
	cout << a << '\n' << b << "\n\n";
	
	tvector<char> v;
	v.push('a');
	v.push('b');
	v.push('c');
	v.sort(compare);
	v.print();
	cout << v.firstIndexOf('a', paritate);
	return 0;
}
