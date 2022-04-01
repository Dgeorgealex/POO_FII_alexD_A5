#pragma once
#include "Car.h"
#include "Weather.h"
class Ford : public Car
{
public:
	Ford();
	void go(int lenght, Weather a);
	void name();
};

