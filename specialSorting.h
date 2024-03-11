#pragma once

#include <vector>

struct Node {
	int key = -1;
	Node* next = nullptr, * tail = nullptr;
};
extern Node* ls;
extern Node* head;

void pocketSort(bool key);

void generalizedPocketSort();

Node* unification(Node* _ls);

int* convertToArray(Node* _head);

void countSort(int arr[], int n, int exp);
void radixSort();
std::vector<int> radix_sort(std::vector<int> arr);
int radix_sort();
