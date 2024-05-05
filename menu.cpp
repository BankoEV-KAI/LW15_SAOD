#include <iostream>
#include "menu.h"



void enteringNumber(int rangeStart, int rangeStop, int& value) {
    while (true) {
        std::cout << "������� ����� �� " << rangeStart << " �� " << rangeStop << " >> ";
        std::cin >> value;

        if (std::cin.fail() || std::cin.peek() != '\n') {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "������������ ����. ";
        }
        else if (value >= rangeStart && value <= rangeStop) {
            return;
        }
        else {
            std::cout << "������������ �����. ";
        }
    }
}

void printMenu(int operation) {
    
    switch (operation)
    {
    case 0:
        std::cout << std::endl
            << "1. ������� 2.1: ������� ������ ���������� " << std::endl
            << "2. ������� 2.2: ���������� ������ ���������� " << std::endl
            << "3. ������� 2.3: ����������� ������ ����������" << std::endl
            << "0. ���������� ��������� " << std::endl;
        break;
    case 1:
        std::cout << "1. ��������� ���������� ���������� � �� ��������� ��� ������ ������� " << std::endl
            << "2. ����� ���������� " << std::endl
            << "0. ����� " << std::endl;
        break;
    case 2:
        std::cout << "1. 10 ��������� " << std::endl
            << "2. 100 ��������� " << std::endl
            << "3. 1000 ��������� " << std::endl
            << "4. 10000 ��������� " << std::endl
            << "5. ������ ���������� ���������" << std::endl
            << "0. ����� " << std::endl;
        break;
    case 3:
        std::cout << "���������� ��������� ����������" << std::endl
            << "1. ���������� ������� " << std::endl
            << "2. ���������� ������� " << std::endl
            << "3. ���������� ��������� " << std::endl
            << "0. ����� " << std::endl;
        break;
    case 4:
        std::cout << "���������� ��������� ����������" << std::endl
            << "1. ������� ����������" << std::endl
            << "2. ������������� ���������� " << std::endl
            << "3. ���������� ����� (����� ���������) " << std::endl
            << "4. ���������� ���������� ������� " << std::endl
            << "0. ����� " << std::endl;
        break;
    case 5:
        std::cout << "����������� ��������� ����������" << std::endl
            << "1. ���������� ��������� ���������� ��� ��� �������" << std::endl
            << "2. ���������� ��������� ���������� � ������������� ��� ������� " << std::endl
            << "3. ���������� ��������� ���������� " << std::endl
            << "4. ����������� ���������� " << std::endl
            << "0. ����� " << std::endl;
        break;
    default:
        break;
    }
}

