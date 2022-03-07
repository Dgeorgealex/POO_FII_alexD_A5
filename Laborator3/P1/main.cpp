#include <iostream>
#include "Math.h"

using namespace std;

int a, b, c, d;
double aa, bb, cc, dd;
char ca[100], cb[100];
int main()
{
	cin >> ca >> cb;
	cin >> a >> b >> c >> d;
	cin >> aa >> bb >> cc >> dd;
	cout << Math::Add(a, b) << '\n';
	cout << Math::Add(a, b, c) << '\n';
	cout << Math::Mul(aa, bb) << '\n';
	cout << Math::Add(ca, cb) << '\n';
}