#include <iostream>
#include <string>
using namespace std;

int main()
{
	int arr[4] = {};

	int key;
	for (int i(0); i < 4; ++i)
	{
		cin >> key;
		arr[i] = key;
		cin.clear();
	}

	int result(0);
	while (arr[0] > 0 && arr[2] > 0 && arr[3] > 0)
	{
		result = result + 256;
		arr[0] = arr[0] - 1;
		arr[2] = arr[2] - 1;
		arr[3] = arr[3] - 1;
	}

	while (arr[0] > 0 && arr[1] > 0)
	{
		result = result + 32;
		arr[0] = arr[0] - 1;
		arr[1] = arr[1] - 1;
	}

		cout << result;

	return 0;
}
