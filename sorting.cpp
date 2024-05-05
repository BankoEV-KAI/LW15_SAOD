#include "sorting.h"
#include "menu.h"

int operation{0};
int sizeTag{0};
int* arrayS = nullptr;
int comparisonCounter{ 0 };
int forwardingCounter{ 0 };


//��� �������������� �����

void resetCounters() {
	comparisonCounter = 0;
	forwardingCounter = 0;
}

void printCounters() {
	std::cout << "���������: " << comparisonCounter << ", ���������: " << forwardingCounter << std::endl;
}

int* copy() {
	int* coped = new int[sizeTag];
	for (int i = 0; i < sizeTag; i++)
		coped[i] = arrayS[i];
	return coped;
}

void printArray(int arr[]) {

	for (int i = 0; i < sizeTag; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

void fillingArray(bool key, int size) {

	if (key) {
		if (arrayS != nullptr) delete[] arrayS;
		arrayS = new int[size];
		for (int i = 0; i < size; i++) {

			arrayS[i] = rand() % 100;
		}

	}
	sizeTag = size;
}


//������� ������ ����������: �������, �������, ���������

void bubbleSortArray() {
	resetCounters();
	int* arr = copy();
	for (int i = 0; i < sizeTag - 1; i++) {
		for (int j = 0; j < sizeTag - i - 1; j++) {
			comparisonCounter++; //���������
			if (arr[j] > arr[j + 1]) {
				std::swap(arr[j], arr[j + 1]);
				/* � ����� ����:
				int* temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				*/
				forwardingCounter++; //���������
			}
		}
	}

	// ������ ��� ������ 
	if (sizeTag <= 20) {
		std::cout << "������������ ����������� �����������: ";
		printArray(arr);
		printCounters();
	}
	else {
		std::cout << "��� ���������� ������� �� " << sizeTag << " ��������� ���������� ��������� �����������:  ";
		printCounters();
	}
}

void selectionSortArray() {
	resetCounters();
	int* arr = copy();
	for (int i = 0; i < sizeTag - 1; i++) {
		int min_index = i;
		for (int j = i + 1; j < sizeTag; j++) {
			comparisonCounter++; //���������
			if (arr[j] < arr[min_index]) {
				min_index = j;
			}
		}

		if (arr[min_index] != arr[i]) forwardingCounter++; //���������
		std::swap(arr[i], arr[min_index]);
	}

	if (sizeTag <= 20) {
		std::cout << "������������ ����������� �������: ";
		printArray(arr);
		printCounters();
	}
	else {
		std::cout << "��� ���������� ������� �� " << sizeTag << " ��������� ���������� ������� �����������:  ";
		printCounters();
	}
}

void insertionSortArray() {
	resetCounters();

	int* arr = copy();
	for (int i = 1; i < sizeTag; i++) {
		int key = arr[i];
		int j = i - 1;

		while (j >= 0 && arr[j] > key) {
			comparisonCounter++; //���������
			forwardingCounter++; //���������
			arr[j + 1] = arr[j];
			j--;
			
		}

		comparisonCounter++; //���������
		arr[j + 1] = key;
	}


	if (sizeTag <= 20) {
		std::cout << "������������ ����������� ���������: ";
		printArray(arr);
		printCounters();
	}
	else {
		std::cout << "��� ���������� ������� �� " << sizeTag << " ��������� ���������� ��������� �����������:  ";
		printCounters();
	}

}

