#include <iostream>
#include <string>
using namespace std;

int main()
{
	long long n(0),m(0);
	cin >> n >> m;

	long long *arr = new long long[m];
	for (long long i(0); i < m; ++i)
	{
		cin >> arr[i];
		cin.clear();
	}

	long long things(0);
	long long memory(0);
	for (long long i(0); i < m; ++i)
	{
		if (m > 1)
		{
			if (i == 0)
			{
				if (arr[i] <= arr[i + 1])
				{
					things = arr[i] - 1;
					memory = arr[i] - 1;
				}

				if (arr[i] > arr[i + 1])
				{
					things = n;
					memory = 0;
				}
			}

			if (i != 0 && i < m - 1)
			{
				if (arr[i] <= arr[i + 1])
				{
					if (memory != 0)
					{
						things = things + arr[i] - memory - 1;
						memory = arr[i] - 1; // - memory
					}
					else
					{
						things = things + arr[i] - 1;
						memory = arr[i] - 1;
					}
				}

				if (arr[i] > arr[i + 1])
				{
					if (memory != 0)
					{
						things = things + n - memory;
						memory = 0;
					}
					else
					{
						things = things + n;
						memory = 0;
					}
				}
			}

			if (i == m - 1)
			{
				if (arr[i - 1] <= arr[i])
				{
					things = things + arr[i] - 1 - memory;
					memory = 0;
				}

				if (arr[i - 1] > arr[i])
				{
					things = things + arr[i] - 1;
					memory = 0;
				}
			}
		}
		else
		{
			things = things + arr[i] - 1;
		}
	}
	cout << things;

	return 0;
}
