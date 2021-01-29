#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

// Every monster has name, type and health.
class Monster
{
public:
	enum MonsterType
	{
		Dragon,
		Goblin,
		Ogre,
		Orc,
		Skeleton,
		Troll,
		Vampire,
		Zombie,
		MAX_MONSTER_TYPES
	};
  
private:
	MonsterType m_type;
	string      m_name;
	int         m_health;

public:
	Monster(MonsterType type, string name, int health)
		: m_type(type), m_name(name), m_health(health)
	{
	}
  
  // We turn enum into a string.
	string getTypeString() const
	{
		switch (m_type)
		{
			case Dragon:  return "dragon";
			case Goblin:  return "goblin";
			case Ogre:    return "ogre";
			case Orc:     return "orc";
			case Skeleton:return "skeleton";
			case Troll:   return "troll";
			case Vampire: return "Vampire";
			case Zombie:  return "Zombie";
		}

		return "Error!";
	}
  
  // We can print all the minster's information.
  void print() const
	{
		cout << m_name << " is the " << getTypeString() << " that has " << m_health << " points\n";
	}
};

// Creat random monster's names, health and type.
class MonsterGenerator
{
public:
	// We generate a random number between min and max (inclusive).
	// It assumes srand () has already been called.
	static int getRandomNumber(int min, int max)
	{
		// use static, since this value needs to be calculated once.
		static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
		// Distribute the calculation of the value from our range evenly.
		return static_cast<int>(rand() * fraction * (max - min + 1) + min);
	}

	static Monster generateMonster()
	{
		Monster::MonsterType type = static_cast<Monster::MonsterType>(getRandomNumber(0, Monster::MAX_MONSTER_TYPES - 1));
		int health = getRandomNumber(1, 100);

		static string s_names[6]{ "John", "Brad", "Alex", "Thor", "Hulk", "Asnee" };
		return Monster(type, s_names[getRandomNumber(0, 5)], health);
	}
};

int main()
{
	srand(static_cast<unsigned int>(time(0))); // Use the system clock as a starting value.
	rand(); // resetting the first random number.

	// Generate 5 first monsters and print them.
	for (int i(0); i < 5; ++i)
	{
		Monster m = MonsterGenerator::generateMonster();
		m.print();
	}

	return 0;
}
