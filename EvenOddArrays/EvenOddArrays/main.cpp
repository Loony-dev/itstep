#include <iostream>

using namespace std;

void fillRand(int array[], const int size);
void print(int array[], const int size);

void main()
{

	setlocale(LC_ALL, "");

	const int n = 10;
	int array[n];
	fillRand(array, n);
	print(array, n);

	int evenCount = 0;
	int oddCount = 0;

	for (int i = 0; i < n; i++)
	{
		if (array[i] % 2 == 0) evenCount++;
		else oddCount++;
	}

	cout << "Even count: " << evenCount << endl;
	cout << "Odd count: " << oddCount << endl;

	int* evenArray = new int[evenCount];
	int* oddArray = new int[oddCount];

	for (int i = 0, j = 0, k = 0; i < n; i++)
	{
		if(array[i] % 2 == 0) evenArray[j++] = array[i];
		else oddArray[k++] = array[i];
	}

	print(evenArray, evenCount);
	print(oddArray, oddCount);

	/*for (int i = 0; i < evenCount; i++) {
		evenArray[i] = ;
		cout << "Even array: " << evenCount << "\t";
	}

	for (int i = 0; i < oddCount; i++) {
		oddArray[i] = ;
		cout << "Odd array: " << oddCount << "\t";
	}*/

	delete[] evenArray;
	delete[] oddArray;

}

void fillRand(int array[], const int size)
{
	for (int i = 0; i < size; i++)
		array[i] = rand() % 2000;
}

void print(int array[], const int size)
{
	for (int i = 0; i < size; i++)
		cout << array[i] << "\t";

	cout << endl;
}