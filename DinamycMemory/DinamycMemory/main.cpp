#include <iostream>

using namespace std;

void fillRand(int array[], int size);
void print(int array[], int size);

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Enter the size of array: ";
	cin >> n;
	cout << endl;

	int* array = new int[n];

	fillRand(array, n);
	print(array, n);

	delete[] array;
}

void fillRand(int array[], int size)
{
	for (int i = 0; i < size; i++)
		array[i] = rand() % 2000;
}

void print(int array[], int size)
{
	for (int i = 0; i < size; i++)
		cout << array[i] << "\t";
	cout << endl;
}