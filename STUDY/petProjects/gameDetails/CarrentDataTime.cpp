#include <iostream>
#include <string>
using namespace std;

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
		cout << m_month << "." << m_year << endl;
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
};

class CarrentTime : public CarrentDate, public Achievements
{
protected:
	int m_hour = 8;
	int m_minut = 0;

public:
	CarrentTime(int hour, int minut, int day, int month, int year)
		: m_hour(hour), m_minut(minut), CarrentDate(day, month, year) {}

	void passedMinuts(int minuts)
	{
		if (m_minut + minuts >= 60)
		{
			m_hour += 1;
			if (m_hour > 23)
			{
				m_hour = 0;
				m_livedDays += 1;
				CarrentDate::goToNextDay();
			}
			m_minut += minuts - 60;
		}
		else
			m_minut += minuts;
	}

	void printInConsole()
	{
		if (m_hour > 23) m_hour = 0;
		if (m_hour < 10)
			cout << '0' << m_hour << ':';
		else
			cout << m_hour << ':';

		if (m_minut < 10)
			cout << '0' << m_minut << '\t';
		else
			cout << m_minut << '\t';

		CarrentDate::printInConsole();
	}
};

int main()
{
	CarrentTime date(23, 0, 30, 6, 2021);
	date.printInConsole();
	date.goToNextDay();
	date.printInConsole();
	date.passedMinuts(60);
	date.printInConsole();

	return 0;
}
