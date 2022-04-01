#pragma once
#include "Car.h"
#include "Weather.h"
class Mazda : public Car
{
public:
	Mazda();
	void go(int lenght, Weather a);
	void name();
};

