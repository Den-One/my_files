#include <iostream>
#include <string>
using namespace std;

int main()
{
	char side;
	cin >> side;
	cin.ignore(32767, '\n');
	string str;
	getline(cin, str);
	int length = str.size();

	if (side == 'L')
	{
		for (int i(0); i < length; ++i)
		{
			if (str[i] == '.')		str[i] = '/';
			if (str[i] == ',')		str[i] = '.';
			if (str[i] == 'm')		str[i] = ',';
			if (str[i] == 'n')		str[i] = 'm';
			if (str[i] == 'b')		str[i] = 'n';
			if (str[i] == 'v')		str[i] = 'b';
			if (str[i] == 'c')		str[i] = 'v';
			if (str[i] == 'x')		str[i] = 'c';
			if (str[i] == 'z')		str[i] = 'x';
			if (str[i] == 'l')		str[i] = ';';
			if (str[i] == 'k')		str[i] = 'l';
			if (str[i] == 'j')		str[i] = 'k';
			if (str[i] == 'h')		str[i] = 'j';
			if (str[i] == 'g')		str[i] = 'h';
			if (str[i] == 'f')		str[i] = 'g';
			if (str[i] == 'd')		str[i] = 'f';
			if (str[i] == 's')		str[i] = 'd';
			if (str[i] == 'a')		str[i] = 's';
			if (str[i] == 'o')		str[i] = 'p';
			if (str[i] == 'i')		str[i] = 'o';
			if (str[i] == 'u')		str[i] = 'i';
			if (str[i] == 'y')		str[i] = 'u';
			if (str[i] == 't')		str[i] = 'y';
			if (str[i] == 'r')		str[i] = 't';
			if (str[i] == 'e')		str[i] = 'r';
			if (str[i] == 'w')		str[i] = 'e';
			if (str[i] == 'q')		str[i] = 'w';
		}
	}
	else if (side == 'R')
	{
		for (int i(0); i < length; ++i)
		{
			if (str[i] == 'x')		str[i] = 'z';
			if (str[i] == 'c')		str[i] = 'x';
			if (str[i] == 'v')		str[i] = 'c';
			if (str[i] == 'b')		str[i] = 'v';
			if (str[i] == 'n')		str[i] = 'b';
			if (str[i] == 'm')		str[i] = 'n';
			if (str[i] == ',')		str[i] = 'm';
			if (str[i] == '.')		str[i] = ',';
			if (str[i] == '/')		str[i] = '.';
			if (str[i] == 's')		str[i] = 'a';
			if (str[i] == 'd')		str[i] = 's';
			if (str[i] == 'f')		str[i] = 'd';
			if (str[i] == 'g')		str[i] = 'f';
			if (str[i] == 'h')		str[i] = 'g';
			if (str[i] == 'j')		str[i] = 'h';
			if (str[i] == 'k')		str[i] = 'j';
			if (str[i] == 'l')		str[i] = 'k';
			if (str[i] == ';')		str[i] = 'l';
			if (str[i] == '\'')		str[i] = ';';
			if (str[i] == 'w')		str[i] = 'q';
			if (str[i] == 'e')		str[i] = 'w';
			if (str[i] == 'r')		str[i] = 'e';
			if (str[i] == 't')		str[i] = 'r';
			if (str[i] == 'y')		str[i] = 't';
			if (str[i] == 'u')		str[i] = 'y';
			if (str[i] == 'i')		str[i] = 'u';
			if (str[i] == 'o')		str[i] = 'i';
			if (str[i] == 'p')		str[i] = 'o';
		}
	}

	cout << str;

	return 0;
}
