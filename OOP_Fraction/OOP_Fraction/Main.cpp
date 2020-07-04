#include <iostream>

#include "Fraction.h"



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
	cout << "---> Addition (++) "; (++AFirst).print();
	cout << endl;

	// ---> Converting ------------------
	int a = AFirst;
	cout << "---> Fraction to int " << a << endl;

	double as = ASecond;
	cout << "---> Fraction to double " << as << endl;
	cout << endl;

	Fraction FD(2.5);
	cout << "---> Float "; FD.print();
	cout << endl;

	// ---> Comparison ------------------
	// CFirst/Second = Comparison First/Second
	Fraction CFirst(2, 3);
	Fraction CSecond(2, 3);

	if (CFirst != CSecond) {
		cout << "---> Comparison (==) (true) "; (CFirst + CSecond).print();
	}
	else 
	{
		cout << "---> Comparison (==) (false) "; (CFirst + CSecond).print();
	}
}

