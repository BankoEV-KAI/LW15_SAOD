#pragma once


void pocketSort(bool key);

void generalizedPocketSort();

void countSort(int arr[], int n, int exp);
void radixSort();

struct ListItem
{
	int data;
	ListItem* next;
};


void AddItem(ListItem* pItem, int value);

void ClearList(ListItem* head);

void ShowPocket(ListItem* mas, int n);

void RadixSort();
