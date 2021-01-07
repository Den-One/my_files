#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
using namespace std;

//We generate a random_number between min & max.
//It's supposed that srand() has already been called.
int getRandonNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    //Distribute the choice of a random number evently in the range
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

//Return true if the user won, false if he lost
bool playGame(int guesses, int number)
{
    //cycle of work with user's guesses
    for (int count(1); count <= guesses; ++count)
    {
        cout << "\tGuess #" << count << ": ";
        int guess;
        cin >> guess;

        //If the previous extraction failed
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "\tThat input is invalid. Please try again.\n";
        }
        else
        {
            cin.ignore(32767, '\n');
        }

        if (guess > number)
            cout << "\tYour guess is too high.\n";
        else if (guess < number)
            cout << "\tYour guess is too low.\n";
        else // guess == number
            return true;
    }

    return false;
}

bool playAgain()
{
    //We keep asking the user if he wants to play again untill he push 'y' or 'n'
    while (true)
    {
        char ch;
        do
        {
            cout << "\tWould you like to play again (y/n)?\n\n";
            cout << "\tThe answer: ";
            cin >> ch;

            //check user response
            if (ch == 'y' || ch == 'n')
                return (ch == 'y');
            //User input the wrong symbol
            else cout << "\tThat input is invalid. Please try again.\n";

        } while (ch != 'y' && ch != 'n');
    }
}

int main()
{
    //Use the system clock as a starting number
    srand(static_cast<unsigned int>(time(0)));
    //Dropping the first result
    //'cause the function rand() doesn't randomize the first rand_num very well
    rand();

    const int guesses = 7; // The user has 7 attempts

    do
    {
        //The number that the user must guess
        int number = getRandonNumber(1, 100);

        system("cls");

        cout << "\tLet's play a game. I'm thinking of a number from 1 to 100.\n";
        cout << "\tYou have " << guesses << " tries to guess what it is.\n\n";

        bool won = playGame(guesses, number);
        if (won)
        {
            cout << "\tCorrect! You win!\n";
        }
        else
            cout << "\tSorry, you lose. The correct number was " << number << endl;

    } while (playAgain());

    cout << "\n\tThank you for playing.\n";
    
    _getch();
    return 0;
}