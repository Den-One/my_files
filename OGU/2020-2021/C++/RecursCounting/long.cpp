/*1. We receive a string as input.
* 2. We check it for emptiness.
* 3. We call a function that causes the character to be added to zero.
* 4. Further, this superfunction checks whether it is true or falls.
* 5. If false then odd, if true, then another function is called,
* 6. Which ultimately should lead to the same check.
* /

#include <iostream>
#include <string>

using namespace std;

//return true if the string is empty
bool empty(string &s)
{
	if (s[0] == '\0')
		return true;
	else
		return false;
}

//moving string while it become '\0'
string change(string s)
{
	int i(0);
	for (; s[i] != '\0'; ++i)
	{
		s[i+1] = s[i];
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
		return false;
}

//return false if the string is odd
bool odd(string &s)
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
	cin  >> s;
	if (even(s))
	{
		cout << "\nThe string is even\n\n";
	}
	else
		cout << "\nThe string is odd\n\n";

	system("pause");

	return 0;
}
