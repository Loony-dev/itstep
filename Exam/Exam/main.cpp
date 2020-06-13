#include <iostream>

#include "main.h"

int main()
{
	setlocale(LC_ALL, "");
	int columns;

	std::cout << "¬ведите число: ";
	std::cin >> columns;

	drawFinish(columns);

	return 0;
}

void drawPre(int columns, int i)
{
	for (int j = 0; j < columns; j++)
		if ((i + j) % 2 == 0) 
			std::cout << "+ ";
		else 
			std::cout << "- ";
	std::cout << "\n";
}

void drawFinish(int columns)
{
	for (int i = 0; i < columns; i++)
		drawPre(columns, i);
}