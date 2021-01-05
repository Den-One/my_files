#include <iostream>
#include <conio.h>
#include "constants.h"

using namespace std;

double getHight()
{
	cout << "\tWhat's the height of tower in maters?\n";
	cout << "\tThe height is: ";
	int towerHeight;
	cin >> towerHeight;

	return towerHeight;
}

double groundIsNear(double getHight, int seconds)
{
	double iFlown = (myConstants::gravity * seconds * seconds) / 2;
	double groundIsNear = getHight - iFlown;

	return groundIsNear;
}

void printResult(double height, int seconds)
{
	if (height > 0.0)
	{
		cout << "\tAt " << seconds << " seconds, the ball is at height:\t" << height << " meters\n";
	}
	else
		cout << "\n\tAt " << seconds << " seconds, the ball is on the ground.\n";
}

int main()
{
	const double initialHeight = getHight();
	int seconds = 0;
	double height;

	do
	{
		height = groundIsNear(initialHeight, seconds);
		printResult(height, seconds);
		++seconds;
	} while (height > 0.0);

	_getch();
	return 0;
}