#include <iostream>
#include <string>
using namespace std;
int main()
{
	int N;
	cin >> N;
	int* arr = new int[N];
	cin.ignore(32767, '\n');

	double elem(0.0);
	double result(0.0);
	for (int i(0); i < N; ++i)
	{
		cin >> elem;
		arr[i] = elem;
		cin.clear();
		result = result + arr[i];
	}
	result = result / N;

	cout << result;

	return 0;
}
