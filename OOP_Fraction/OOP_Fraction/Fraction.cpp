﻿#include "Fraction.h"

#include <iostream>

using namespace std;

// ---> Constructors ------------------
Fraction::Fraction()
{
	this->integer		= 0;
	this->numerator		= 0;
	this->denominator	= 1;
}

Fraction::Fraction(int integer)
{
	this->integer		= integer;
	this->numerator		= 0;
	this->denominator	= 1;
}

Fraction::Fraction(int numerator, int denominator)
{
	this->integer		= 0;
	this->numerator		= numerator;
	setDenominator(denominator);
}

Fraction::Fraction(int integer, int numerator, int denominator)
{
	this->integer		= integer;
	this->numerator		= numerator;
	setDenominator(denominator);
}

Fraction::Fraction(const Fraction& other)
{
	this->integer		= other.integer;
	this->numerator		= other.numerator;
	setDenominator(other.denominator);
}


Fraction::Fraction(double decimal)
{
	integer = decimal;
	decimal -= integer;

	numerator = decimal * 100000000;
	denominator = 100000000;

	reduce();
}

// ---> Destructor ------------------
Fraction::~Fraction() {}


// ---> Getters ------------------
int Fraction::getInteger() const
{
	return integer;
}

int Fraction::getNumerator() const
{
	return numerator;
}

int Fraction::getDenominator() const
{
	return denominator;
}

// ---> Setters ------------------
void Fraction::setInteger(int integer)
{
	this->integer = integer;
}

void Fraction::setNumerator(int numerator)
{
	this->numerator = numerator;
}

void Fraction::setDenominator(int denominator)
{
	if (denominator == 0)
		denominator = 1;

	this->denominator = denominator;
}

// ---> Operators ------------------
Fraction& Fraction::operator=(const Fraction& other)
{
	this->integer		= other.integer;
	this->numerator		= other.numerator;
	this->denominator	= other.denominator;
	return *this;
}

Fraction& Fraction::operator+=(Fraction other)
{
	this->reduce().toImprorer();
	other.reduce().toImprorer();

	this->numerator =
		this->numerator * other.denominator +
		this->denominator * other.numerator;

	this->denominator = this->denominator *= other.denominator;
	return this->reduce().toProper();
}

Fraction& Fraction::operator++()
{
	this->reduce().toProper();
	this->integer++;
	return *this;
}

Fraction Fraction::operator++(int)
{
	this->reduce().toProper();
	Fraction old = *this;
	++this->integer;
	return old;
}

Fraction& Fraction::operator-=(Fraction other)
{
	this->reduce().toImprorer();
	other.reduce().toImprorer();

	this->numerator = 
		this->numerator		* other.denominator - 
		this->denominator	* other.numerator;
	
	this->denominator = this->denominator *= other.denominator;
	return this->reduce().toProper();
}

Fraction& Fraction::operator*=(Fraction other)
{
	this->reduce().toImprorer();
	other.reduce().toImprorer();
	this->numerator		*= other.numerator;
	this->denominator	*= other.denominator;
	return this->reduce().toProper();
}

Fraction& Fraction::operator/=(Fraction other)
{
	this->reduce().toImprorer();
	other.reduce().toImprorer();
	this->numerator		*= other.denominator;
	this->denominator	*= other.numerator;
	return this->reduce().toProper();
}

Fraction operator+(Fraction first, Fraction second)
{
	first.toImprorer();
	second.toImprorer();

	return Fraction(
		first.getNumerator() * second.getDenominator() +
		second.getNumerator() * first.getDenominator(),
		first.getDenominator() * second.getDenominator()
	).toProper().reduce();
}

Fraction operator-(Fraction first, Fraction second)
{
	first.toImprorer();
	second.toImprorer();

	return Fraction(
		first.getNumerator() * second.getDenominator() -
		second.getNumerator() * first.getDenominator(),
		first.getDenominator() * second.getDenominator()
	).toProper().reduce();
}

Fraction operator/(Fraction first, Fraction second)
{
	first.toImprorer();
	second.toImprorer();

	return Fraction(
		first.getNumerator() * second.getDenominator(),
		first.getDenominator() * second.getNumerator()
	).toProper().reduce();
}

Fraction operator*(Fraction first, Fraction second)
{
	first.toImprorer();
	second.toImprorer();

	return Fraction(
		first.getNumerator() * second.getNumerator(),
		first.getDenominator() * second.getDenominator()
	).toProper().reduce();
}

ostream& operator<<(ostream& os, const Fraction& obj)
{
	if (obj.getInteger())os << obj.getInteger();
	if (obj.getNumerator())
	{
		if (obj.getInteger())os << "(";
		os << obj.getNumerator() << "/" << obj.getDenominator();
		if (obj.getInteger())os << ")";
	}
	else if (obj.getInteger() == 0) cout << 0;
	return os;
}

bool operator==(const Fraction& first, const Fraction& second)
{
	return first.getInteger() == second.getInteger() &&
		first.getNumerator() == second.getNumerator() &&
		first.getDenominator() == second.getDenominator();
}

bool operator!=(const Fraction& first, const Fraction& second)
{
	return !(second == first);
}

bool operator>(Fraction first, Fraction second)
{
	first.toImprorer();
	second.toImprorer();

	first -= second;
	double result = first;

	return (result > 0);
}

bool operator<(const Fraction& first, const Fraction& second)
{
	return !(first >= second);
}

bool operator>=(const Fraction& first, const Fraction& second)
{
	return first > second || first == second;
}

bool operator<=(const Fraction& first, const Fraction& second)
{
	return !(first > second) || first == second;
}

// ---> Methods ------------------
Fraction& Fraction::toProper()
{
	integer += numerator / denominator;
	numerator %= denominator;
	return *this;
}

Fraction& Fraction::toImprorer()
{
	numerator += integer * denominator;
	integer = 0;
	return *this;
}

Fraction& Fraction::reduce()
{
	int more, less, reminder = 0;

	if (denominator > numerator)
	{
		more = denominator;
		less = numerator;
	}
	else
	{
		more = numerator;
		less = denominator;
	}

	do
	{
		reminder = more % less;
		more = less;
		less = reminder;
	} while (reminder);

	int GCD = more; // ---> Greatest Common Divider

	numerator /= GCD;
	denominator /= GCD;

	return *this;
}

void Fraction::print() const
{
	if (integer)
		cout << integer;

	if (numerator)
	{
		if (integer) 
			cout << "(" << numerator << "/" << denominator << ")";
		else cout << numerator << "/" << denominator;
	}
	else if (integer == 0)
		cout << integer;

	cout << endl;
}