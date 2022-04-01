#pragma once
#include "Weather.h"
class Car
{
protected:
	int fuel, fuelcon;
	int speed[3];
	
public:
	float result;
	virtual void go(int lenght, Weather a) = 0;
	virtual void name() = 0;
};