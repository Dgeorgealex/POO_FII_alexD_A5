#include "Ford.h"
#include <stdio.h>

Ford::Ford()
{
	fuel = 100; //l
	fuelcon = 10;   //l/km
	speedrain = 10; // km/h
	speedsun = 50;  // km/h
	speedsnow = 2;  // km/h
	result = -1;
}

void Ford::go(int lenght)
{
	if (lenght * fuelcon > fuel)
	{
		result = -1;
		return;
	}
	result = (float)lenght / speedsun;
}

void Ford::name()
{
	printf("Ford");
}