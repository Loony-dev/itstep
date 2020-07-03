#include <iostream>

#include "String.h"

void main()
{
	using namespace std;

	String str1;
	String str2 = 5;
	String str3 = "Hello"; 
	String str4 = "World!";
	String str5 = str3 + str4;

	cout << "---> Size string 1 > " << str1.getSize() << endl;
	cout << "---> Size string 2 > " << str2.getSize() << endl;
	cout << "---> Size string 3 > " << str3.getSize() << endl;
	cout << "---> Size string 4 > " << str4.getSize() << endl;
	cout << "---> Size string 5 > " << str5.getSize() << endl << endl;

	cout << "---> String 2 > " << str3 << endl;
	cout << "---> String 4 > " << str4 << endl;
	cout << "---> String 5 > " << str5 << endl;
}