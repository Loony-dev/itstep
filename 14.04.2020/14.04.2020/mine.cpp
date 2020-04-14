#include <iostream>

/*
TODO:
1. Массив, заполненный случайными числами разделить на два массива МИНИМАЛЬНО ВОЗМОЖНОГО РАЗМЕРА: even - будет содержать четные элементы исходного массива, odd -  будет содержать НЕчетные элементы исходного массива;
2. Написать функции для работы с динамическими массивами:
	FillRand;																	>>>>>>>>>> DONE
	Print;																		>>>>>>>>>> DONE
	??? push_back(???) - добавляет элемент в конец массива;						>>>>>>>>>> IN PROCESS
	??? push_front(???) - добавляет элемент в начало массива;					>>>>>>>>>> IN PROCESS
	??? insert(???) - вставляет в массив новый элемент по указанному индексу;	>>>>>>>>>> IN PROCESS
	??? pop_back(???) - удаляет элемент с конца массива;						>>>>>>>>>> IN PROCESS
	??? pop_front(???) - удаляет элемент с начала массива;						>>>>>>>>>> IN PROCESS
	??? erase(???) - удаляет элемент по указанному индексу;						>>>>>>>>>> IN PROCESS
*/

using namespace std;

void fillRand(int array[], int size);
void print(int array[], int size);

void main()
{
	setlocale(LC_ALL, "");

	int n;

	cout << "Enter the size of array: ";
	cin >> n;

	int* array = new int[n];
	
	fillRand(array, n);
	print(array, n);

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