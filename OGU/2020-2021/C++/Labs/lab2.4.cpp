#include <iostream>
#include <cstdlib>
#include <locale>
using namespace std;

struct List
{
	int d;
	List* next;
};

// creats the first list element
List* makeFirst(int x)
{
	List* prev = new List;
	prev->d = x;
	prev->next = 0;

	return prev;
}

// adds the list element to the beginning
void addBegin(List** prevBeg, int x)
{
	List* prev = new List;
	prev->d = x;
	prev->next = *prevBeg;
	*prevBeg = prev;
}

// adds the list element to the end
void addEnd(List** prevEnd, int x)
{
	List* prev = new List;
	prev->d = x;
	prev->next = 0;
	(*prevEnd)->next = prev;
	*prevEnd = prev;
}

// shows all the list elements
void print(List* prevBeg)
{
	List* prev = prevBeg;
	cout << "List: ";

	while (prev > 0)
	{
		cout << prev->d << ' ';
		prev = prev->next;
	}

	cout << endl;
}

// looks for the element
List* find(List* const prevBeg, int key)
{
	List* prev = prevBeg;
	while (prev)
	{
		if (prev->d == key) break;
		prev = prev->next;
	}

	return prev;
}

// looks for the element preceding given one in the list
List* findBefore(List* const prevBeg, List* key)
{
	List* prev = prevBeg;
	while (prev)
	{
		if (prev->next == key) break;
		prev = prev->next;
	}

	return prev;
}

// adds the element before the found one
void addBefore(List** prevBeg, int key, int x)
{
	List* f = find(*prevBeg, key);

	if (f)
	{
		if (f == *prevBeg)
			addBegin(&*prevBeg, x);
		else
		{
			List* prev = new List;
			prev->next = f;
			prev->d = x;
			List* fb = findBefore(*prevBeg, f);
			fb->next = prev;
		}
	}
	else
		cout << "Error 1" << endl;
}

// adds the element after the found one
void addAfter(List** prevBeg, List** prevEnd, int key, int x)
{
	List* f = find(*prevBeg, key);

	if (f)
	{
		if (f == *prevEnd)
			addEnd(&*prevEnd, x);
		else
		{
			List* prev = new List;
			prev->d = x;
			prev->next = f->next;
			f->next = prev;
		}
	}
	else
		cout << "Error 2" << endl;
}

// removal of a certain element 
void deleteIf(List** prevBeg, List** prevEnd, int key)
{
	List* f = find(*prevBeg, key);

	if (f)
	{
		List* fb = findBefore(*prevBeg, f);
		if (f == *prevBeg)
			*prevBeg = (*prevBeg)->next;
		else if (f == *prevEnd)
			fb->next = nullptr;
		else
			fb->next = f->next;
	}
	else
		cout << "Error 3" << endl;
}

int main()
{
	List* prevBeg = makeFirst(1);
	List* prevEnd = prevBeg;
	//print(prevBeg);

	char doing = '+';
	while (doing == '+')
	{
		cout << "1: add u number to the beginning;\t" << "4: add u number after the found one;" << endl;
		cout << "2: add u number to the end;\t\t" << "5: add u number before the found one." << endl;
		cout << "3: Delete a number;\n" << endl;

		int answer;
		cout << "Choose the number of act: ";
		cin >> answer;

		int num, key;
		switch (answer)
		{
		case 1:
			cout << "\nThe number is: ";
			cin >> num;
			addBegin(&prevBeg, num);
			print(prevBeg);
			break;

		case 2:
			cout << "\nThe number is: ";
			cin >> num;
			addEnd(&prevEnd, num);
			print(prevBeg);
			break;

		case 3:
			cout << "\nThe number is: ";
			cin >> key;
			deleteIf(&prevBeg, &prevEnd, key);
			print(prevBeg);
			break;

		case 4:
			cout << "\nYour new number is: ";
			cin >> num;
			cout << "\nThe after found number: ";
			cin >> key;
			addAfter(&prevBeg, &prevEnd, key, num);
			print(prevBeg);
			break;

		case 5:
			cout << "\nYour new number is: ";
			cin >> num;
			cout << "\nThe before found number: ";
			cin >> key;
			addBefore(&prevBeg, key, num);
			print(prevBeg);
			break;

		default: cout << "\nError 4. Invalid input. Try again." << endl;
		}

		cout << "Print \"+\", if you want to continue changing the list: ";
		cin >> doing;
		system("cls");
	}
	cout << "Exit" << endl;
  
  return 0;
}
