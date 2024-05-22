#include "specialSorting.h"
#include "sorting.h"

#include <iostream>


//создание "специальных" массивов элементов
void generateSpecialArray(bool key) {
	if (arrayS != nullptr) delete[] arrayS;
	arrayS = new int[sizeTag];

	if (!key) { //для карманной сортировки БЕЗ повторов
		for (int i = 0; i < sizeTag; i++) arrayS[i] = i;
		int randIndex;
		for (int i = 0; i < sizeTag; i++) {
			randIndex = rand() % sizeTag;
			std::swap(arrayS[i], arrayS[randIndex]);
		}
	}

	std::cout << "Начальный массив: ";
	printArray(arrayS);
}



//карманная сортировка БЕЗ повторов
void pocketSort(bool key) {
	generateSpecialArray(false);
	/* Пример из методички
	sizeTag = 10;
	arrayS = new int[10] {3, 1, 4, 6, 0, 7, 2, 9, 5, 8};
	printArray(arrayS);
	*/
	resetCounters();
	int* arr = copy();
	if (key) { 
		int* sortedArray = new int[sizeTag];
		for (int i = 0; i < sizeTag; i++) {
			sortedArray[arr[i]] = arr[i];
			forwardingCounter++;
		}

		delete[] arr;
		arr = sortedArray;
	}
	else {
		int temp;

		for (int i = 0; i < sizeTag; i++) {
			
			while (arr[i] != i) {
				comparisonCounter++;
				temp = arr[arr[i]];
				arr[arr[i]] = arr[i];
				arr[i] = temp;
				forwardingCounter++;
			}
			comparisonCounter++;
		}
	}

	if (sizeTag <= 200000) {
		std::cout << "Отсортирован карманной сортировкой: ";
		printArray(arr);
		printCounters();
	}
	else {
		std::cout << "Для введенного массива из " << sizeTag << " элементов карманная сортировка потребовала:  ";
		printCounters();
	}
}


//сортировки которые предполагают использование дополнительного списка

//карманная сортировка С повторами
void generalizedPocketSort()
{
	resetCounters();

	int arraySize = sizeTag;
	int* arr;

	//создание массива элементов
	if (sizeTag > 0 && sizeTag <= 1000)
	{
		arr = new int[sizeTag];
		for (int i = 0; i < sizeTag; i++)
			arr[i] = rand() % sizeTag;
		std::cout << "Массив создан:" << std::endl;
		if(sizeTag <= 20)
			printArray(arr);
	}
	else { return; }
	

	ListItem* sortedArray = new ListItem[sizeTag];
	for (int i = 0; i < sizeTag; i++)
		sortedArray[i].next = nullptr;

	for (int i = 0; i < sizeTag; i++, forwardingCounter++)
		AddItem(&sortedArray[arr[i]], arr[i]); 

	ShowPocket(sortedArray, sizeTag);
	printCounters();
	for (int i = 0; i < sizeTag; i++)
		ClearList(sortedArray[i].next);
	delete[] sortedArray;
}

//поразрядная сортировка С использованием списка
void RadixSort()
{
	setlocale(LC_ALL, "ru");

	/*sizeTag = 15;
	arrayS = new int[15] {56, 17, 83, 9, 11, 27, 33, 2, 16, 45, 8, 37, 66, 99, 90};
	printArray(arrayS);*/

	int size = sizeTag;
	
	int* arr = copy();

	ListItem* sortedArray = new ListItem[10];
	int max = 0; //макимальное число в списке => максимальное количство разрядов
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}

	int i = 0;
	resetCounters();
	while (max >= 1)
	{
		i++;
		max /= 10; 
		for (int j = 0; j < 10; j++)
			sortedArray[j].next = nullptr;
		for (int j = 0; j < size; j++)
		{
			int div = 1;
			for (int l = 0; l < i; l++, div *= 10);
			AddItem(&sortedArray[((arr[j] % div) * 10) / div], arr[j]);
			forwardingCounter++;
		}
		for (int j = 0, l = 0; l < size; j++)
		{
			ListItem* tmp = sortedArray[j].next;
			while (tmp != NULL)
			{
				arr[l] = tmp->data;
				tmp = tmp->next;
				l++;
			}
		}
		for (int j = 0; j < 10; j++)
			ClearList(sortedArray[j].next);
	}
	std::cout << "Отсортированный массив:" << std::endl;
	printArray(arr);
	printCounters();
	delete[] sortedArray;
}


//Дополнительные функции для работы со списком

void AddItem(ListItem* pItem, int value)
{
	while (pItem->next != nullptr)
		pItem = pItem->next;
	pItem->next = new ListItem;
	pItem->next->data = value;
	pItem->next->next = nullptr;
}

void ClearList(ListItem* head)
{
	while (head != nullptr)
	{
		ListItem* tmp = head;
		head = head->next;
		delete tmp;
	}
}

void ShowPocket(ListItem* mas, int n)
{
	std::cout << "Отсортированный массив:" << std::endl;
	for (int i = 0; i < n; i++)
	{
		ListItem* current = mas[i].next;
		while (current != nullptr)
		{
			std::cout << current->data << " ";
			current = current->next;
		}
	}
	std::cout << std::endl;
}


//поразрядная сортировка БЕЗ использования списка
void radixSort() {

	std::cout << "Начальный массив элементов: ";

	/*
	sizeTag = 15;
	arrayS = new int[15] {56, 17, 83, 9, 11, 27, 33, 2, 16, 45, 8, 37, 66, 99, 90};
	printArray(arrayS);
	*/

	if (sizeTag <= 0) return;
	resetCounters();
	int* arr = copy();

	int maxNum = arr[0];
	for (int i = 1; i < sizeTag; ++i) {
		if (arr[i] > maxNum) {
			maxNum = arr[i];
		}
	}
	int i{ 1 };
	for (int exp = 1; maxNum / exp > 0; exp *= 10) {
		std::cout << "Массив, отсортирован по " << i++ << " разряду: " << std::endl;
		countSort(arr, sizeTag, exp);
		printArray(arr);
	}
	std::cout << "Полностью отсортированный массив: ";
	printArray(arr);
	printCounters();
}

void countSort(int arr[], int n, int exp) {

	const int BASE = 10;
	int* output = new int[n];
	int count[BASE] = { 0 };

	for (int i = 0; i < n; ++i) {
		count[(arr[i] / exp) % BASE]++;
	}


	for (int i = 1; i < BASE; ++i) {
		count[i] += count[i - 1];
	}


	for (int i = n - 1; i >= 0; --i) {
		output[count[(arr[i] / exp) % BASE] - 1] = arr[i];
		count[(arr[i] / exp) % BASE]--;
		forwardingCounter++;
	}

	for (int i = 0; i < n; ++i) {
		arr[i] = output[i];
		forwardingCounter++;
	}
	delete[] output;
}