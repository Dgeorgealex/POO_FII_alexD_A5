#include "Mercedes.h"
#include <stdio.h>
#include "Weather.h"
Mercedes::Mercedes()
{
	fuel = 100; //l
	fuelcon = 1;   //l/km
	speed[0] = 10; // km/h -> speed snow
	speed[1] = 100;  // km/h -> speed rain 
	speed[2] = 150;  // km/h -> speed sun
	result = -1;
}

void Mercedes::go(int lenght, Weather a)
{
	if (lenght * fuelcon > fuel)
	{
		result = -1;
		return;
	}
	result = (float)lenght / speed[a];
}

void Mercedes::name()
{
	printf("Mercedes");
}