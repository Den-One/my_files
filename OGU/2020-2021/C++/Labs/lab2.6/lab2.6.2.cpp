#include <iostream>
#include <string>
using namespace std;

struct Man
{
	string sername;
	string agency;

	Man* l = nullptr;
	Man* r = nullptr;
};
struct City
{
	string name;

	Man* m = nullptr;
	City* l = nullptr;
	City* r = nullptr;
};
Man* searchMan(Man* node, string s, string a)
{
	if (node == nullptr)
	{
		node = new Man;
		node->sername = s;
		node->agency = a;
		node->l = node->r = nullptr;
	}
	else if (s <= node->sername)
		node->l = searchMan(node->l, s, a);
	else if (s > node->sername)
		node->r = searchMan(node->r, s, a);

	return (node);
}
City* searchCity(City* tree, string n, string s, string a)
{
	if (tree == nullptr)
	{
		tree = new City;
		tree->name = n;
		tree->m = searchMan(tree->m, s, a);
		tree->l = tree->r = nullptr;
	}
	else if (n < tree->name)
		tree->l = searchCity(tree->l, n, s, a);
	else if (n > tree->name)
		tree->r = searchCity(tree->r, n, s, a);
	else if (n == tree->name)
		tree->m = searchMan(tree->m, s, a);

	return (tree);
}
void printMan(Man* node)
{
	if (node != nullptr)
	{
		printMan(node->l);
		cout <<  node->sername << endl;
		printMan(node->r);
	}
}
void printCity(City* tree)
{
	if (tree != nullptr)
	{
		printCity(tree->l);
		cout << endl << tree->name << endl;
		printMan(tree->m);
		printCity(tree->r);
	}
}
int main()
{
	City* city1 = nullptr;
	string name, sername, agency;

	char act = 'y';
	while (act == 'y')
	{
		cout << "Imput city: ";
		getline(cin, name);

		cout << "Imput surname: ";
		getline(cin, sername);

		cout << "Imput organization: ";
		getline(cin, agency);
		city1 = searchCity(city1, name, sername, agency);

		cout << "Continue? (y/n) ";
		cin >> act;
		cin.ignore(32767, '\n');
		cout << endl;
	}
	system("cls");
	printCity(city1);

	return 0;
}
