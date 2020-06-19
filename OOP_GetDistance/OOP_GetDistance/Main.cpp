#include <iostream>

#include "Main.h"

int distance(int x, int y); // First task
int distance(int x1, int y1, int x2, int y2); // Second task

void main()
{
	using namespace std;

	Main _one(12, 54); // First task

	Main one(21, 17); // Second task
	Main two(12, 23); // Second task

	cout << distance(_one.getX(), _one.getY()) << endl;
	cout << distance(one.getX(), one.getY(), two.getX(), two.getY()) << endl;
}

int distance(int x, int y) // First task
{
	return sqrt(x * x + y * y); // Starting position -> 0
}

int distance(int x1, int y1, int x2, int y2) // Second task
{
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}