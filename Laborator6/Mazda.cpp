#include "Mazda.h"
#include <stdio.h>
#include "Weather.h"

Mazda::Mazda()
{
	fuel = 100; //l
	fuelcon = 1;   //l/km
	speed[0] = 5; // km/h -> speed snow
	speed[1] = 10;  // km/h -> speed rain 
	speed[2] = 60;  // km/h -> speed sun
	result = -1;
}

void Mazda::go(int lenght, Weather a)
{
	if (lenght * fuelcon > fuel)
	{
		result = -1;
		return;
	}
	result = (float)lenght / speed[a];
}

void Mazda::name()
{
	printf("Mazda");
}