#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

void read(int arr[], int length)
{
	for (int i(0); i < length; ++i)
	{
		cin >> arr[i];
	}
}

int comp1(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}

int findLostElement(int arr1[], int arr2[], int length)
{
	for (int i(0); i < length; ++i)
	{
		if (arr1[i] != arr2[i])
			return arr1[i];
	}

	return 0;
}

int main()
{
	int length(0);
	cin >> length;
	cin.ignore(32767, '\n');

	int *arr1 = new int[length];
	int* arr2 = new int[length];
	int* arr3 = new int[length];
	
	int lostElem1(0);
	int lostElem2(0);

	read(arr1, length);
	read(arr2, length - 1);
	qsort(arr1, length, sizeof(int), comp1);
	qsort(arr2, length - 1, sizeof(int), comp1);
	lostElem1 = findLostElement(arr1, arr2, length);

	read(arr3, length - 2);
	qsort(arr3, length - 2, sizeof(int), comp1);
	lostElem2 = findLostElement(arr2, arr3, length - 1);

	cout << lostElem1 << endl << lostElem2;

	return 0;
}
