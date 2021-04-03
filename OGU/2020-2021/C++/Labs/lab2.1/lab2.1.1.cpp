#include <iostream>
#include <iostream>
#include <string>
using namespace std;

// announcement in advance
bool odd(string s);

//return true if the string is empty
bool empty(string s)
{
	if (s[0] == '\0')
		return true;
	else
		return false;
}

//moving string while it become '\0'
string change(string s)
{
	int i;
	for (i =0; s[i+1] != '\0'; ++i)
	{
		s[i] = s[i+1];
	}

	s[i] = '\0';

	return s;
}

//return true if the string is even
bool even(string s)
{
	if (empty(s))
		return true;
	else
		return odd(change(s));
}

//return false if the string is odd
bool odd(string s)
{
	if (empty(s))
		return false;
	else
		return even(change(s));
}

int main()
{
	string s;
	cout << "Input the string: ";
	cin >> s;
	if (even(s))
	{
		cout << "The string is even\n\n";
	}
	else
		cout << "The string is odd\n\n";

	system("pause");

	return 0;
}
