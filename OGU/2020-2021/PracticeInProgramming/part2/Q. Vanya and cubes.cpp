#include <iostream>
#include <string>
using namespace std;
int main()
{
	int N(0), sum(0), hugh(0);
	cin >> N;
	int get(0), s(0);
	while (N > sum)
	{
		get++;
		s = s + get;
		sum = sum + s;
		
		if (N >= sum)
			hugh++;
	}

	cout << hugh;

	return 0;
}
