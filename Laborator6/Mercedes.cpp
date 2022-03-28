#include "Mercedes.h"
#include <stdio.h>

Mercedes::Mercedes()
{
	fuel = 100; //l
	fuelcon = 1;   //l/km
	speedrain = 10; // km/h
	speedsun = 100;  // km/h
	speedsnow = 2;  // km/h
	result = -1;
}

void Mercedes::go(int lenght)
{
	if (lenght * fuelcon > fuel)
	{
		result = -1;
		return;
	}
	result = (float)lenght / speedsun;
}

void Mercedes::name()
{
	printf("Mercedes");
}