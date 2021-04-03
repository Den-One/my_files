#include <iostream>
#include <string>

using namespace std;

//moving string while it become '\0'
string change(string s)
{
	int i(0);
	for (; s[i + 1] != '\0'; ++i) {
		s[i] = s[i + 1];
	}
	s[i] = '\0';
	return s;
}

//return true if the string is empty
bool empty(string s)
{
	if (s[0] == '\0')
		return true;
	else
		return false;
}

//return true if the string is even
//return false if the string is odd
bool even(string s)
{
	if (empty(s))
	{
		return true;
	}
	if (empty(change(s)))
	{
		return false;
	}
	else
		return even(change(change(s)));
}

int main()
{
	string s;
	cout << "Input the string: ";
	cin >> s;
	if (even(s))
	{
		cout << "The string is even\n\n" << endl;
	}
	else
		cout << "The string is odd\n\n" << endl;

	system("pause");
	return 0;
}
