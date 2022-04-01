#pragma once
#include "Car.h"
#include "Weather.h"
#include <iostream>

class Circuit
{
private:
	Car** vector; 
	int maxx;
	int index;
	int lenght;
	Weather vreme;

public:
	Circuit();
	bool AddCar(Car* masina);
	void SetLength(int x);
	void SetWeather(Weather a);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
};

