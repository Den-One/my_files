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

string m_inf = "";

//Overload +
class Dollars
{
private:
	int m_dol;

public:

	Dollars(int doll) : m_dol(doll) {}
	int getDollars() const { return m_dol; }

	//Overload with friend-function +
	friend Dollars operator+(const Dollars& v1, const Dollars& v2);
	friend Dollars operator-(const Dollars& v1, const Dollars& v2);
	friend Dollars operator*(const Dollars& v1, const Dollars& v2);
	friend Dollars operator/(const Dollars& v1, const Dollars& v2);

	friend ostream& operator<< (ostream& out, const Dollars& v1);
};

//return the sum
Dollars operator+(const Dollars& v1, const Dollars& v2)
{
	m_inf = "sum";
	return Dollars(v1.m_dol + v2.m_dol);
}

Dollars operator-(const Dollars& v1, const Dollars& v2)
{
	m_inf = "sub";
	return Dollars(v1.m_dol - v2.m_dol);
}

Dollars operator*(const Dollars& v1, const Dollars& v2)
{
	m_inf = "mul";
	return Dollars(v1.m_dol * v2.m_dol);
}

// It using getDollars
Dollars operator/(const Dollars& v1, const Dollars& v2)
{
	m_inf = "div";
	return Dollars(v1.getDollars() / v2.getDollars());
}

ostream& operator<< (ostream& out, const Dollars& v1)
{
	out << "The number " << v1.m_dol << " was used like " << m_inf << endl;
	return out;
}

void print(Dollars& smth)
{
	cout << "The result of " << m_inf << " is " << smth.getDollars() << endl;
}

class Point
{
private:
	int m_x;
	int m_y;
	int m_z;

public:
	Point(int x=0, int y=0, int z=0): m_x(x), m_y(y), m_z(z) {}

	friend ostream& operator<< (ostream& out, const Point& v1);
	friend istream& operator>> (istream& in, Point& v1);
};

ostream& operator<< (ostream& out, const Point& v1)
{
	cout << "Point(" << v1.m_x << ", " << v1.m_y << ", " << v1.m_z << ")\n";
	return out;
}

istream& operator>> (istream &in, Point& v1)
{
	in >> v1.m_x;
	in >> v1.m_y;
	in >> v1.m_z;

	return in;
}

class Value
{
private:
	int m_a=0;
	int m_b=0;

public:
	Value(int a=0, int b=0): m_a(a), m_b(b) {}
	

	friend ostream& operator<< (ostream& out, const Value& v);
	friend istream& operator>> (istream& in, Value& v);
};

istream& operator>> (istream &in, Value &v)
{
	in >> v.m_a;
	in >> v.m_b;

	return in;
}

ostream& operator<< (ostream& out, const Value& v)
{
	out <<  v.m_a << " + " << v.m_b << " = " << v.m_a + v.m_b << endl;
	return out;
}

int main()
{

	Value q;
	cin >> q;
	cout << q;

	Dollars d1(5);
	Dollars d2(10);

	Dollars sum = d2 + d1;
	print(sum);

	Dollars d5(3);
	cout << d5;

	Dollars sub = d2 - d1;
	print(sub);

	Dollars mul = d2 * d1;
	print(mul);

	Dollars div = d2 / d1;
	print(div);

	Point p;
	cin >> p;
	cout << p;

	return 0;
}