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
            forwardingCounter++; // увеличиваем счетчик на 1 при каждой пересылке
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
    quickSort(arr, sizeTag);
    forwardingCounter /= 2;
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


//построение "перамиды" 
void heapify(int arr[], int left, int right) {

    int i, j, x;
    i = left; j = 2 * left;

    x = arr[left];
    if ((j < right) && (arr[j + 1] > arr[j]))
    {
        j = j + 1;
    }
    while ((j <= right) && (arr[j] > x))
    {
        comparisonCounter++;
        arr[i] = arr[j];
        i = j;
        forwardingCounter++;
        j = 2 * j;
        if ((j < right) && (arr[j + 1] > arr[j]))
        {
            j = j + 1;
        }
    }
    comparisonCounter++;
    arr[i] = x;
}

//сортировка кучей, она же перамидальная сортировка  (улучшение сортировки выбором)
void heapSort() {
    resetCounters();
    int* arr = copy();
    int left = sizeTag / 2 + 1; 
    int right = sizeTag - 1;

    
    while (left > 0) //Цикл построения пирамиды
    {
        left = left - 1;
        heapify(arr, left, right);
    }
    while (right > 0) //Цикл сортировки
    {
        int temp = arr[0];
        arr[0] = arr[right];
        arr[right] = temp;
        right = right - 1;
        heapify(arr, left, right);
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


//сортировка Шелла (улучшенная сортировка вставками)
void shellSort() {
    resetCounters();
    int* arr = copy();
    int countSteps = log2(sizeTag);
    int steps[]{ 1,3,7,15,31,63,127,255,511,1023,2047,4097,8191 }; //формула элемента 2^(i+1) + 1;
    /*использована теорема (А.А. Папернова, Г.В. Стасевича)*/
    for (int gap = countSteps - 1; gap > -1; gap--) {
        int H = steps[gap];
        for (int i = H; i < sizeTag; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= H; j -= H) {
                comparisonCounter++;
                if (arr[j - H] > temp) {
                    arr[j] = arr[j - H];
                    comparisonCounter++;
                    forwardingCounter++;
                }
                else {
                    break;
                }
            }
            arr[j] = temp;
        }
    }

    
    
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



