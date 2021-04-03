#include <iostream>
#include <string>
using namespace std;

int main()
{
	int number(0), answ(0), result(0);
	cin >> number;
	cin.ignore(32767, '\n');

	int groups[4] = {};
	for (int i(0); i < number; ++i)
	{
		cin >> answ;
		if (answ == 1)
			groups[0] = groups[0] + 1;
		if (answ == 2)
			groups[1] = groups[1] + 1;
		if (answ == 3)
			groups[2] = groups[2] + 1;
		if (answ == 4)
		{
			groups[3] = groups[3] + 1;
			result = result + 1;
		}

		cin.clear();
	}

	while (groups[2] > 0 && groups[0] > 0)
	{
		result = result + 1; // 3 + 1
		groups[2] = groups[2] - 1;
		groups[0] = groups[0] - 1;
	}

	while (groups[2] > 0 && groups[0] == 0)
	{
		result = result + 1; // 3
		groups[2] = groups[2] - 1;
	}

	while (groups[1] > 1)
	{
		result = result + 1; // 2 + 2
		groups[1] = groups[1] - 2;
	}

	while (groups[1] > 0 && groups[0] > 1)
	{
		result = result + 1; // 2 + 1 + 1
		groups[1] = groups[1] - 1;
		groups[0] = groups[0] - 2;
	}

	while (groups[1] > 0 && groups[0] == 1)
	{
		result = result + 1; // 2 + 1
		groups[1] = groups[1] - 1;
		groups[0] = groups[0] - 1;
	}

	while (groups[1] > 0 && groups[0] == 0)
	{
		result = result + 1; // 2
		groups[1] = groups[1] - 1;
	}

	while (groups[0] > 3)
	{
		result = result + 1; // 1 + 1 + 1 + 1
		groups[0] = groups[0] - 4;
	}

	while (groups[0] > 2)
	{
		result = result + 1; // 1 + 1 + 1 
		groups[0] = groups[0] - 3;
	}

	while (groups[0] > 1)
	{
		result = result + 1; // 1 + 1
		groups[0] = groups[0] - 2;
	}

	while (groups[0] > 0)
	{
		result = result + 1; // 1
		groups[0] = groups[0] - 1;
	}

	cout << result;

	return 0;
}
