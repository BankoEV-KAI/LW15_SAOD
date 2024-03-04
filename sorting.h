#pragma once

#include <iostream>
#include <vector>


const int SIZE10 = 10;
const int SIZE100 = 100;
const int SIZE1000 = 1000;
const int SIZE10000 = 10000;
extern int operation;
extern int sizeTag;
extern int* arrayS;
extern std::vector<int> arrayD;

extern int comparisonCounter;
extern int forwardingCounter;

void bubbleSortArray();

void bubbleSortVector(std::vector<int> numbers);

void selectionSortArray();

void selectionSortVector(std::vector<int> numbers);

void insertionSortArray();

void insertionSortVector(std::vector<int> arr);

void printVector(std::vector<int> numbers);

void printArray(int arr[]);

void fillingArray(bool key, int Size);
