#include <cstring>
#include <iostream>

#include "String.h"

using namespace std;

// ---> Constructors
String::String() : string(new char[80]), size(80) {}

String::String(int strSize) : string(new char[strSize]), size(strSize) {}

String::String(const char* str) : string(new char[strlen(str)]), size(strlen(str))
{
	copy(str, str + size, string);
}

String::String(const String& other) : string(new char[other.size]), size(other.size)
{
	copy(other.string, other.string + other.size, string);
}

// ---> Destructor
String::~String()
{
	if (string) 
		delete[] string;

	if (size) 
		size = 0;
}

// ---> Getters
size_t String::getSize() const
{
	return this->size;
}

char String::operator[](int pos) const
{
	if (pos >= size) return 0;
	return string[pos];
}

char String::operator[](int pos)
{
	if (pos >= size) return 0;
	return string[pos];
}

// ---> Operators
String& String::operator+=(const String& other)
{
	// TODO: insert return statement here
	char* temp = string;

	string = new char[size + other.size];

	copy(temp, temp + size, string);
	copy(other.string, other.string + other.size, string + size);

	size += other.size;
	delete[] temp;

	return *this;
}

ostream& operator<<(ostream& out, const String string)
{
	int size = string.getSize();

	for (int i = 0; i < size; i++) 
		out << string[i];

	return out;
}

String operator+(String first, const String& second)
{
	return first += second;
}