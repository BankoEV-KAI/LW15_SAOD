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
	std::cout << "сравнений: " << comparisonCounter << ", перестановок: " << forwardingCounter << std::endl;
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
	if (sizeTag <= 20000) {
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

		if (arr[min_index] != arr[i]) {
			forwardingCounter++; //пересылки

			std::swap(arr[i], arr[min_index]);

			/* В явном виде:
				int* temp = arr[i];
				arr[i] = arr[min_index];
				arr[i] = temp;
			*/
		}
	}

	if (sizeTag <= 2000) {
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

	/*arrayS = new int[6] {15, 33, 42, 7, 12, 19};
	sizeTag = 6;*/
	

	int* arr = copy();
	

	for (int i = 1; i < sizeTag; i++) {
		int temp = arr[i];
		int j = i - 1;
		comparisonCounter++;
		forwardingCounter++;
		while (j >= 0 && temp < arr[j]) {
			comparisonCounter++;
			arr[j + 1] = arr[j];  
			/* фактически тут происходит "сдвиг" элемента, то есть на первой иттерации*(i=1) если массив был [5, 3, 4, 1, 2], то
			* он примет вид [5, 5, 4, 1, 2] в последствии на эту позицию будет вставлена та самая 3 [3, 5, 4, 1, 2] 
			*/
			j--;
			forwardingCounter++;
		}
		arr[j + 1] = temp;
		forwardingCounter++;
	}
	forwardingCounter = int(forwardingCounter / 3);

	//for (int i = 1; i < sizeTag; i++) {
	//	int temp = arr[i]; 
	//	int j = i - 1; 
	//	while (j >= 0 && temp < arr[j]) {
	//		comparisonCounter++; //сравнения
	//		forwardingCounter++; //перестановки
	//		std::swap(arr[j + 1], arr[j]);
	//		/* в явном виде swap:
	//			int* temp = arr[j];
	//			arr[j] = arr[j + 1];
	//			arr[j + 1] = temp;
	//		*/
	//		j--;
	//	}
	//	if (j != -1) 
	//		comparisonCounter++; //сравнения вайл не сработал, но сравление было
	//}	

	if (sizeTag <= 5000) {
		std::cout << "Отсортирован сортировкой вставками: ";
		printArray(arr);
		printCounters();
	}
	else {
		std::cout << "Для введенного массива из " << sizeTag << " элементов сортировка вставками потребовала:  ";
		printCounters();
	}

}

