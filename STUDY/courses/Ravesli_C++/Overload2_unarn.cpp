#include <iostream>
#include <array>
#include <ctime> // fortime()
#include <cstdlib> // forrand() &srand()
#include <cassert> // forassert()
#include <conio.h>


//****ПЕРЕГРУЗКА ОПЕРАТОРОВ 3 СПОСОБА****
//***************************************
// - дружественные функции - friend Smth() { }
// - обычные функции - 
// - методы класса 

using namespace std;

class Value
{
private:
	int m_value;

public:
	Value(int value) { m_value = value; }

	Value operator+(int value);

	int getDollars() { return m_value; }
};

Value Value::operator+(int value)
{
	return Value(m_value + value);
}

class Dollars
{
private:
	int m_dollars;

public:
	Dollars(int dollars) { m_dollars = dollars; }

	Dollars operator-() const;
	int getDollars() const { return m_dollars; }
};

Dollars Dollars::operator-() const
{
	return Dollars(-m_dollars);
}

class Something
{
private:
	double m_a, m_b, m_c;

public:
	Something(double a = 0.0, double b = 0.0, double c = 0.0):
		m_a(a), m_b(b), m_c(c) {}

	Something operator- () const
	{
		return Something(-m_a, -m_b, -m_c);
	}

	bool operator! () const
	{
		return (m_a == 0.0 && m_b == 0.0 && m_c == 0.0);
	}

	double getA() { return m_a; }
	double getB() { return m_b; }
	double getC() { return m_c; }

	friend istream& operator>> (istream &in, Something& v2);
};

istream& operator>> (istream &in, Something &v2)
{
	in >> v2.m_a;
	in >> v2.m_b;
	in >> v2.m_c;
	
	return in;
}

int main()
{
	Value v1(5);
	Value v2 = v1 + 25;
	cout << "I have " << v2.getDollars() << " dollars.\n";

	const Dollars dollars1(7);
	
	cout << "My debt is " << (-dollars1).getDollars() << " dollars.\n";

	Something smth;
	cin >> smth;

	if (!smth)
		cout << "Something is null!" << endl;
	else
		cout << "Something isn't null!" << endl;

	return 0;
}
