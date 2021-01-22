#include <string>
#include <iostream>
#include <cassert>

using namespace std;

class Massiv
{
private:
    int *m_array;
    int m_length;

public:
    Massiv(int length) //Constructor
    {
        assert(length > 0);

        m_array = new int[length];
        m_length = length;
    }
    
    ~Massiv() //Destructor
    {
        delete[] m_array;
    }

    void setValue(int index, int value) { m_array[index] = value; }
    int getValue(int index) { return m_array[index]; }

};

int main()
{
    Massiv arr(15);
    for (int i = 0; i < 15; ++i)
        arr.setValue(i, i * 2);

        cout << "The value of element 7 is " << arr.getValue(7);

    return 0;
}
