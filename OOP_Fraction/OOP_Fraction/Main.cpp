#include <iostream>

#include "Fraction.h"

Fraction operator+(Fraction first, Fraction second);
Fraction operator-(Fraction first, Fraction second);
Fraction operator*(Fraction first, Fraction second);
Fraction operator/(Fraction first, Fraction second);

void main()
{
	using namespace std;

	// ---> Multiplication ------------------
	// MFirst/Second = Multiplication First/Second
	Fraction MFirst(2, 3);
	Fraction MSecond(5, 7);

	cout << "---> Multiplication (*)  "; (MFirst * MSecond).print();
	cout << "---> Multiplication (*=) "; (MFirst *= MSecond).print();
	cout << endl;

	// ---> Division ------------------
	// DFirst/Second = Division First/Second
	Fraction DFirst(2, 3);
	Fraction DSecond(5, 7);

	cout << "---> Division (/)  "; (DFirst / DSecond).print();
	cout << "---> Division (/=) "; (DFirst /= DSecond).print();
	cout << endl;

	// ---> Subtraction ------------------
	// SFirst/Second = Subtraction First/Second
	Fraction SFirst(2, 3);
	Fraction SSecond(5, 7);

	cout << "---> Subtraction (-)  "; (SFirst - SSecond).print();
	cout << "---> Subtraction (-=) "; (SFirst -= SSecond).print();
	cout << endl;

	// ---> Addition ------------------
	// AFirst/Second = Addition First/Second
	Fraction AFirst(2, 3);
	Fraction ASecond(5, 7);

	cout << "---> Addition (+)  "; (AFirst + ASecond).print();
	cout << "---> Addition (+=) "; (AFirst += ASecond).print();
	cout << endl;
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