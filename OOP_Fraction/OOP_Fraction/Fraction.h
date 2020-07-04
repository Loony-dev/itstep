#pragma once
#include <ostream>
using namespace std;

// ---> Operators ------------------
class Fraction;
Fraction operator+(Fraction first, Fraction second);
Fraction operator-(Fraction first, Fraction second);
Fraction operator*(Fraction first, Fraction second);
Fraction operator/(Fraction first, Fraction second);

bool operator==(const Fraction& first, const Fraction& second);
bool operator!=(const Fraction& first, const Fraction& second);
bool operator>(Fraction first, Fraction second);
bool operator<(const Fraction& first, const Fraction& second);
bool operator>=(const Fraction& first, const Fraction& second);
bool operator<=(const Fraction& first, const Fraction& second);

class Fraction
{
public:

	// ---> Constructors ------------------
	Fraction();
	Fraction(int integer);
	Fraction(int numerator, int denominator);
	Fraction(int integer, int numerator, int denominator);
	Fraction(const Fraction& other);

	Fraction(double decimal);

	// ---> Destructor ------------------
	~Fraction();

	// ---> Getters ------------------
	int getInteger() const;
	int getNumerator() const;
	int getDenominator() const;

	// ---> Setters ------------------
	void setInteger(int integer);
	void setNumerator(int numerator);
	void setDenominator(int denominator);

	// ---> Operators ------------------
	Fraction& operator=(const Fraction& other);
	Fraction& operator+=(Fraction other);
	Fraction& operator-=(Fraction other);
	Fraction& operator*=(Fraction other);
	Fraction& operator/=(Fraction other);

	Fraction& operator++();
	Fraction operator++(int);

	operator int()
	{
		return this->integer;
	}

	operator double()
	{
		return integer + (double)numerator / denominator;
	}

	// ---> Methods ------------------
	Fraction& toProper();
	Fraction& toImprorer();
	Fraction& reduce();
	void print() const;


private:
	int integer;
	int numerator;
	int denominator;
};
