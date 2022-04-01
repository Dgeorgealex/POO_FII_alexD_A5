#pragma once
#include "Car.h"
#include "Weather.h"
class Dacia : public Car
{
public:
	Dacia();
	void go(int lenght, Weather a);
	void name();
};

