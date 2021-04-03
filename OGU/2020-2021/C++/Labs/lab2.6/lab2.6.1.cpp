#include <iostream>
#include <string>
using namespace std;

struct Node
{
	string s;
	int x = 0;
	Node* l, * r;
};
Node* searchInsert(Node*& Tree, string str) // makes new Node of our Tree
{
	if (Tree == nullptr)
	{
		Tree = new Node;
		Tree->s = str;
		Tree->x = 1;
		Tree->l = nullptr;
		Tree->r = nullptr;
	}
	else if (str < Tree->s)
		Tree->l = searchInsert(Tree->l, str);
	else if (str > Tree->s)
		Tree->r = searchInsert(Tree->r, str);
	else if (str == Tree->s)
		Tree->x++;

	return(Tree);
}
void show(Node*& Tree) // shows our dictionary
{
	if (Tree != nullptr)
	{
		show(Tree->l);
		cout << endl << Tree->x << " times: " << Tree->s << '\t';
		show(Tree->r);
	}
}
int main()
{
	char act;		// choice of running program
	string str;		// here's our string with word 
	bool b = true;	// while b = true, program running
	Node* Tree = nullptr;
	while (b)
	{
		cout << "Imput the word: ";	
		getline(cin, str);

		Tree = searchInsert(Tree, str);
		cout << "Continue? (y/n): ";
		cin >> act;
		cin.ignore(32767, '\n');
		b = act == 'y';
	}
	show(Tree);

	return 0;
}
