#include <iostream>
#include <conio.h>
#include <string>
#include <algorithm>

using namespace std;

//Student's information
struct Student
{
    string name;
    int estimate;
};

//Sorting. The biggest estimate will be the highest
void sortNames(Student* array, int N)
{
    for (int i_start{}; i_start < N - 1; ++i_start)
    {
        int i_big = i_start;

        for (int i_current(i_start + 1); i_current < N; ++i_current)
        {
            if (array[i_current].estimate > array[i_big].estimate)
            {
                //We found the biggest student's estimate
                i_big = i_current;
            }
        }

        //The biggest student's estimate takes the highest place.
        swap(array[i_start], array[i_big]);
    }
}

int main()
{
    cout << "How many students would you like to add?\nThe unswer: ";
    int N;
    cin >> N;
    cin.ignore(32767, '\n');

    //Making dynamicaling array for information of students.
    Student *array = new Student[N];

    //Input the name and estimate each of students.
    for (int i(0); i < N; ++i)
    {
        cout << "Please, input the " << i + 1 << " student's name: ";
        getline(cin, array[i].name);
        cout << "Please, input the " << i + 1 << " student's estimate: ";
        cin >> array[i].estimate;
        cin.ignore(32767, '\n');
    }

    //Sorting the students' information
    sortNames(array, N);

    //Output the restult
    cout << endl;
    for (int i{}; i < N; i++)
    {
        cout << array[i].name << " got a grade of " << array[i].estimate << endl;
    }

    //Freeing up memory
    delete[] array;

    _getch();
    return 0;
}
