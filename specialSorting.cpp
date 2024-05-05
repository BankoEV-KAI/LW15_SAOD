#include "specialSorting.h"
#include "sorting.h"

#include <iostream>


//�������� "�����������" �������� ���������
void generateSpecialArray(bool key) {
	if (arrayS != nullptr) delete[] arrayS;
	arrayS = new int[sizeTag];

	if (!key) { //��� ��������� ���������� ��� ��������
		for (int i = 0; i < sizeTag; i++) arrayS[i] = i;
		int randIndex;
		for (int i = 0; i < sizeTag; i++) {
			randIndex = rand() % sizeTag;
			std::swap(arrayS[i], arrayS[randIndex]);
		}
	}

	std::cout << "��������� ������: ";
	printArray(arrayS);
}

//��������� ���������� ��� ��������
void pocketSort(bool key) {
	generateSpecialArray(false);
	/* ������ �� ���������
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

	if (sizeTag <= 20) {
		std::cout << "������������ ��������� �����������: ";
		printArray(arr);
		printCounters();
	}
	else {
		std::cout << "��� ���������� ������� �� " << sizeTag << " ��������� ��������� ���������� �����������:  ";
		printCounters();
	}
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

//����������� ���������� ��� ������������� ������
void radixSort() {
	
	std::cout << "��������� ������ ���������: ";

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
		std::cout << "������, ������������ �� " << i++ << " �������: " << std::endl;
		countSort(arr, sizeTag, exp);
		printArray(arr);
	}
	std::cout << "��������� ��������������� ������: ";
	printArray(arr);
	printCounters();
}


//���������� ������� ������������ ������������� ��������������� ������

//��������� ���������� � ���������
void generalizedPocketSort()
{
	resetCounters();

	int arraySize = sizeTag;
	int* arr;

	//�������� ������� ���������
	if (sizeTag > 0 && sizeTag <= 10000)
	{
		arr = new int[sizeTag];
		for (int i = 0; i < sizeTag; i++)
			arr[i] = rand() % sizeTag;
		std::cout << "������ ������:" << std::endl;
		if(sizeTag <= 20)
			printArray(arr);
	}
	else { return; }
	

	ListItem* sortedArray = new ListItem[sizeTag];
	for (int i = 0; i < sizeTag; i++)
		sortedArray[i].next = NULL;
	for (int i = 0; i < sizeTag; i++, forwardingCounter++)
		AddItem(&sortedArray[arr[i]], arr[i]); 
	ShowPocket(sortedArray, sizeTag);

	ShowPocket(sortedArray, sizeTag);
	printCounters();
	for (int i = 0; i < sizeTag; i++)
		ClearList(sortedArray[i].next);
	delete[] sortedArray;
}

//����������� ���������� � �������������� ������
void RadixSort()
{
	int size = sizeTag;
	fillingArray(true, size);
	ListItem* sortedArray = new ListItem[10];
	int* arr = copy();
	int max = 0;
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
	std::cout << "��������������� ������:" << std::endl;
	printArray(arr);
	printCounters();
	delete[] sortedArray;
}


//�������������� ������� ��� �������� ������

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
	std::cout << "��������������� ������:" << std::endl;
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
