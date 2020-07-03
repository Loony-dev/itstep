#pragma once

using namespace std;

class String
{
public:

	// ---> Constructors
	String();
	String(int size);
	String(const char* str);
	String(const String& other);

	// ---> Destructor
	~String();

	// ---> Getters
	size_t getSize() const;
	char operator[](int pos) const;
	char operator[](int pos);

	// ---> Operators
	String& operator+=(const String& other);

private:
	char* string;
	size_t size;
};

ostream& operator<<(ostream& out, const String str);
String operator+(String left, const String& right);