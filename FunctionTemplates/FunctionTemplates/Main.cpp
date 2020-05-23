#include "functions.h"

void main()
{
	setlocale(LC_ALL, "");

	int n;
	int value;

	cout << "Enter the size of array: ";
	cin >> n;
	cout << endl;

	int* array = new int[n];

	fillRand(array, n);
	print(array, n);
	insert(array, n);

	cout << "Enter value for push back: ";
	cin >> value;
	cout << endl;
	array = pushBack(array, n, value);
	n++;
	print(array, n);

	cout << "Enter value for push front: ";
	cin >> value;
	cout << endl;
	array = pushFront(array, n, value);
	n++;
	print(array, n);

	cout << "Pop back:" << endl;
	array = popBack(array, n);
	n--;
	print(array, n);

	cout << "Pop front:" << endl;
	array = popFront(array, n);
	n--;
	print(array, n);

	delete[] array;
}