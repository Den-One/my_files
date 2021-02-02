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

class Car
{
private:
	string m_company = "";
	string m_model = "";

public:
	Car(string comp = "", string mod = ""): m_company(comp), m_model(mod) {}

	friend bool operator== (Car& v1, Car& v2);
	friend bool operator!= (Car & v1, Car & v2);
	friend istream& operator>> (istream& in, Car& v1);

	friend bool operator> (const Car& c1, const Car& c2);
	friend bool operator>= (const Car& c1, const Car& c2);
	friend bool operator< (const Car& c1, const Car& c2);
	friend bool operator<= (const Car& c1, const Car& c2);
};

bool operator> (const Car& c1, const Car& c2)
{
	return c1.m_company > c1.m_company;
}

bool operator>= (const Car& c1, const Car& c2)
{
	return c1.m_company >= c2.m_company;
}
bool operator< (const Car& c1, const Car& c2)
{
	return c1.m_company < c2.m_company;
}
bool operator<= (const Car& c1, const Car& c2)
{
	return c1.m_company <= c2.m_company;
}

istream& operator>> (istream& in, Car& v1)
{
	in >> v1.m_company;
	in >> v1.m_model;

	return in;
}

bool operator== (Car& v1, Car& v2)
{
	return (v1.m_company == v2.m_company && v1.m_model == v2.m_model);
}

bool operator!= (Car& v1, Car& v2)
{
	return !(v1 == v2);
}

class Number
{
private:
	int m_number;

public:
	Number(int number = 0) :m_number(number) {}

	Number& operator++();
	Number& operator--();

	friend ostream& operator<< (ostream& out, Number& v1);
};

Number& Number::operator++()
{
	if (m_number == 10)
		m_number = 0;
	else
		++m_number;

	return *this;
}

Number& Number::operator--()
{
	if (m_number == 0)
		m_number = 10;
	else
		--m_number;

	return *this;
}

ostream& operator<< (ostream& out, Number& v1)
{
	out << v1.m_number;
	return out;
}

int main()
{
	Number num(6);
	cout << ++num << endl;
	cout << ++num << endl;
	cout << --num << endl;
	cout << --num << endl;

	cout << "Input the names of company and mark's car twice: \n";

	Car mustang;
	cin >> mustang;
	Car logan;
	cin >> logan;

	if (mustang == logan)
		cout << "Names are the same.\n";
	if (mustang != logan)

		cout << "Names aren't the same.\n";

	if (mustang > logan)
		cout << "Mustang are greater than logan\n";
	if (mustang >= logan)
		cout << "Mustang are greater than logan or equal\n";
	if (mustang < logan)
		cout << "Logan are greater than mustang\n";
	if (mustang <= logan)
		cout << "Logan are greater than mustang or euqal\n";
}
