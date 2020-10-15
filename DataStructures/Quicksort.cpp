/*
	Author : Kwanwoong Yoon
	Date : 2020. 10. 14
*/

#include <iostream>

using namespace std;

int arr[10] = {52, 5, 22, 60, 30, 1, 2, 1, 60, 8};

void swap(int i, int j) {
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

void Quicksort(int left, int right) {
	if (left >= right)return;
	int pivot = arr[left], i = left+1, j = right;
	while (i < j) {
		while (arr[i] <= pivot)i++;
		while (arr[j] > pivot)j--;
		if (i < j)swap(i, j);
	}
	swap(left, j);
	Quicksort(left, j - 1);
	Quicksort(j + 1, right);
}

int main() {
	Quicksort(0, 9);
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << ' ';
	}
	cout << '\n';
}