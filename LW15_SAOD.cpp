﻿
#include "sorting.h"
#include "menu.h"
#include <iostream>
#include "LW15_SAOD.h"
#include "improvedSorting.h"
#include "specialSorting.h"

int size;

int main()
{
    setlocale(LC_ALL, "ru");
    srand(static_cast<unsigned int>(time(0)));
    
    while (true) {
        printMenu(0);
        enteringNumber(0, 3, operation);
        switch (operation)
        {
        case 0:
            return 0;
        case 1:
            printMenu(1);
            enteringNumber(0, 2, operation);
            switch (operation)
            {
            case 1:
                printMenuCountArray();
                bubbleSortArray();
                insertionSortArray();
                selectionSortArray();
                startQuickSort();
                heapSort();
                shellSort();
                cocktailSort();
                break;
            case 2:
                printMenuCountArray();
                while (true) {
                    printMenu(3);
                    enteringNumber(0, 3, operation);
                    if (operation != 0) printSelectType();
                    else break;
                }
                break;
            default:
                break;
            }
            break;
        case 2:
            printMenu(1);
            enteringNumber(0, 2, operation);
            switch (operation)
            {
            case 1:
                printMenuCountArray();
                bubbleSortArray();
                insertionSortArray();
                selectionSortArray();
                startQuickSort();
                heapSort();
                shellSort();
                cocktailSort();
                std::cout << std::endl;
                break;
            case 2:
                printMenuCountArray();
                while (true) {
                    printMenu(4);
                    enteringNumber(0, 3, operation);
                    operation += 3;
                    if (operation != 3) printSelectType();
                    else break;
                }
                break;
            default:
                break;
            }
            break;
        case 3:
            printMenu(5);
            enteringNumber(0, 4, operation);
            switch (operation)
            {
            case 0:
                break;
            case 1:
                std::cout << "Количество элементов в масииве: ";
                enteringNumber(1, 10000, sizeTag);
                pocketSort(false);
                break;
            case 2:
                std::cout << "Количество элементов в масииве: ";
                enteringNumber(1, 10000, sizeTag);
                pocketSort(true);
                break;
            case 3:
                std::cout << "Количество элементов в масииве: ";
                enteringNumber(1, 10000, sizeTag);
                generalizedPocketSort();
                break;
            case 4:
                printMenuCountArray();
                radixSort();
                break;
            default:
                break;
            }
            break;
        
        default:
            break;
        }
    }

}

void printMenuCountArray() {
    printMenu(2);
    enteringNumber(0, 5, sizeTag);
    if (sizeTag == 1) fillingArray(1, 10);
    else if (sizeTag == 2) fillingArray(1, 100);
    else if (sizeTag == 3) fillingArray(1, 1000);
    else if (sizeTag == 4) fillingArray(1, 10000);
    else if (sizeTag == 5) fillingArray(1, sizeTag);
    else return;
    std::cout << "Массив до сортировок: ";
    printArray(arrayS);
    std::cout << std::endl;
}

void printSelectType() {
    if (operation != 0) {
        std::cout << "Массив до сортировки: ";
        printArray(arrayS);
    }
    switch (operation)
    {
    case 0:
        break;
    case 1:
        bubbleSortArray();
        break;
    case 2:
        insertionSortArray();
        break;
    case 3:
        selectionSortArray();
        break;
    case 4:
        startQuickSort();
        break;
    case 5:
        heapSort();
        break;
    case 6:
        shellSort();
        break;
    case 7:
        cocktailSort();
        break;
    default:
        break;
    }
}
