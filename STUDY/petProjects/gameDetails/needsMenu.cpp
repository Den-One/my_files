#include <iostream>
#include <string>
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

class Bladder: public Needs
{
public:
	Bladder(double valueOfNeed, double speedOfFalling)
		: Needs(valueOfNeed, speedOfFalling) {}

	void printCurrentNeedValue() {
		cout << "Bladder:" << fixed;
		Needs::printCurrentNeedValue();
	}
	void makeLower(int timeInMinuts)
	{
		Needs::makeLower(timeInMinuts);
		if (s_valueOfNeed < 0.0001)
		{
			cout << "You died from lack of peeing :(\n";
			exit(1);
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
		if (s_valueOfNeed < 0.0001)
		{
			cout << "You died from lack of fun :(\n";
			exit(1);
		}
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

int main()
{
	// Macking our display in console
	Hunger hunger(1.0, 0.014);
	Energy sleep(10, 0.0075);
	Bladder bladder(4, 0.009);
	Hygiene hygiene(8, 0.0009);
	Social social(4, 0.001);
	Fun fun(5, 0.008);

	printPersonDisplayInConsole(hunger, sleep, bladder, hygiene, social, fun);
	sleep.makeLower(1);
	fun.makeLower(5);
	social.makeLower(14);
	printPersonDisplayInConsole(hunger, sleep, bladder, hygiene, social, fun);
	
	return 0;
}
