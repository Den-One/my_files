#include <iostream>
using namespace std;

// return the number mod
int rest(int a, int b)
{
	if (a < b)
		return a;
	else
		return rest(a - b, b);
}

// It takes back the greatest common divisor
int comDivisor(int a, int b)
{
	if (b == 0)
		return a;
	else
		return comDivisor(b, rest(a, b));
}

int main()
{
	int num1, num2;
	cout << "Imput 2 numbers: ";
	cin >> num1;
	cin >> num2;
	cout << "NOD: " << comDivisor(num1, num2) << endl;

	system("pause");
	return 0;
}
