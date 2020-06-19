#pragma once
#include <cmath>

class Main
{
public:
	Main(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	~Main() {}

	int getX() const
	{
		return x;
	}

	int getY() const
	{
		return x;
	}

private:
	int x;
	int y;
};