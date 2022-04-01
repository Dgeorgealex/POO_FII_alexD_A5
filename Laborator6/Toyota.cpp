#include "Toyota.h"
#include <stdio.h>
#include "Weather.h"
Toyota::Toyota()
{
	fuel = 10; //l
	fuelcon = 10;   //l/km
	speed[0] = 10; // km/h -> speed snow
	speed[1] = 80;  // km/h -> speed rain 
	speed[2] = 100;  // km/h -> speed sun
	result = -1;
}

void Toyota::go(int lenght, Weather a)
{
	if (lenght * fuelcon > fuel)
	{
		result = -1;
		return;
	}
	result = (float)lenght / speed[a];
}

void Toyota::name()
{
	printf("Toyota");
}