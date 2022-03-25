#pragma once
class Number
{
private:
	char *c;
	int n, b;

	long long tozece();
	void fromzece(long long x);

public:

	Number(): n(0), b(10), c(nullptr) {};
	Number(const char* value, int base); // where base is between 2 and 16
	~Number();
	

	// add operators and copy/move constructor
	Number(const Number& a);
	Number(Number&& a);
	Number(int a);
	char operator[](int index);


	friend Number operator+(Number a, Number b);
	friend Number operator-(Number a, Number b);

	Number& operator=(const Number& a);
	Number& operator=(Number&& a);
	Number& operator=(int a);
	Number& operator+=(Number a);
	Number& operator=(const char* a);

	bool operator==(Number& a);
	bool operator<(Number& a);
	bool operator>(Number& a);

	
	void operator--();
	void operator--(int val);

	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base
};
