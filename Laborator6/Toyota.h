#pragma once
#include "Car.h"
#include "Weather.h"
class Toyota : public Car
{
public:
	Toyota();
	void go(int lenght, Weather a);
	void name();
};

