#include "Dacia.h"
#include <stdio.h>

Dacia::Dacia()
{
	fuel = 100; //l
	fuelcon = 1;   //l/km
	speed[0] = 10; // km/h -> speed snow
	speed[1] = 80;  // km/h -> speed rain 
	speed[2] = 100;  // km/h -> speed sun
	result = -1;
}

void Dacia::go(int lenght, Weather a)
{
	if (lenght * fuelcon > fuel)
	{
		result = -1;
		return;
	}
	result = (float)lenght / speed[a];
}

void Dacia::name()
{
	printf("Dacia");
}