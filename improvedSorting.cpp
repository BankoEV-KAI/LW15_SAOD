#include "sorting.h"
#include "improvedSorting.h"

#include <algorithm>

//улучшенная сортировка пузырьком #1
void cocktailSort() {
    resetCounters();
    int* arr = copy();

    bool swapped = true;
    int start = 0;
    int end = sizeTag - 1;

    while (swapped) {
        swapped = false;

        for (int i = start; i < end; i++) {
            comparisonCounter++;
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
                forwardingCounter++;
            }
        }

        if (!swapped) {
            break;
        }

        end--;

        for (int i = end; i > start; i--) {
            comparisonCounter++;
            if (arr[i] < arr[i - 1]) {
                std::swap(arr[i], arr[i - 1]);
                swapped = true;
                forwardingCounter++;
            }
        }

        start++;
    }
    
    if (sizeTag <= 20) {
        std::cout << "Отсортирован улучшенной пузырьковой сортировкой (перемешиванием): ";
        printArray(arr);
        printCounters();
    }
    else {
        std::cout << "Для введенного массива из " << sizeTag << " элементов сортировка перемешиванием потребовала:  ";
        printCounters();
    }
}

//быстрая сортировка (тоже улученная пузырьковая (обменом)) 
void quickSort(int* mas, int size) {

    int i = 0;
    int j = size-1;

    int mid = mas[size / 2];

    do {
        while (mas[i] < mid) {
            comparisonCounter++;
            i++;
        }
        if (mas[i] > mid) //поиск справа элемента, меньшего опорного
            comparisonCounter++;
        while (mas[j] > mid) {
            comparisonCounter++;
            j--;
        }
        if (mas[j] < mid)
            comparisonCounter++;

        if (i <= j) {
            int tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;
            i++;
            j--;
            forwardingCounter++;
        }
    } while (i <= j);

    if (j > 0) {
        quickSort(mas, j + 1);
    }
    if (i < size) {
        quickSort(mas + i, size - i);
    }
}

void startQuickSort() {
    resetCounters();
    int* arr = copy();

    /*int* arr = new int[11] { 13, 42, 28, 17, 9, 25, 47, 31, 39, 15, 20 };
    int sizeTag = 11;*/

    quickSort(arr, sizeTag);
    forwardingCounter /= 2;
    if (sizeTag <= 2000) {
        std::cout << "Отсортирован быстрой сортировкой: ";
        printArray(arr);
        printCounters();
    }
    else {
        std::cout << "Для введенного массива из " << sizeTag << " элементов быстрая сортировка потребовала:  ";
        printCounters();
    }
}


//построение "пирамиды" 
void heapify(int arr[], int first, int last) {
    while (true)
    {
        int left = 2 * first + 1; //второй уровень и слева
        int right = 2 * first + 2; //второй уровень и справа
        int largest;

        if (left < last && arr[left] > arr[first]) { // если по убыванию считать, то arr[left] < arr[first]
            largest = left;
        }
        else {
            largest = first;
        }
        comparisonCounter++;

        if (right < last && arr[right] > arr[largest]) { // если по убыванию считать, то arr[right] < arr[largest]
            largest = right;
        }
        comparisonCounter++;

        if (largest == first) {
            break;
        }
        std::swap(arr[first], arr[largest]);
        forwardingCounter++;
        first = largest;
    }
}

//сортировка кучей, она же пирамидальная сортировка  (улучшение сортировки выбором)
void heapSort() {
    resetCounters();
    int* arr = copy();

    /*int* arr = new int[15] {45, 40, 28, 25, 30, 44, 33, 22, 60, 15, 55, 47, 66, 20, 50};
    sizeTag = 15;*/

    int n = sizeTag;
    for (int i = (n - 1) / 2; i >= 0; i--) { //просеивание == создание пирамиды
        heapify(arr, i, n);
    }

    for (int i = n - 1; i >= 1; i--) //сортировка
    {
        std::swap(arr[0], arr[i]);
        forwardingCounter++;
        heapify(arr, 0, i);
    }
    

    if (sizeTag <= 2000) {
        std::cout << "Отсортирован пирамидальной сортировкой: ";
        printArray(arr);
        printCounters();
    }
    else {
        std::cout << "Для введенного массива из " << sizeTag << " элементов пирамидальная сортировка потребовала:  ";
        printCounters();
    }
}


//сортировка Шелла (улучшенная сортировка вставками)
void shellSort() {
    resetCounters();
    int* arr = copy();

    /*int* arr = new int[6] {15, 33, 42, 7, 12, 19};
    sizeTag = 6;*/

    int countSteps = log2(sizeTag);
    
    //int steps[]{ 1,3,7,15,31,63,127,255,511,1023,2047,4097,8191 }; /
   
    int steps[]{ 1, 3, 7, 15, 31, 63, 127, 255, 511, 1023, 2047, 4095, 8191, 16383, 32767 };

    for (int gap = countSteps - 1; gap > -1; gap--) {
        int H = steps[gap];
        for (int i = H; i < sizeTag; i++) {
            int temp = arr[i];
            int j = i - H;
            forwardingCounter++;
            comparisonCounter++;
            while (j >= 0 && temp < arr[j]) {
                comparisonCounter++;
                arr[j + H] = arr[j];
                j = j - H;
                forwardingCounter++;
            }
            arr[j + H] = temp;
            forwardingCounter++;
        }
    }
    forwardingCounter = int(forwardingCounter / 3);
    /*
    // Если делать каждый шаг/2
    printCounters();
    resetCounters();
    arr = copy();
    for (int gap = sizeTag / 2; gap > 0; gap /= 2) {
        std::cout << gap << " ";
        for (int i = gap; i < sizeTag; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap; j -= gap) {
                comparisonCounter++;
                if (arr[j - gap] > temp) {
                    arr[j] = arr[j - gap];
                    forwardingCounter++;
                }
                else {
                    break;
                }
            }
            arr[j] = temp;
        }
    }
    std::cout << std::endl;
    */

    if (sizeTag <= 200000) {
        std::cout << "Отсортирован сортировкой Шелла: ";
        printArray(arr);
        printCounters();
    }
    else {
        std::cout << "Для введенного массива из " << sizeTag << " элементов сортировка Шелла потребовала:  ";
        printCounters();
    }
}



