#include "Dacia.h"
#include <stdio.h>

Dacia::Dacia()
{
	fuel = 100; //l
	fuelcon = 1;   //l/km
	speedrain = 10; // km/h
	speedsun = 30;  // km/h
	speedsnow = 2;  // km/h
	result = -1;
}

void Dacia::go(int lenght)
{
	if (lenght * fuelcon > fuel)
	{
		result = -1;
		return;
	}
	result = (float)lenght / speedsun;
}

void Dacia::name()
{
	printf("Dacia");
}