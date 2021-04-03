#include <iostream>
#include <string>
using namespace std;

int main()
{
	int friends(0), high(0);
	cin >> friends;
	cin >> high;
	cin.ignore(32676, '\n');

	int result(0);
	int arr[2001] = {};
	for (int i(0); i < friends; ++i)
	{
		cin >> arr[i];
		if (arr[i] <= high)
			result++;
		else
			result = result + 2;
	}

	cout << result;

	return 0;
}
