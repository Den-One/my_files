#include <iostream>
#include <string>
using namespace std;

int main()
{
	int calorie[4] = {};

	int number(0);
	for (int i(0); i < 4; ++i)
	{
		cin >> number;
		calorie[i] = number;
		cin.clear();
	}
	cin.ignore(32767, '\n');

	string str;
	getline(cin, str);
	int length = str.size();
	int result(0);
	for (int i(0); i < length; ++i)
	{
		if (str[i] == '1')
		{
			result = result + calorie[0];
		}

		if (str[i] == '2')
		{
			result = result + calorie[1];
		}

		if (str[i] == '3')
		{
			result = result + calorie[2];
		}

		if (str[i] == '4')
		{
			result = result + calorie[3];
		}
	}

	cout << result;

	return 0;
}
