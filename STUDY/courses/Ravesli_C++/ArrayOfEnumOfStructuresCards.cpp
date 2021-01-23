#include <iostream>
#include <conio.h>
#include <array>
#include <iterator>
#include <ctime>
#include <cstdlib>

using namespace std;

//All the Card's suits. From 0 to 4
enum CardSuit
{
    SUIT_CLUBS,
    SUIT_DIAMONDS,
    SUIT_HEARTS,
    SUIT_SPADES,
    MAX_CARD_SUIT
};

//All the Card's values. From 0 to 14
enum CardValue
{
    VALUE_2,
    VALUE_3,
    VALUE_4,
    VALUE_5,
    VALUE_6,
    VALUE_7,
    VALUE_8,
    VALUE_9,
    VALUE_10,
    JACK,
    QUEEN,
    KING,
    ACE,
    MAX_CARD_VALUE
};

//Contsins all the card's information.
struct Card
{
    CardValue value;    //14
    CardSuit  suit;     //4
};

//Takes velues and suits from enums by link and print one letter
void printCard(const Card &someCard)
{
    switch (someCard.value)
    {
    case VALUE_2: cout << "2"; break;
    case VALUE_3: cout << "3"; break;
    case VALUE_4: cout << "4"; break;
    case VALUE_5: cout << "5"; break;
    case VALUE_6: cout << "6"; break;
    case VALUE_7: cout << "7"; break;
    case VALUE_8: cout << "8"; break;
    case VALUE_9: cout << "9"; break;
    case VALUE_10: cout << "10"; break;
    case JACK: cout << "J"; break;
    case QUEEN: cout << "Q"; break;
    case KING: cout << "K"; break;
    case ACE: cout << "A"; break;
    }

    switch (someCard.suit)
    {
    case SUIT_CLUBS: cout << "_C"; break;
    case SUIT_DIAMONDS: cout << "_D"; break;
    case SUIT_HEARTS: cout << "_H"; break;
    case SUIT_SPADES: cout << "_S"; break;
    }
}

//Takes the array's name and print all the card using space
void printDeck(const array<Card, 52> &deck)
{
    for (const auto &element : deck)
    {
        printCard(element);
        cout << ' ';
    }

    cout << '\n';
}

//Swaps two cards (their values and suits)
void swapCard(Card &a, Card &b)
{
    Card c = a;
    a = b;
    b = c;
}

//Generates random numbers taking minimum and maximum
int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

//Takes filled array, swaps sequential cards and random cards
void shuffleDeck(array<Card, 52> &deck)
{
    for (int i(0); i < 52; ++i)
    {
        int iSwap = getRandomNumber(0, 51);
        swapCard(deck[i], deck[iSwap]);
    }
}

int getCardValue(const Card &someCard)
{
    switch (someCard.value)
    {
        case VALUE_2: return 2;
        case VALUE_3: return 3;
        case VALUE_4: return 4;
        case VALUE_5: return 5;
        case VALUE_6: return 6;
        case VALUE_7: return 7;
        case VALUE_8: return 8;
        case VALUE_9: return 9;
        case VALUE_10: return 10;
        case JACK: return 10;
        case QUEEN: return 10;
        case KING: return 10;
        case ACE: return 11;
    }

    return 0;
}

enum BlackjackResults
{
    BJ_PLAYER_WIN,
    BJ_DEALER_WIN,
    BJ_DRAW
};

char getPlayerChoice()
{
    cout << "\t(h) to hit, or (s) to stand: ";
    char choice;
    do
    {
        cin >> choice;
    } while (choice != 'h' && choice != 's');

    return choice;
}

bool playBlackjack(array<Card, 52> &deck)
{
    //Setting up the starting game mode
    const Card *cardPtr = &deck[0];

    int PlayerCards(0);
    int DealerCards(0);

    //Dealer gets one card
    DealerCards += getCardValue(*cardPtr++);
    cout << "\tThe DEALER is showing: " << DealerCards << '\n';

    //Player gets two cards
    PlayerCards += getCardValue(*cardPtr++);
    PlayerCards += getCardValue(*cardPtr++);

    //Player starts
    while (1)
    {
        cout << "\tYou hava: " << PlayerCards << '\n';

        //Checking, does the player has 21 points?
        if (PlayerCards > 21)
            return false;

        char choice = getPlayerChoice();
        if (choice == 's')
            break;

        PlayerCards += getCardValue(*cardPtr++);
    }

    //If the player has not lost and he has no more than 21 points,
    //then the dealer receives cards until he has a total of 17 points
    while (DealerCards < 17)
    {
        DealerCards += getCardValue(*cardPtr++);
        cout << "\tThe DEALER now has: " << DealerCards << '\n';
    }

    //If the dealer has more than 21 points the player won
    if (DealerCards > 21)
        return true;

    return (PlayerCards > DealerCards);

}

int main()
{
    //Making random number using clock and using  algorithm
    srand(static_cast<unsigned int>(time(0)));
    rand();

    //Making array of structs using std::array
    array<Card, 52> deck{};

    //Fills an array with enum's values.
    int card(0);
    for (int suit(0); suit < MAX_CARD_SUIT; ++suit)
    {
        for (int value(0); value < MAX_CARD_VALUE; ++value)
        {
            //name array[0-52].structureElement =
            //int ->  CardSuit/CardValue (enum)
            deck[card].suit = static_cast<CardSuit>(suit);
            deck[card].value = static_cast<CardValue>(value);
            ++card;
        }
    }

    bool a = true;
    while (a)
    {
        shuffleDeck(deck);
        cout << "\t\t==THE GAME 21 POINTS==\n\n";

        if (playBlackjack(deck))
            cout << "\n\tYou win!\n";
        else
            cout << "\n\tYou lose!\n";

        cout << "\n\tDo you want to play again?\n";
        cout <<"\t(y) to say 'yes', or (n) to say 'no': ";
        char choice;
        do
        {
            cin >> choice;
        } while (choice != 'y' && choice != 'n');

        if (choice == 'y')
        {
            a = true;
            system("cls");
        }
        else
            a = false;
    }

    _getch();
    return 0;
}
