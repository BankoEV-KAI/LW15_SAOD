#include "sorting.h"
#include "menu.h"

int countIteration{ 0 };
int operation{0};
int sizeTag{0};
int* arrayS = nullptr;
int comparisonCounter{ 0 };
int forwardingCounter{ 0 };
std::vector<int> arrayD;


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
	else {
		for (int i = 0; i < size; i++)
			arrayD.push_back(rand() % 100);
	}
	sizeTag = size;
}


//базовые методы сортировки: обменом, выбором, вставками

void bubbleSortArray() {
	resetCounters();
	int* arr = copy();
	for (int i = 0; i < sizeTag - 1; i++) {
		for (int j = 0; j < sizeTag - i - 1; j++) {
			comparisonCounter++;
			if (arr[j] > arr[j + 1]) {
				std::swap(arr[j], arr[j + 1]);
				/*
				int* temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				*/
				forwardingCounter++;
			}
		}
	}

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
			if (arr[j] < arr[min_index]) {
				min_index = j;
			}
			comparisonCounter++;
		}
		if (min_index == i) forwardingCounter--;
		forwardingCounter++;
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
		comparisonCounter++;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
			forwardingCounter++;
		}

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


//Если все таки верну вектор

void bubbleSortVector(std::vector<int>& numbers)
{
	for (int i = numbers.size() - 1; i >= 0; i--) {
		for (int j = 1; j <= i; j++) {
			if (numbers[j - 1] > numbers[j]) {
				std::swap(numbers[j - 1], numbers[j]);
			}
		}
	}

}
void selectionSortVector(std::vector<int> numbers) {
	int n = numbers.size();
	for (int i = 0; i < n - 1; i++) {
		int min_index = i;
		for (int j = i + 1; j < n; j++) {
			if (numbers[j] < numbers[min_index]) {
				min_index = j;
			}
		}
		std::swap(numbers[i], numbers[min_index]);
	}
}
void insertionSortVector(std::vector<int> arr) {
	if (arr.empty()) {
		return;
	}

	for (size_t i = 1; i < arr.size(); i++) {
		int key = arr[i];
		size_t j = i - 1;

		while (j < arr.size() && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}

		arr[j + 1] = key;
	}
}
void printVector(std::vector<int> numbers) {
	for (int n : numbers)
		std::cout << n << " ";
}

