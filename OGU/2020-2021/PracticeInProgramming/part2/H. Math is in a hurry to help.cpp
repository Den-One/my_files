#include <iostream>
#include <string>
using namespace std;

int main()
{
	int arr[3] = { 0, 0, 0 };

	string str;
	getline(cin, str);

	int length = str.size();;
	for (int i(0); i < length; ++i)
	{
		if (str[i] == '1')
			arr[0] = arr[0] + 1;

		if (str[i] == '2')
			arr[1] = arr[1] + 1;

		if (str[i] == '3')
			arr[2] = arr[2] + 1;
	}

	int numberOfsymbls(0);
	for (int i(0); i < 3; ++i)
	{
		numberOfsymbls += arr[i];
	}

	int save = numberOfsymbls;
	--save;

	while (arr[0] > 0 && save > 0)
	{
		cout << "1+";
		arr[0] = arr[0] - 1;
		save = save - 1;
	}

	while (arr[1] > 0  && save > 0)
	{
			cout << "2+";
			arr[1] = arr[1] - 1;
			save = save - 1;
	}

	while (arr[2] > 0 && save > 0)
	{
			cout << "3+";
			arr[2] = arr[2] - 1;
			save = save - 1;
	}

	if (arr[0] > 0)
	{
		cout << "1";
		arr[0] -= 1;
	}

	if (arr[1] > 0)
	{
		cout << "2";
		arr[1] -= 1;
	}

	if (arr[2] > 0)
	{
		cout << "3";
		arr[2] -= 2;
	}

	return 0;
}
