#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

class Needs
{
protected:
	double s_speedOfFalling; // speed of value falling
	double s_valueOfNeed; // current velue of need

public:
	Needs(double valueOfNeed, double speedOfFalling)
		: s_valueOfNeed(valueOfNeed), s_speedOfFalling(speedOfFalling) {}

	void makeLower(int timeInMinuts)
	{
		s_valueOfNeed -= s_speedOfFalling * timeInMinuts;
	}

	void makeHigher(double valueOfHigher)
	{
		s_valueOfNeed += valueOfHigher;
		if (s_valueOfNeed > 10) s_valueOfNeed = 10;
	}

	void printCurrentNeedValue() {
		cout.precision(2);
		cout << s_valueOfNeed << '\t';
	}
};

class Hunger : public Needs
{
public:
	Hunger(double valueOfNeed, double speedOfFalling)
		: Needs(valueOfNeed, speedOfFalling) {}

	void printCurrentNeedValue() {
		cout << "Hunger: " << fixed;
		Needs::printCurrentNeedValue();
	}
	void makeLower(int timeInMinuts)
	{
		Needs::makeLower(timeInMinuts);
		if (s_valueOfNeed < 0.0001)
		{
			cout << "You died from hunger :(\n";
			exit(1);
		}
	}
};

class Energy : public Needs
{
public:
	Energy(double valueOfNeed, double speedOfFalling)
		: Needs(valueOfNeed, speedOfFalling) {}

	void printCurrentNeedValue() {
		cout << "Energy: " << fixed;
		Needs::printCurrentNeedValue();
	}
	void makeLower(int timeInMinuts)
	{
		Needs::makeLower(timeInMinuts);
		if (s_valueOfNeed < 0.0001)
		{
			cout << "You died from lack of sleep :(\n";
			exit(1);
		}
	}
};

class Hygiene : public Needs
{
public:
	Hygiene(double valueOfNeed, double speedOfFalling)
		: Needs(valueOfNeed, speedOfFalling) {}

	void printCurrentNeedValue() {
		cout << "Hygiene:" << fixed;
		Needs::printCurrentNeedValue();
	}
	void makeLower(int timeInMinuts)
	{
		Needs::makeLower(timeInMinuts);
		if (s_valueOfNeed < 0.0001)
		{
			s_valueOfNeed = 0;
		}
	}
};

class Bladder : public Needs
{
public:
	Bladder(double valueOfNeed, double speedOfFalling)
		: Needs(valueOfNeed, speedOfFalling) {}

	void printCurrentNeedValue() {
		cout << "Bladder:" << fixed;
		Needs::printCurrentNeedValue();
	}
	void makeLower(int timeInMinuts, Hygiene &hygiene)
	{
		Needs::makeLower(timeInMinuts);
		if (s_valueOfNeed < 0.0001)
		{
			s_valueOfNeed = 10;
			hygiene.makeLower(3000);
			cout << "You pissed off. Hope nobody saw it \1\n";
			_getch();
			//exit(1);
		}
	}
};

class Fun : public Needs
{
public:
	Fun(double valueOfNeed, double speedOfFalling)
		: Needs(valueOfNeed, speedOfFalling) {}

	void printCurrentNeedValue() {
		cout << "Fun:    " << fixed;
		Needs::printCurrentNeedValue();
	}
	void makeLower(int timeInMinuts)
	{
		Needs::makeLower(timeInMinuts);
		if (s_valueOfNeed < 0.0001)
		{
			cout << "You died from lack of fun :(\n";
			exit(1);
		}
	}
};

class Social : public Needs
{
public:
	Social(double valueOfNeed, double speedOfFalling)
		: Needs(valueOfNeed, speedOfFalling) {}

	void printCurrentNeedValue() {
		cout << "Social: " << fixed;
		Needs::printCurrentNeedValue();
	}
	void makeLower(int timeInMinuts)
	{
		Needs::makeLower(timeInMinuts);
		if (s_valueOfNeed < 0.0001) s_valueOfNeed = 0;
	}
};

void printPersonDisplayInConsole(Hunger hunger, Energy sleep, Bladder bladder, Hygiene hygiene, Social social, Fun fun)
{
	cout << char(201); // cornor
	for (int i(0); i < 31; i++) // line
		cout << char(205);
	cout << char(187) << endl; // cornor

	cout << char(186) << ' '; hunger.printCurrentNeedValue();
	sleep.printCurrentNeedValue(); cout << char(186); cout << endl;
	cout << char(186) << ' '; bladder.printCurrentNeedValue();
	hygiene.printCurrentNeedValue(); cout << char(186); cout << endl;
	cout << char(186) << ' '; social.printCurrentNeedValue();
	fun.printCurrentNeedValue(); cout << char(186); cout << endl;

	cout << char(200); // cornor
	for (int i(0); i < 31; i++) // line
		cout << char(205);
	cout << char(188); // cornor
	cout << endl;
}

class CarrentDate
{
protected:
	int m_day;
	int m_month;
	int m_year;

public:
	CarrentDate(int day, int month, int year)
		: m_day(day), m_month(month), m_year(year) {}

	void printInConsole()
	{
		if (m_day < 10) cout << '0';
		cout << m_day << ".";
		if (m_month < 10) cout << '0';
		cout << m_month << "." << m_year;
	}

	void goToNextDay()
	{
		switch (m_month)
		{
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
				if (m_day < 31) m_day += 1;
				else {
					m_month += 1;
					m_day = 1;
				} break;
			case 2:
				if (m_day < 28) m_day += 1;
				else { 
					m_month += 1;
					m_day = 1;
				} break;
			case 12:
				if (m_day < 31) m_day += 1;
				else {
					m_year += 1;
					m_month = 0;
					m_day = 1;
				} break;
			case 4:
			case 6:
			case 9:
			case 11:
				if (m_day < 30) m_day += 1;
				else {
					m_month += 1;
					m_day = 1;
				} break;
		}
	}
};

class Achievements
{
protected:
	int m_livedDays = 0;
public:
	void printInConsole() { cout << "You lived days: " << m_livedDays; }
	void getAchievTime() { m_livedDays += 1; }
};

class CarrentTime : public CarrentDate, public Achievements
{
protected:
	int m_hour = 8;
	int m_minut = 0;

public:
	CarrentTime(int hour, int minut, int day, int month, int year)
		: m_hour(hour), m_minut(minut), CarrentDate(day, month, year) {}

	void passedMinuts(int minuts) // 22:45 + 480 
	{
		if (m_minut + minuts >= 60) // 525 > 60
		{
			int minutsToHours = (m_minut + minuts) / 60; // 525 / 60 = 8.75 
			int restOfMinuts = (m_minut + minuts) - (minutsToHours * 60); // 525 - 480 = 45
			m_minut = restOfMinuts; // 45 -> 45

			m_hour += minutsToHours; // 22:45 -> 30:45
			if (m_hour > 23)
			{
				int newHours = m_hour - 24; // 30 - 24 = 6
				m_hour = newHours; // 6
				CarrentDate::goToNextDay();
				Achievements::getAchievTime();
			}
		}
		else
			m_minut += minuts;
	}

	void printInConsole()
	{
		cout << char(201); // cornor
		for (int i(0); i < 31; i++) // line
			cout << char(205);
		cout << char(187) << endl; // cornor
		cout << char(186) << ' ' << "Time: ";

		if (m_hour > 23) m_hour = 0;
		if (m_hour < 10)
			cout << '0' << m_hour << ':';
		else
			cout << m_hour << ':';

		if (m_minut < 10)
			cout << '0' << m_minut << "\t";
		else
			cout << m_minut << "\t";

		CarrentDate::printInConsole();

		cout << '\t' << char(186) << endl;
		cout << char(200); // cornor
		for (int i(0); i < 31; i++) // line
			cout << char(205);
		cout << char(188); // cornor
		
		cout << endl;
		Achievements::printInConsole();
	}
};

struct Food
{
	string s_name;
	double s_foodCost;
	double s_addPrice;
	int s_pack;

	Food(string name, double foodCost, double addPrice, int pack)
		: s_name(name), s_foodCost(foodCost), s_addPrice(addPrice), s_pack(pack) {}

	void beEaten()
	{
		if (s_pack > 0)
			s_pack -= 1;
	}

	void printInConsole() { cout << "Food " << s_name << " packs: " << s_pack << endl; }
};

struct BudgetInRubles
{
	double s_money;

	BudgetInRubles(double money) : s_money(money) {}

	int buyFood(Food someFood)
	{
		if (s_money > someFood.s_foodCost)
		{
			s_money -= someFood.s_foodCost;
			return someFood.s_pack += 1;
		}
		else
			return someFood.s_pack;
	}

	int sellFood(Food someFood)
	{
		if (someFood.s_pack > 0)
		{
			s_money += someFood.s_foodCost + someFood.s_addPrice;
			return someFood.s_pack -= 1;
		}
		else
			return someFood.s_pack;
	}

	void printInConsole() { cout << "Money: " << s_money << " P" << endl; }
};

int main()
{
	/* ------ Make our needs ------ */
	Hunger hunger(10, 0.010416);
	Energy sleep(10, 0.008771929);
	Bladder bladder(10, 0.011904);
	Hygiene hygiene(10, 0.00362318);
	Social social(10, 0.00260416);
	Fun fun(10, 0.003472);

	/* ------ Make our Data and TIme ------ */
	CarrentTime date(6, 0, 30, 6, 2021);
	int minutsNum(0);

	/* Make other information */
	BudgetInRubles persBudget(100);
	Food vermicelli("vermicell", 17.5, 8.5, 0);
	Achievements achiv;

	int userDecision(-1);
	while (userDecision != 0)
	{
		/* ------ Make our display ------ */
		system("cls");
		printPersonDisplayInConsole(hunger, sleep, bladder, hygiene, social, fun);
		date.printInConsole();
		cout << endl;

		persBudget.printInConsole();
		vermicelli.printInConsole();
		cout << "\n";

		cout << "\n0: Do smth (5 minut);\t";
		cout << "1: Do smth (1 hour)\n";
		cout << "2: Eat;\t\t\t";
		cout << "3: Buy some food;\n";
		cout << "4: Sleep;\t\t";
		cout << "5: Sell food;\n";
		cout << "6: Exit;\n";
		cout << "Answer: "; cin >> userDecision;

		switch (userDecision)
		{
		case 0:
			hunger.makeLower(5);
			sleep.makeLower(5);
			date.passedMinuts(5); break;
		case 1:
			hunger.makeLower(60);
			sleep.makeLower(60);
			date.passedMinuts(60); break;
		case 2:
			if (vermicelli.s_pack > 0)
			{
				vermicelli.beEaten();
				hunger.makeHigher(2.94);
				sleep.makeLower(10);
				date.passedMinuts(10);
			} break;
		case 3:
			if (persBudget.s_money > vermicelli.s_foodCost)
			{
				hunger.makeLower(30);
				sleep.makeLower(30);
				date.passedMinuts(30);
				vermicelli.s_pack = persBudget.buyFood(vermicelli);
			} break;
		case 4:
			hunger.makeLower(240);
			date.passedMinuts(480);
			sleep.makeHigher(7.1);
			break;
		case 5:
			if (vermicelli.s_pack > 0)
			{
				hunger.makeLower(15);
				sleep.makeLower(15);
				date.passedMinuts(15);
				vermicelli.s_pack = persBudget.sellFood(vermicelli);
			}
			break;
		case 6:
			cout << "Death is also exit.";
			exit(1); break;
		}
	}
	return 0;
}
