#include <iostream>

/*
TODO:
1. Массив, заполненный случайными числами разделить на два массива МИНИМАЛЬНО ВОЗМОЖНОГО РАЗМЕРА: even - будет содержать четные элементы исходного массива, odd -  будет содержать НЕчетные элементы исходного массива;
2. Написать функции для работы с динамическими массивами:
	FillRand;		>>>>>>>>>> DONE
	Print;			>>>>>>>>>> DONE
	??? push_back(???) - добавляет элемент в конец массива;		>>>>>>>>>> DONE
	??? push_front(???) - добавляет элемент в начало массива;	>>>>>>>>>> DONE
	??? insert(???) - вставляет в массив новый элемент по указанному индексу;	>>>>>>>>>> DONE
	??? pop_back(???) - удаляет элемент с конца массива;		>>>>>>>>>> DONE
	??? pop_front(???) - удаляет элемент с начала массива;		>>>>>>>>>> DONE
	??? erase(???) - удаляет элемент по указанному индексу;		>>>>>>>>>> IN PROCESS
*/

using namespace std;

void fillRand(int array[], int size);
void print(int array[], int size);

int* pushBack(int array[], int size, int value);
int* pushFront(int array[], int size, int value);
void insert(int array[], int size);

int* popBack(int array[], int size);
int* popFront(int array[], int size);
void erase(int array[], int size);

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