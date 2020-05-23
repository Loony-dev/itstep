#pragma once
#include <iostream>

using namespace std;

void fillRand(int array[], int size);
void print(int array[], int size);

int* pushBack(int array[], int size, int value);
int* pushFront(int array[], int size, int value);
void insert(int array[], int size);

int* popBack(int array[], int size);
int* popFront(int array[], int size);
void erase(int array[], int size);