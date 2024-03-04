
#include "sorting.h"
#include "menu.h"
#include <iostream>
#include "LW15_SAOD.h"
#include "improvedSorting.h"

int size;

int main()
{
    setlocale(LC_ALL, "ru");
    srand(static_cast<unsigned int>(time(0)));


    
    while (true) {
        printMenu(1);
        enteringNumber(0, 2, operation);
        switch (operation)
        {
        case 0:
            return 0;
        case 1:
            printMenuCountArray();
            bubbleSortArray();
            insertionSortArray();
            selectionSortArray();
            cocktailSort();
            startQuickSort();
            heapSort();
            shellSort();
            
            break;
        case 2:
            printMenuCountArray();
            while (true) {
                printMenu(4);
                enteringNumber(0, 3, operation);
                if (operation != 0) printSelectType();
                else break;                
            }
            break;
        default:
            break;
        }
    }

}

void printMenuCountArray() {
    printMenu(3);
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
    default:
        break;
    }
}
