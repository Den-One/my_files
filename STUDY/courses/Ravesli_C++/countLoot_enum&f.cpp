#include <iostream>
#include <conio.h>

using namespace std;

//All the gamer's loot
enum Loot
{
    HEALTH_POTION,
    TORCH,
    ARROW,
    MAX_LOOT
};

//Counts all the loot using the enum from array
//It takes the array's pointer
int countTotalltems(int *arrayLoot)
{
    int allLoot(0);
    for (int i(0); i < MAX_LOOT; ++i)
        allLoot += arrayLoot[i];

    return (allLoot);
}

int main()
{
    //Using MAX_LOOT for number of all loot items
    int arrayLoot[MAX_LOOT] {3, 6, 12};
    
    int result = countTotalltems(arrayLoot);
    cout << "The player has " << result << " items in total.\n";

    _getch();
    return 0;
}
