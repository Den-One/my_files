#include <iostream>
#include <array>
#include <string>
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

class Dollars
{
private:
	int m_dollars;

public:
	Dollars(int dollars = 0) { m_dollars = dollars; }

	operator int() { return m_dollars; }

	int getDollars() { return m_dollars; }
	void setDollars(int dollars) { m_dollars = dollars; }
};

void printInt(int value)
{
	cout << value;
}

class Cents
{
private:
	int m_cents;
public:
	Cents(int cents = 0) {m_cents = cents;}

	operator Dollars() { return Dollars(m_cents / 100); }
};

void printDollars(Dollars dollars)
{
	cout << dollars;
}

int main()
{
	Cents cents(800);
	printDollars(cents);

	return 0;
}
