#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

//Ask the user about the names' number
int askUser()
{
    cout << "\tHow many names would you like to add?\n\tThe answer: ";
    int N; cin >> N;
    cin.ignore(32767, '\n');
    cout << endl;
    return N;
}

//It sorts alphabetically if function has names' number and array
void sortNames(int N, string *array)
{
    for (int i = 0; i < N - 1; i++)
    {
        int sml_i = i;
        for (int j = i + 1; j < N; j++)
        {
            if (array[j] < array[sml_i])
                sml_i = j;
        }

        swap(array[i], array[sml_i]);
    }
}

//It shows the names from array and cleans screen
void printNames(int N, string *array)
{
    system("cls");

    cout << "\n\tThe correct list:\n\n";
    for (int i(0); i < N; i++)
    {
        cout << "\tThe name " << i+1 << ": " << array[i] << endl;
    }
}


int main()
{
    //We'll know the names' number
    int N = askUser();

    //Input the names in dynamic array
    string* array = new string[N];

    for (int i(0); i < N; i++)
    {
        cout << "\tThe name " << i + 1 << ": ";
        getline(cin, array[i]);
    }

    sortNames (N, array);
    printNames(N, array);

    //freeing heap
    delete[] array;
    array = nullptr;

    _getch();
    return 0;
}
