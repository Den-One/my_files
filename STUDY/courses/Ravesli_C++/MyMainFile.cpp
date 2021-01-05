#include <iostream>
#include <conio.h>
using namespace std;

double enterValue()
{
	cout << "\tEnter a double value: ";
	int a;
	cin >> a;

	return a;
}

char enterOpearator()
{
	cout << "\tEnter one of the following: +, -, * or /: ";
	char simble;
	cin >> simble;

	return simble;
}

void writeRestult(double n1, char simble, double n2)
{
	switch (simble)
	{
	case '+':
		cout << "\t" << n1 << " " << simble << " " << n2 << " = " << n1 + n2; break;
	case '-':
		cout << "\t" << n1 << " " << simble << " " << n2 << " = " << n1 - n2; break;
	case '*':
		cout << "\t" << n1 << " " << simble << " " << n2 << " = " << n1 * n2; break;
	case '/':
		cout << "\t" << n1 << " " << simble << " " << n2 << " = " << n1 / n2; break;
	default:
		cout << "Mistake!" << endl; break;
	}
}

int main()
{
	char q = ' ';
	while (q != 'q')
	{
		setlocale(LC_ALL, "Russian");

		double n1    = enterValue();
		double n2    = enterValue();
		char simble  = enterOpearator();
		writeRestult(n1, simble, n2);
		

		_getch();
		system("cls");
	}

	return 0;
}