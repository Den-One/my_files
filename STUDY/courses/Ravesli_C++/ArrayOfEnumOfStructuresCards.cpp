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
        case VALUE_2 : cout << "2"; break;
        case VALUE_3 : cout << "3"; break;
        case VALUE_4 : cout << "4"; break;
        case VALUE_5 : cout << "5"; break;
        case VALUE_6 : cout << "6"; break;
        case VALUE_7 : cout << "7"; break;
        case VALUE_8 : cout << "8"; break;
        case VALUE_9 : cout << "9"; break;
        case VALUE_10: cout << "10";break;
        case JACK    : cout << "J"; break;
        case QUEEN   : cout << "Q"; break;
        case KING    : cout << "K"; break;
        case ACE     : cout << "A"; break;
    }

    switch (someCard.suit)
    {
        case SUIT_CLUBS   : cout << "C"; break;
        case SUIT_DIAMONDS: cout << "D"; break;
        case SUIT_HEARTS  : cout << "H"; break;
        case SUIT_SPADES  : cout << "S"; break;
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
void shuffleDeck(std::array<Card, 52> &deck)
{
    for (int i(0); i < 52; ++i)
    {
        int iSwap = getRandomNumber(0, 51);
        swapCard(deck[i], deck[iSwap]);
    }
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
            deck[card].suit  = static_cast<CardSuit>(suit);
            deck[card].value = static_cast<CardValue>(value);
            ++card;
        }
    }

    printDeck(deck);

    shuffleDeck(deck);

    //Prints shuffled desk
    cout << endl;
    printDeck(deck);

    _getch();
    return 0;
}
