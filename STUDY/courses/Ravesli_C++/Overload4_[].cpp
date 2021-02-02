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

class IntArray
{
private:
	int m_array[10];

public:
	int& operator[] (const int i);
};

int& IntArray::operator[] (const int i)
{
	return m_array[i];
}

int main()
{
	IntArray array;
	array[4] = 5;
	cout << array[4];

	return 0;
}
