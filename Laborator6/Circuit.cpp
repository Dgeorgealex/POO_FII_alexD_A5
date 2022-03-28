#include "Circuit.h"
#include <iostream>

using namespace std;

Circuit::Circuit()
{
	maxx = 100;
	index = 0;
	lenght = 0;
	vector = (Car**)(malloc(maxx * sizeof(Car*)));
}

bool Circuit::AddCar(Car* a)
{
	if (index < maxx)
	{
		vector[index++] = a;
		return 1;
	}
	return 0;
}

void Circuit::SetLength(int x)
{
	lenght = x;
}

void Circuit::Race()
{
	for (int i = 0; i < index; i++)
		vector[i]->go(lenght);
}

void Circuit::ShowFinalRanks()
{
	for (int i = 0; i < index; i++)
	{
		vector[i]->name();
		cout << ' ' << vector[i]->result;
		cout << '\n';
	}
	cout << '\n';
}

void Circuit::ShowWhoDidNotFinish()
{
	for (int i = 0; i < index; i++)
		if (vector[i]->result == -1)
		{
			vector[i]->name();
			cout << '\n';
		}
	cout << '\n';
}
