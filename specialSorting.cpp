#include "specialSorting.h"
#include "sorting.h"

#include <iostream>
Node* ls = nullptr, * head = nullptr;

void generateSpecialArray(bool key) {
	if (arrayS != nullptr) delete[] arrayS;
	arrayS = new int[sizeTag];
	if (!key) {
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

void pocketSort(bool key) {
	generateSpecialArray(false);
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
				temp = arr[arr[i]];
				arr[arr[i]] = arr[i];
				arr[i] = temp;
				forwardingCounter++;
			}
		}
	}

	if (sizeTag <= 20) {
		std::cout << "Отсортирован карманной сортировкой: ";
		printArray(arr);
		printCounters();
	}
	else {
		std::cout << "Для введенного массива из " << sizeTag << " элементов карманная сортировка потребовала:  ";
		printCounters();
	}
}

void generalizedPocketSort() {
	if (arrayS != nullptr) delete[] arrayS;
	arrayS = new int[sizeTag];
	for (int i = 0; i < sizeTag; i++) arrayS[i] = rand() % 10;

	std::cout << "Начальный "; 
	printArray(arrayS);

	ls = new Node[10];

	for (int i = 0; i < sizeTag; i++) {
		if (ls[arrayS[i]].key == -1)
			ls[arrayS[i]].key = arrayS[i];
		else if (ls[arrayS[i]].next == NULL) {
			ls[arrayS[i]].next = new Node;
			ls[arrayS[i]].tail = ls[arrayS[i]].next;
			ls[arrayS[i]].next->key = arrayS[i];
		}
		else if (ls[arrayS[i]].tail->next == NULL) {
			ls[arrayS[i]].tail->next = new Node;
			ls[arrayS[i]].tail->next->key = arrayS[i];
			ls[arrayS[i]].tail = ls[arrayS[i]].tail->next;
		}
	}
	head = unification(ls);
	arrayS = convertToArray(head);
	std::cout << "Отсортированный ";
	printArray(arrayS);
}

Node* unification(Node* _ls) {
	Node* _head = new Node;
	_head->key = _ls[0].key;
	_head->next = _ls[0].next;
	_head->tail = _ls[0].tail;
	Node* pCurrent = _head;
	for (int i = 0; i < 9; i++) {
		if (_ls[i].tail != NULL)
			pCurrent = _ls[i].tail;
		pCurrent->next = new Node;
		pCurrent = pCurrent->next;
		pCurrent->key = _ls[i + 1].key;
		pCurrent->next = _ls[i + 1].next;
		pCurrent->tail = _ls[i + 1].tail;
	}
	return _head;
}

int* convertToArray(Node* _head) {
	Node* pCurrent = _head;
	int* c = new int[sizeTag];
	for (int i = 0; i < sizeTag; i++) {
		if (pCurrent->key == -1) i--;
		else c[i] = pCurrent->key;
		pCurrent = pCurrent->next;
	}
	return c;
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
	}

	for (int i = 0; i < n; ++i) {
		arr[i] = output[i];
	}
	delete[] output;
}

void radixSort() {
	
	std::cout << "Начальный массив элементов: ";
	printArray(arrayS);

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
		std::cout << std::endl;
	}
	std::cout << "Полностью отсортированный массив: ";
	printArray(arr);
}

