#include <iostream>
#include <string>
using namespace std;

int findLength(string s, int length)
{
	int arr[11] = {};

	int sLength = length;
	int j(0);
	for (int i(0); i < sLength; ++i)
	{
		if (s[i] != '-' && s[i] != '(' && s[i] != ')' && s[i] != '+')
		{
			switch (s[i])
			{
			case '0': j++; break;
			case '1': j++; break;
			case '2': j++; break;
			case '3': j++; break;
			case '4': j++; break;
			case '5': j++; break;
			case '6': j++; break;
			case '7': j++; break;
			case '8': j++; break;
			case '9': j++; break;
			}
		}
	}

	return j;
}

//if the length = 11
void saveInArray1(string s, int arr[], int length)
{
	int sLength = length;
	int j(0);
	for (int i(0); i < sLength; ++i)
	{
		if (s[i] != '-' && s[i] != '(' && s[i] != ')' && s[i] != '+')
		{
			switch (s[i])
			{
			case '0': arr[j] = 0; break;
			case '1': arr[j] = 1; break;
			case '2': arr[j] = 2; break;
			case '3': arr[j] = 3; break;
			case '4': arr[j] = 4; break;
			case '5': arr[j] = 5; break;
			case '6': arr[j] = 6; break;
			case '7': arr[j] = 7; break;
			case '8': arr[j] = 8; break;
			case '9': arr[j] = 9; break;
			}
			j++; //fill in the next array's element
		}

		if (arr[0] == 7)
			arr[0] = 8;
	}
}

// if еру length = 7
void saveInArray2(string s, int arr[], int length)
{
	int sLength = length;
	int j(4);
	for (int i(0); i < sLength; i++)
	{
		arr[0] = 8;
		arr[1] = 4;
		arr[2] = 9;
		arr[3] = 5;

		if (s[i] != '-' && s[i] != '(' && s[i] != ')' && s[i] != '+')
		{
			switch (s[i])
			{
			case '0': arr[j] = 0; break;
			case '1': arr[j] = 1; break;
			case '2': arr[j] = 2; break;
			case '3': arr[j] = 3; break;
			case '4': arr[j] = 4; break;
			case '5': arr[j] = 5; break;
			case '6': arr[j] = 6; break;
			case '7': arr[j] = 7; break;
			case '8': arr[j] = 8; break;
			case '9': arr[j] = 9; break;
			}
			j++; //fill in the next array's element
		}
	}
}

void saveInArray(string s, int arr[])
{
	cin.clear();
	getline(cin, s);
	int length = s.size();

	int sizeNum = findLength(s, length);

	if (sizeNum == 11)
		saveInArray1(s, arr, length);
	else if (sizeNum == 7)
		saveInArray2(s, arr, length);
}

void printResult(int phone[], int ph[])
{
	int count(0);
	for (int i(0); i < 11; ++i)
	{
		if (phone[i] == ph[i])
			count++;
	}

	if (count == 11)
		cout << "YES\n";
	else
		cout << "NO\n";
}

int main()
{
	int phone[11] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
	int ph1[11] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
	int ph2[11] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
	int ph3[11] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };

	string p;
	saveInArray(p, phone);
	saveInArray(p, ph1);
	saveInArray(p, ph2);
	saveInArray(p, ph3);

	printResult(phone, ph1);
	printResult(phone, ph2);
	printResult(phone, ph3);

	return 0;
}
