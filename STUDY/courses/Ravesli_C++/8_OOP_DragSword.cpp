#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <conio.h>

using namespace std;

//Generats a random number between min & max
int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

class Creature
{
protected:
	string	m_name;
	char	m_symbol;
	int		m_health;
	int		m_damage;
	int		m_gold;
	
public:
	Creature( string name, char symbol, int health, int damage, int gold):
		m_name(name), m_symbol(symbol), m_health(health), m_damage(damage), m_gold(gold) {}

	string getName() { return m_name; }
	char getSymbol() { return m_symbol; }
	int getHealth() { return m_health; }
	int getDamage() { return m_damage; }
	int getGold() { return m_gold; }

	void reduceHealth(int health) { m_health -= health; }
	bool isDead() { return m_health <= 0; }
	void addGold(int gold) { m_gold += gold;}
};

class Player: public Creature
{
private:
	int m_level = 1;
	int m_killed = 0;

public:
	Player(string name)
	: Creature(name, '@', 13, 1, 0) {}

	int getLevel() { return m_level; }

	void levelUp() { m_level += 1; m_damage += 1; }
	bool hasWon() { return m_level >= 20; }
};

class Monster: public Creature
{
public:
	enum Type
	{
		DRAGON,
		ORC,
		SLIME,
		MAX_TYPES
	};

	struct MonsterData
	{
		const char* name;
		char symbol;
		int health;
		int damage;
		int gold;
	};

	static MonsterData monsterData[MAX_TYPES];

	Monster(Type type): Creature(monsterData[type].name, monsterData[type].symbol,
		monsterData[type].health, monsterData[type].damage, monsterData[type].gold)
	{
	}

	static Monster getRandomMonster()
	{
		int num = getRandomNumber(0, MAX_TYPES - 1);
		return Monster(static_cast<Type>(num));
	}
};

Monster::MonsterData Monster::monsterData[Monster::MAX_TYPES]
{
	{ "dragon", 'D', 20, 4, 100 },
	{ "orc", 'o', 4, 2, 25 },
	{ "slime", 's', 1, 1, 10 }
};

// This method handles the monster's attack by the player
void attackMonster(Player& p, Monster& m)
{
	// If the player is dead, then he can't attack the monster
	if (p.isDead()) return;

	cout << "\tYou hit the " << m.getName() << " for " << p.getDamage() << " damage.\n";

	// Monster's health is reduced by player damage
	m.reduceHealth(p.getDamage());

	// If the monsted is dead, then increase the player's level
	if (m.isDead())
	{
		cout << "\n\tYou killed the " << m.getName() << ".\n";
		p.levelUp();
		//cout << "\n\tYou are now level " << p.getLevel() << ".\n";
		cout << "\tYou found " << m.getGold() << " gold.\n";
		p.addGold(m.getGold());
	}
}

// This method handles the player's attck by the monster
void attackPlayer(Monster& m, Player& p)
{
	// If the monster is dead, then it can't attck the player
	if (m.isDead()) return;

	// Player's health is reduced by monster damage
	p.reduceHealth(m.getDamage());
	cout << "\tThe " << m.getName() << " hit you for " << m.getDamage() << " damage.\n";
}

// This method handles the entire fight between the player and the rand-monster
void fightMonster(Player& p)
{
	_getch();
	system("cls");

	// Shows all the player's information 
	cout << "\tBrave " << p.getName() << " took the sword.\n";
	cout << "\tLevel: \t" << p.getLevel() << "\tGold: \t" << p.getGold() << endl;
	cout << "\tHealth:\t" << p.getHealth() << "\tKilled:\t" << p.getLevel() - 1 << endl;

	// Firstly it generates the rand-monster
	Monster m = Monster::getRandomMonster();
	cout << "\n\tYou have encountered a " << m.getName() << " (" << m.getSymbol() << ").\n";

	// While monster or player isn't dead, then the fight is going on
	while (!m.isDead() && !p.isDead())
	{
		cout << "\t(R)un or (F)ight: ";
		char input;
		cin >> input;
		if (input == 'R' || input == 'r')
		{
			// 50/50 chance of a successful escape
			if (getRandomNumber(1, 2) == 1)
			{
				cout << "\tYou successfully fled.\n";
				return; // Meeting with the monster was avoided
			}
			else
			{
				// Unsuccessful escape attempt gives the monster the right to attack
				cout << "\tYou failed to flee.\n\n";
				attackPlayer(m, p);
				continue;
			}
		}

		if (input == 'F' || input == 'f')
		{
			//The player attacks first, then the monster
			attackMonster(p, m);
			attackPlayer(m, p);
		}
	}
}

int main()
{
	// Set the value of the system clock as the start number
	srand(static_cast<unsigned int>(time(0)));
	rand(); // Resets the first result

	cout << "\tEnter your name: ";
	string playerName;
	cin >> playerName;

	Player p(playerName);
	cout << "\tWelcome, " << p.getName() << '\n';

	_getch();
	system("cls");

	// If the player is not dead and has not won yet, then the game continues
	while (!p.isDead() && !p.hasWon())
		fightMonster(p);

	// At this point, the player is either dead or won
	if (p.isDead())
	{
		cout << "\n\tYou died at level " << p.getLevel() << " and with " << p.getGold() << " gold.\n";
		cout << "\tToo bad you can't take it with you!\n";
	}
	else
	{
		cout << "\n\tYou won the game wuth " << p.getGold() << " gold!\n";
	}

	return 0;
}
