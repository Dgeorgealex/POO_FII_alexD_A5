#include <iostream>
#include "Sort.h"

using namespace std;

int main()
{
	Sort a1;
	a1.InsertSort();
	a1.Print();

	cout << "\n\n";

	char c[] = { "4,3,1,2" };
	Sort a2(c);
	a2.QuickSort();
	a2.Print();

	cout << "\n\n";

	int v[] = { 1, 3, 4, 2 };
	Sort a3(4, v);
	a3.BubbleSort(true);
	a3.Print();

	cout << "\n\n";

	Sort a4(4, 1, 4);
	a4.QuickSort(true);
	a4.Print();

	cout << "\n\n";

	Sort a5(4, 3, 2, 1, 4);
	a5.InsertSort();
	a5.Print();
}