#include <iostream>
#include "menu.h"



void enteringNumber(int rangeStart, int rangeStop, int& value) {
    while (true) {
        std::cout << "Введите число от " << rangeStart << " до " << rangeStop << " >> ";
        std::cin >> value;

        if (std::cin.fail() || std::cin.peek() != '\n') {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Некорректный ввод. ";
        }
        else if (value >= rangeStart && value <= rangeStop) {
            return;
        }
        else {
            std::cout << "Некорректное число. ";
        }
    }
}

void printMenu(int operation) {
    switch (operation)
    {
    case 0:
        std::cout << std::endl
            << "1. Задание 2.1: базовые методы сортировки " << std::endl
            << "2. Задание 2.2: улучшенные методы сортировки " << std::endl
            << "3. Задание 2.3: специальные методы сортировки" << std::endl
            << "0. Завершение программы " << std::endl;
        break;
    case 1:
        std::cout << "1. Сравнение простейших сортировок и их улучшений для одного массива " << std::endl
            << "2. Выбор сортировки " << std::endl
            << "0. Назад " << std::endl;
        break;
    case 2:
        std::cout << "1. 10 элементов " << std::endl
            << "2. 100 элементов " << std::endl
            << "3. 1000 элементов " << std::endl
            << "4. 10000 элементов " << std::endl
            << "5. Другое количество элементов" << std::endl
            << "0. Назад " << std::endl;
        break;
    case 3:
        std::cout << "Простейшие алгоритмы сортировки" << std::endl
            << "1. Сортировка обменом " << std::endl
            << "2. Сортировка выбором " << std::endl
            << "3. Сортировка вставками " << std::endl
            << "0. Назад " << std::endl;
        break;
    case 4:
        std::cout << "Улучшенные алгоритмы сортировки" << std::endl
            << "1. Быстрая сортирвока" << std::endl
            << "2. Пирамидальная сортировка " << std::endl
            << "3. Сортировка Шелла (улучш вставками) " << std::endl
            << "4. Улучшенная сортировка обменом " << std::endl
            << "0. Назад " << std::endl;
        break;
    case 5:
        std::cout << "Специальные алгоритмы сортировки" << std::endl
            << "1. Простейшая карманная сортировка без доп массива" << std::endl
            << "2. Простейшая карманная сортировка с использование доп массива " << std::endl
            << "3. Обобщенная карманная сортировка " << std::endl
            << "4. Поразрядная сортировка " << std::endl
            << "0. Назад " << std::endl;
        break;
    default:
        break;
    }
}

