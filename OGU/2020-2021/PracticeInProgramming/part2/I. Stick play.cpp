#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n(0), m(0);
	
	for (int i(0); i < 2; ++i)
	{
		if (i == 0)
			cin >> n;
		else
			cin >> m;
		cin.clear();
	}

	if (n > m)
		swap(n, m);

	int res = n % 2;

	if (res == 0)
		cout << "Malvika";
	else
		cout << "Akshat";

	return 0;
}
