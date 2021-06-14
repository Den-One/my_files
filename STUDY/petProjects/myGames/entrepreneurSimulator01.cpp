#include <iostream>
#include <string>
using namespace std;

 struct CarrentDate
{
	int m_day;
	int m_month;
	int m_year;

	CarrentDate(int day, int month, int year)
		: m_day(day), m_month(month), m_year(year) {}
	
	int goToNextDay() { return m_day += 1; }
	void printInConsole() { cout << m_day << "." << m_month << "." << m_year << endl; }
};

 int win(0);
 struct Achievement
 {
	 void printInConsole()
	 {
		 for (int i(0); i < win; i++)
			 cout << '\3' << " ";

		 cout << endl;
	 }
 };

struct RealTime
{

	int s_hour = 8;
	int s_minut = 0;

	RealTime(int hour, int minut) : s_hour(hour), s_minut(minut) {}

	int passedMinuts(int minut, CarrentDate day)
	{
		if (s_minut + minut >= 60)
		{
			s_hour += 1;
			if (s_hour > 23)
			{
				s_hour = 0;
				win += 1;
				return day.m_day = day.goToNextDay();
			}
			s_minut += minut - 60;
			return day.m_day;
		}
		else
			s_minut += minut;
		
		return day.m_day;
	}

	int passedHours(int hour, CarrentDate day)
	{
		if (s_hour + hour > 23)
		{
			s_hour = 24 - s_hour;
			hour = hour - s_hour;
			win += 1;
			s_hour =hour;
			return day.m_day = day.goToNextDay();
		}

		s_hour += hour;
		return day.m_day;
	}

	void printInConsole()
	{
		if (s_hour > 23)
			s_hour = 0;
		if (s_hour < 10)
			cout << '0' << s_hour << ':';
		else
			cout << s_hour << ':';

		if (s_minut < 10)
			cout << '0' << s_minut << endl;
		else
			cout << s_minut << endl;
	}
};

struct Need
{
	double s_speedOfFalling = 0.018;
	double s_value; // current velue of need
	Need(double value, double speedOfFalling): s_value(value), s_speedOfFalling(speedOfFalling) {}

	void makeLower(int n)
	{
		s_value -= s_speedOfFalling * n;
		
		if (s_value < 0.1)
		{
			cout << "You died from hunger\n";
			exit(1);
		}
	}

	void makeHigher(double valueOfHigher)
	{
		s_value += valueOfHigher;
		if (s_value > 10) s_value = 10;
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

	BudgetInRubles(double money): s_money(money) {}

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
	CarrentDate date(2, 6, 2021);
	RealTime todayTime(6, 0);
	Need hunger(4.0, 0.014);
	Need sleep(10, 0.0075);
	BudgetInRubles persBudget(100);
	Food vermicelli("vermicell", 17.5, 8.5, 0);
	Achievement achiv;

	int doing = 0;
	while (doing != 6)
	{
		system("cls");
		achiv.printInConsole();
		date.printInConsole();
		todayTime.printInConsole();
		persBudget.printInConsole();
		vermicelli.printInConsole();
		cout << "\n";
		cout << "Person has 2 need\n" << "Hunger: " << hunger.s_value;

		if (hunger.s_value > 7.06)
			cout << "\t\tI'm full\n";
		else if (hunger.s_value < 2)
			cout << "\t\tI'm hungry!\n";
		else
			cout << endl;

		cout << "Sleep : " << sleep.s_value;

		if (sleep.s_value > 7.7)
			cout << "\t\tI slept well\n";
		else if (sleep.s_value < 2.6)
			cout << "\t\tI wanna sleep!\n";
		else
			cout << endl;

		cout << "\n0: Do something (5 minut);\t";
		cout << "1: Do something (1 hour)\n";
		cout << "2: Eat;\t\t\t\t";
		cout << "3: Buy some food;\n";
		cout << "4: Sleep;\t\t\t";
		cout << "5: Sell food;\n";
		cout << "6: Exit;\n";
		cout << "Answer: "; cin >> doing;

		cout << endl;
		switch (doing)
		{
		case 0:
			hunger.makeLower(5);
			sleep.makeLower(5);
			date.m_day = todayTime.passedMinuts(5, date); break;
		case 1:
			hunger.makeLower(60);
			sleep.makeLower(60);
			date.m_day = todayTime.passedHours(1, date); break;
		case 2:
			if (vermicelli.s_pack > 0)
			{
				vermicelli.beEaten();
				hunger.makeHigher(2.94);
				sleep.makeLower(10);
				date.m_day = todayTime.passedMinuts(10, date);
			} break;
		case 3:
			if (persBudget.s_money > vermicelli.s_foodCost)
			{
				hunger.makeLower(30);
				sleep.makeLower(30);
				date.m_day = todayTime.passedMinuts(30, date);
				vermicelli.s_pack = persBudget.buyFood(vermicelli);
			} break;
		case 4:
			hunger.makeLower(240);
			date.m_day = todayTime.passedHours(8, date);
			sleep.makeHigher(7.1);
			break;
		case 5:
			if (vermicelli.s_pack > 0)
			{
				hunger.makeLower(15);
				sleep.makeLower(15);
				date.m_day = todayTime.passedMinuts(15, date);
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
