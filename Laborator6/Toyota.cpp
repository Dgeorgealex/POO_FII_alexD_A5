#include "Toyota.h"
#include <stdio.h>

Toyota::Toyota()
{
	fuel = 10; //l
	fuelcon = 10;   //l/km
	speedrain = 10; // km/h
	speedsun = 30;  // km/h
	speedsnow = 2;  // km/h
	result = -1;
}

void Toyota::go(int lenght)
{
	if (lenght * fuelcon > fuel)
	{
		result = -1;
		return;
	}
	result = (float)lenght / speedsun;
}

void Toyota::name()
{
	printf("Toyota");
}