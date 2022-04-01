#pragma once
#include "Car.h"
#include "Weather.h"
class Mercedes : public Car
{
public:
	Mercedes();
	void go(int lenght, Weather a);
	void name();
};

