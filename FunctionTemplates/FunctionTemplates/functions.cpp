#include "functions.h"

void fillRand(int array[], int size)
{
	for (int i = 0; i < size; i++)
		array[i] = rand() % 2000;
}

void print(int array[], int size)
{
	for (int i = 0; i < size; i++)
		cout << array[i] << "\t";
	cout << endl << endl;
}

int* pushBack(int array[], int size, int value) {
	int* buffer = new int[size + 1];

	for (int i = 0; i < size; i++)
		buffer[i] = array[i];

	delete[] array;

	array = buffer;
	buffer = nullptr;

	array[size] = value;
	size++;

	return array;
}
int* pushFront(int array[], int size, int value) {
	int* buffer = new int[size + 1];

	for (int i = 0; i < size; i++)
		buffer[i + 1] = array[i];

	delete[] array;

	array = buffer;
	buffer = nullptr;

	array[0] = value;
	size++;

	return array;
}
void insert(int array[], int size) {
	int key, args;

	cout << "Enter the number of the element of the array want to replace: ";
	cin >> key;
	cout << endl;

	if (key <= size)
	{

		cout << "Enter the value by which you want to replace the element from the array: ";
		cin >> args;
		cout << endl;

		array[key - 1] = args;
		print(array, size);
	}
}

int* popBack(int array[], int size) {
	int* buffer = new int[size];

	for (int i = 0; i < size; i++)
		buffer[i] = array[i];

	delete[] array;

	array = buffer;
	buffer = nullptr;

	size--;

	return array;
}
int* popFront(int array[], int size) {
	// Aoaoaoa not worked (nearly) --- falls into error
	int* buffer = new int[size - 1];

	for (int i = 0; i < size; i++)
		buffer[i] = array[i + 1];

	delete[] array;

	array = buffer;
	buffer = nullptr;

	size--;

	return array;
}
void erase(int array[], int size) {}