#include <iostream>

/*
TODO:
1. Массив, заполненный случайными числами разделить на два массива МИНИМАЛЬНО ВОЗМОЖНОГО РАЗМЕРА: even - будет содержать четные элементы исходного массива, odd -  будет содержать НЕчетные элементы исходного массива;
2. Написать функции для работы с динамическими массивами:
	FillRand;		>>>>>>>>>> DONE
	Print;			>>>>>>>>>> DONE
	??? push_back(???) - добавляет элемент в конец массива;		>>>>>>>>>> IN PROCESS
	??? push_front(???) - добавляет элемент в начало массива;	>>>>>>>>>> IN PROCESS
	??? insert(???) - вставляет в массив новый элемент по указанному индексу;	>>>>>>>>>> DONE
	??? pop_back(???) - удаляет элемент с конца массива;		>>>>>>>>>> IN PROCESS
	??? pop_front(???) - удаляет элемент с начала массива;		>>>>>>>>>> IN PROCESS
	??? erase(???) - удаляет элемент по указанному индексу;		>>>>>>>>>> IN PROCESS
*/

using namespace std;

void fillRand(int array[], int size);
void print(int array[], int size);

void pushBack(int array[], int size);
void pushFront(int array[], int size);
void insert(int array[], int size);

void popBack(int array[], int size);
void popFront(int array[], int size);
void erase(int array[], int size);

int n;
int array[n];
int* array = new int[n];
void main()
{
	setlocale(LC_ALL, ""); 

	cout << "Enter the size of array: ";
	cin >> n;
	cout << endl;
	
	fillRand(array, n);
	print(array, n);
	insert(array, n);
	pushBack(array, n);


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

void pushBack(int array[], int size) {
	int args;

	cout << "Enter the value want to add to the array: ";
	cin >> args;
	cout << endl;

	n++;
	array[n] = args;
	print(array, n);
}
void pushFront(int array[], int size) {}
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

void popBack(int array[], int size) {}
void popFront(int array[], int size) {}
void erase(int array[], int size) {}