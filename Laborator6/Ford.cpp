#include "Ford.h"
#include "Weather.h"
#include <stdio.h>

Ford::Ford()
{ 
	fuel = 100; //l
	fuelcon = 10;   //l/km
	speed[0] = 10; // km/h -> speed snow
	speed[1] = 50;  // km/h -> speed rain 
	speed[2] = 120;  // km/h -> speed sun
	result = -1;
}

void Ford::go(int lenght, Weather a)
{
	if (lenght * fuelcon > fuel)
	{
		result = -1;
		return;
	}
	result = (float)lenght / speed[a];
}

void Ford::name()
{
	printf("Ford");
}