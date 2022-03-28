#pragma once
#include "Car.h"
#include <iostream>

class Circuit
{
private:
	Car** vector; 
	int maxx;
	int index;
	int lenght;

public:
	Circuit();
	bool AddCar(Car* masina);
	void SetLength(int x);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
};

