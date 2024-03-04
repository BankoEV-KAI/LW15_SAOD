#include "sorting.h"
#include "improvedSorting.h"

#include <algorithm>


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

void quickSort(int* mas, int size) {
    int i = 0;
    int j = size - 1;

    int mid = mas[size / 2];

    do {
        while (mas[i] < mid) {
            comparisonCounter++;
            i++;
        }
        while (mas[j] > mid) {
            comparisonCounter++;
            j--;
        }

        if (i <= j) {
            int tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;

            i++;
            j--;
            forwardingCounter += 3;
        }
    } while (i <= j);

    if (j > 0) {
        quickSort(mas, j + 1);
    }
    if (i < size) {
        quickSort(&mas[i], size - i);
    }
}

void startQuickSort() {
    resetCounters();
    int* arr = copy();
    quickSort(arr, sizeTag);
    if (sizeTag <= 20) {
        std::cout << "Отсортирован быстрой сортировкой: ";
        printArray(arr);
        printCounters();
    }
    else {
        std::cout << "Для введенного массива из " << sizeTag << " элементов быстрая сортировка потребовала:  ";
        printCounters();
    }
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n) {
        comparisonCounter++;
        if (arr[left] > arr[largest]) {
            largest = left;
        }
    }

    if (right < n) {
        comparisonCounter++;
        if (arr[right] > arr[largest]) {
            largest = right;
        }
    }

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        forwardingCounter += 3;
        heapify(arr, n, largest);
    }
}

void heapSort() {
    resetCounters();
    int* arr = copy();

    for (int i = sizeTag / 2 - 1; i >= 0; i--) {
        heapify(arr, sizeTag, i);
    }

    for (int i = sizeTag - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        forwardingCounter += 3;
        heapify(arr, i, 0);
    }

    if (sizeTag <= 20) {
        std::cout << "Отсортирован пирамидальной сортировкой: ";
        printArray(arr);
        printCounters();
    }
    else {
        std::cout << "Для введенного массива из " << sizeTag << " элементов пирамидальная сортировка потребовала:  ";
        printCounters();
    }
}

void shellSort() {
    resetCounters();
    int* arr = copy();

    for (int gap = sizeTag / 2; gap > 0; gap /= 2) {
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

    if (sizeTag <= 20) {
        std::cout << "Отсортирован сортировкой Шелла: ";
        printArray(arr);
        printCounters();
    }
    else {
        std::cout << "Для введенного массива из " << sizeTag << " элементов сортировка Шелла потребовала:  ";
        printCounters();
    }
}



