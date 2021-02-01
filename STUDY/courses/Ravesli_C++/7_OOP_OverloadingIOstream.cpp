#include <iostream>

using namespace std;

class Fraction
{
private:
	int m_numerator = 0;
	int m_denominator = 1;

public:
	Fraction(int numerator = 0, int denominator = 1) :
		m_numerator(numerator), m_denominator(denominator)
	{
		// We put the reduce () method in the constructor
    to make sure all the fractions we have are reduced!
		// Any fractions that are overwritten must be re-reduced.
		reduce();
	}

	static int nod(int a, int b)
	{
		return b == 0 ? a : nod(b, a % b);
	}

	void reduce()
	{
		int nod = Fraction::nod(m_numerator, m_denominator);
		m_numerator /= nod;
		m_denominator /= nod;
	}

	friend Fraction operator*(const Fraction& f1, const Fraction& f2);
	friend Fraction operator*(const Fraction& f1, int value);
	friend Fraction operator*(int value, const Fraction& f1);

	friend std::ostream& operator<<(std::ostream& out, const Fraction& f1);
	friend std::istream& operator>>(std::istream& in, Fraction& f1);

	void print()
	{
		std::cout << m_numerator << "/" << m_denominator << "\n";
	}
};

Fraction operator*(const Fraction& f1, const Fraction& f2)
{
	return Fraction(f1.m_numerator * f2.m_numerator, f1.m_denominator * f2.m_denominator);
}

Fraction operator*(const Fraction& f1, int value)
{
	return Fraction(f1.m_numerator * value, f1.m_denominator);
}

Fraction operator*(int value, const Fraction& f1)
{
	return Fraction(f1.m_numerator * value, f1.m_denominator);
}

std::ostream& operator<<(std::ostream& out, const Fraction& f1)
{
	out << f1.m_numerator << "/" << f1.m_denominator;
	return out;
}

std::istream& operator>>(std::istream& in, Fraction& f1)
{
	char c;

	// Overwriting the values of the object f1
	in >> f1.m_numerator;
	in >> c; // ignore separator '/'
	in >> f1.m_denominator;

	// Since we have overwritten the existing f1, we need to re-execute the reduction
	f1.reduce();

	return in;
}

int main()
{

	Fraction f1;
	std::cout << "Enter fraction 1: ";
	std::cin >> f1;

	Fraction f2;
	std::cout << "Enter fraction 2: ";
	std::cin >> f2;

	std::cout << f1 << " * " << f2 << " is " << f1 * f2 << '\n';

	return 0;
}
