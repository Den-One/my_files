#include <iostream>
#include <string>
using namespace std;

struct FirstList
{
	long long d; // singly linked list
	FirstList* next;
};

FirstList* addList(FirstList*& List, long long num)
{
	if (List == nullptr) // List element doesn't full
	{
		List = new FirstList;
		List->d = num;
		List->next = nullptr;
	}
	else // element has already full, checking next
		List->next = addList(List->next, num);

	return(List);
}

FirstList* makeList(string str, long long length, FirstList* List)
{
	char save = str[length - 1]; // raplacing the last symbol with space
	str[length - 1] = ' '; // make possible to recognize the last number fully
	long long finish(0), start(0), i(0); // each number starts with the first digit

	while (i < length) // moving over the whole line 
	{
		long long sum(0); // save here all the found number between spaces
		if (str[i] == ' ') // if we found space
		{
			start = i - 1; // starts before space that is, first digit
			if (i == length - 1) // if the found space is the last symbol in string
			{
				str[i] = save; // replacing back the space with saved symbol
				start++;	   // we start with a saved symbol
			}

			int digit(1); // each number has at least 1 digit
			for (start; start >= finish; --start)
			{
				switch (str[start]) //recognizing symbols and turning into int type
				{
				case '1': sum = sum + (1 * digit);	digit *= 10; break;
				case '2': sum = sum + (2 * digit);	digit *= 10; break;
				case '3': sum = sum + (3 * digit);	digit *= 10; break;
				case '4': sum = sum + (4 * digit);	digit *= 10; break;
				case '5': sum = sum + (5 * digit);	digit *= 10; break;
				case '6': sum = sum + (6 * digit);	digit *= 10; break;
				case '7': sum = sum + (7 * digit);	digit *= 10; break;
				case '8': sum = sum + (8 * digit);	digit *= 10; break;
				case '9': sum = sum + (9 * digit);	digit *= 10; break;
				}
			}

			addList(List, sum); // add the found number to the List
			start = i - 1;	finish = start + 2; // finish is the last digit number
			start = 0;  sum = 0;  digit = 1; // resetting counters
		}
		i++; // going to the next symbol
	}
	return(List);
}

FirstList* multiplyLists(FirstList*& List1, FirstList*& List2, FirstList*& List3)
{
	while (List1 != nullptr || List2 != nullptr) // check while every list doesn't end
	{
		if (List3 == nullptr)
		{
			List3 = new FirstList; // make new multy-list element

			if (List1 != nullptr && List2 != nullptr) // if both lists has numbers
			{
				List3->d = List1->d * List2->d; // save the result of multuplication
				List3->next = nullptr;
			}

			if (List1 != nullptr && List2 == nullptr) // if List2 already ended
			{
				List3->d = List1->d * 1; // take List1 number and add to the List3
				List3->next = nullptr;
			}

			if (List2 != nullptr && List1 == nullptr) // if List1 already ended
			{
				List3->d = List2->d * 1; // take List2 number and add to the List3
				List3->next = nullptr;
			}

			if (List1 != nullptr) // if we didn't find the end of List1
				List1 = List1->next; // moving up to the next List element

			if (List2 != nullptr) // if we didn't find the end of List2
				List2 = List2->next; // moving up to the next List element
		}
		else // moving up to the next multy-list element if this one is already full
			List3->next = multiplyLists(List1, List2, List3->next);
	}
	return (List3);
}

void showList(FirstList*& List)
{
	if (List != nullptr)
	{
		cout << List->d << ' ';
		showList(List->next); // tryna find the empty list element and finish
	}
}

FirstList* deleteLastElement(FirstList*& List)
{ // 'couse our list has only 'next' pointer
	if (List->next = nullptr)
	{
		List->d = 0; 
		delete List; // we can delete only one element
		List = nullptr; // when we found end of list
	}
	else // moving up to the next element if the next one full
		deleteLastElement(List->next);

	return (List);
}

void deleteList(FirstList*& List)
{
	while (List != nullptr) // removes each element one at a time,
		List = deleteLastElement(List);// reaching the end of the list
}

int main()
{
	FirstList *List1 = nullptr, *List2 = nullptr, *List3 = nullptr;

	// User makes List1
	string str;
	cout << "Input the first list:\t";
	getline(cin, str);
	int lengthOfString = str.size();
	List1 = makeList(str, lengthOfString, List1);

	// User makes List2
	str.clear(); // preparing for inputting a new string
	cout << "Input the second list:\t";
	getline(cin, str);
	lengthOfString = str.size();
	List2 = makeList(str, lengthOfString, List2);

	// We multiply the user lists and show the result
	List3 = multiplyLists(List1, List2, List3);
	cout << endl << "Multiplied List: ";
	showList(List3);
	cout << endl << endl;

	// don't forget to delete the memory from heap
	deleteList(List1); deleteList(List2); deleteList(List3);

	return 0;
}
