#include <iostream>
#include <string>
using namespace std;
int main()
{
	int street[3] = {};
	int result(0);

	for (int i(0); i < 3; ++i)
	{
		cin >> street[i];
		cin.clear();
	}

	if (street[0] > street[1]) // the first shop always in st[0]
		swap(street[0], street[1]); 
	result = result + street[0]; // visited first shop 

	if (street[1] + street[0] > street[2])
		result = result + street[2]; //visited shop 2 without getting home
	else
	{
		result = result + street[0]; // got back home
		result = result + street[1]; // visited the shop 2
	}

	if (street[0] + street[2] > street[1])
		result = result + street[1]; // returned home
	else
	{
		result = result + street[2]; //visited the first magazin
		result = result + street[0]; //reterned home
	}

	cout << result;

	return 0;
}
