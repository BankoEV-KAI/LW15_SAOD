#include "sorting.h"
#include "menu.h"

int operation{0};
int sizeTag{0};
int* arrayS = nullptr;
int comparisonCounter{ 0 };
int forwardingCounter{ 0 };


//для информационной части

void resetCounters() {
	comparisonCounter = 0;
	forwardingCounter = 0;
}

void printCounters() {
	std::cout << "сравнений: " << comparisonCounter << ", пересылок: " << forwardingCounter << std::endl;
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


//базовые методы сортировки: обменом, выбором, вставками

void bubbleSortArray() {
	resetCounters();
	int* arr = copy();
	for (int i = 0; i < sizeTag - 1; i++) {
		for (int j = 0; j < sizeTag - i - 1; j++) {
			comparisonCounter++; //сравнения
			if (arr[j] > arr[j + 1]) {
				std::swap(arr[j], arr[j + 1]);
				/* В явном виде:
				int* temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				*/
				forwardingCounter++; //пересылки
			}
		}
	}

	// просто для вывода 
	if (sizeTag <= 20) {
		std::cout << "Отсортирован пузырьковой сортировкой: ";
		printArray(arr);
		printCounters();
	}
	else {
		std::cout << "Для введенного массива из " << sizeTag << " элементов сортировка пузырьком потребовала:  ";
		printCounters();
	}
}

void selectionSortArray() {
	resetCounters();
	int* arr = copy();
	for (int i = 0; i < sizeTag - 1; i++) {
		int min_index = i;
		for (int j = i + 1; j < sizeTag; j++) {
			comparisonCounter++; //сравнения
			if (arr[j] < arr[min_index]) {
				min_index = j;
			}
		}

		if (arr[min_index] != arr[i]) forwardingCounter++; //пересылки
		std::swap(arr[i], arr[min_index]);
	}

	if (sizeTag <= 20) {
		std::cout << "Отсортирован сортировкой выбором: ";
		printArray(arr);
		printCounters();
	}
	else {
		std::cout << "Для введенного массива из " << sizeTag << " элементов сортировка выбором потребовала:  ";
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
			comparisonCounter++; //сравнения
			forwardingCounter++; //пересылки
			arr[j + 1] = arr[j];
			j--;
			
		}

		comparisonCounter++; //сравнения
		arr[j + 1] = key;
	}


	if (sizeTag <= 20) {
		std::cout << "Отсортирован сортировкой вставками: ";
		printArray(arr);
		printCounters();
	}
	else {
		std::cout << "Для введенного массива из " << sizeTag << " элементов сортировка вставками потребовала:  ";
		printCounters();
	}

}

