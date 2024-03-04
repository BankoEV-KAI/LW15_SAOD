#include "sorting.h"
#include "menu.h"

int countIteration{ 0 };
int operation{0};
int sizeTag{0};
int* arrayS = nullptr;
int comparisonCounter{ 0 };
int forwardingCounter{ 0 };
std::vector<int>	 arrayD;


void bubbleSortArray() {
	comparisonCounter = 0; forwardingCounter = 0;
	int* arr = new int[sizeTag];
	for (int i = 0; i < sizeTag; i++)
		arr[i] = arrayS[i];

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


	std::cout << "Отсортирован пузырьковой сортировкой: ";
	printArray(arr);
	std::cout << "Количество сравнений " << comparisonCounter << ", количество пересылок " << forwardingCounter << " за время сортировки" << std::endl;

}

void selectionSortArray() {
	int* arr = new int[sizeTag];
	for (int i = 0; i < sizeTag; i++)
		arr[i] = arrayS[i];
	comparisonCounter = 0; forwardingCounter = 0;
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
	std::cout << "Отсортирован методом выбора: ";
	printArray(arr);
	std::cout << "Количество сравнений " << comparisonCounter << ", количество пересылок " << forwardingCounter << " за время сортировки" << std::endl;
}

void insertionSortArray() {
	int* arr = new int[sizeTag];
	for (int i = 0; i < sizeTag; i++)
		arr[i] = arrayS[i];
	comparisonCounter = 0; forwardingCounter = 0;
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
	std::cout << "Отсортирован вставками: ";
	printArray(arr);
	std::cout << "Количество сравнений " << comparisonCounter << ", количество пересылок " << forwardingCounter << " за время сортировки" << std::endl;


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
		for(int i=0; i < size; i++)
		arrayD.push_back(rand() % 100);
	}
	sizeTag = size;
}


//Если все таки верну вектор

void bubbleSortVector(std::vector<int> numbers)
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
	std::cout << std::endl;
}

