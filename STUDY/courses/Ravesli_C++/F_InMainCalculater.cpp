#include <iostream>
#include <conio.h>
using namespace std;

double enterValue()
{
	cout << "\tEnter a double value: ";
	double a;
	cin >> a;

	//Проверка на остаток в cin данных.
	if (cin.fail())
	{
		//возвращаем cin в обычный режим и чистим от ввода.
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "\n\tIncorrect input, please try again: \n";
	}
	else
	{
		//Удаляем лишние значения.
		cin.ignore(32767, '\n');
		return a;
	}
}

char enterOpearator()
{
	while (true)
	{
		cout << "\tEnter one of the following: +, -, * or /: ";
		char symbol;
		cin >> symbol;

		//Удаляем лишние символы
		cin.ignore(32767, '\n');

		//Проверяем введённое значение
		if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/')
			return symbol;			//Данные    верны, возвращаем в функцию main()
		else                        //Данные не верны, сообщаем, просим ввести снова.
			cout << "\n\tIncorrect input, please try again: \n";
	}
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
		cout << "\tMistake!" << endl; break;
	}
}

int main()
{
	char q = ' ';
	while (q != 'q')
	{
		setlocale(LC_ALL, "Russian");

		double n1 = enterValue();
		double n2 = enterValue();
		char simble = enterOpearator();
		writeRestult(n1, simble, n2);


		_getch();
		system("cls");
	}

	return 0;
}
