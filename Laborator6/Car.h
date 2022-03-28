#pragma once
class Car
{
protected:
	int fuel, fuelcon;
	int speedrain, speedsun, speedsnow;
	
public:
	float result;
	virtual void go(int lenght) = 0;
	virtual void name() = 0;
};