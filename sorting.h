﻿#pragma once

#include <iostream>
#include <vector>


const int SIZE10 = 10;
const int SIZE100 = 100;
const int SIZE1000 = 1000;
const int SIZE10000 = 10000;
extern int operation;
extern int sizeTag;
extern int* arrayS;

extern int comparisonCounter;
extern int forwardingCounter;

void printCounters();
int* copy();
void resetCounters();

void bubbleSortArray();
void selectionSortArray();
void insertionSortArray();

void printArray(int arr[]);
void fillingArray(bool key, int Size);
