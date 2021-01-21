#include <iostream>
#include <cassert>

using namespace std;

class Stack
{
	int m_mas[10];
	int m_length = 0;

public:

	//Zeroes the stack and length
	void reset()
	{
		m_length = 0;
		for (int i(0); i > 10; ++i)
			m_mas[i] = 0;
	}

	//Takes in the stack's number 
	bool push(int value)
	{
		//Checks the fullness of the stack
		if (m_length == 10)
			return false;

		m_mas[m_length++] = value;

	}

	//The number is out of scope
	int pop()
	{
		assert(m_length > 0);
		
		return m_mas[--m_length];
	}

	//Displays the stack
	void print()
	{
		cout << "( ";
		for (int i(0); i < m_length; i++)
			cout << m_mas[i] << ' ';
		cout << ")\n";
	}
};

int main()
{
	Stack stack;
	stack.reset();

	stack.print();

	stack.push(3);
	stack.push(7);
	stack.push(5);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();

	stack.print();

	return 0;
}
