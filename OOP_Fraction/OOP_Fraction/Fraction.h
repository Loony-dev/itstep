#pragma once

class Fraction
{
public:

	// ---> Constructors ------------------
	Fraction();
	Fraction(int integer);
	Fraction(int numerator, int denominator);
	Fraction(int integer, int numerator, int denominator);
	Fraction(const Fraction& other);

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
