#include "Mazda.h"
#include <stdio.h>

Mazda::Mazda()
{
	fuel = 100; //l
	fuelcon = 1;   //l/km
	speedrain = 10; // km/h
	speedsun = 60;  // km/h
	speedsnow = 2;  // km/h
	result = -1;
}

void Mazda::go(int lenght)
{
	if (lenght * fuelcon > fuel)
	{
		result = -1;
		return;
	}
	result = (float)lenght / speedsun;
}

void Mazda::name()
{
	printf("Mazda");
}