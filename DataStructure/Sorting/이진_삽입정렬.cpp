#include <iostream>
#include <vector>

using namespace std;
/*
	Binary Insertion Sort (이진 삽입정렬)

*/

int N;
int* arr;

int binary_search(int start, int end, int value) {
	if (start == end) {
		return start;
	}
	int mid = (start + end) / 2;
	if (arr[mid] < value) {
		binary_search(mid + 1, end, value);
	}
	else {
		binary_search(start, mid, value);
	}
}

void swap(int i, int j) {
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}


int main() {
	cin >> N;
	arr = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i < N; i++) {
		int v = arr[i];
		int put_idx = binary_search(0, i, v);
		for (int j = i; j > put_idx; j--) {
			arr[j] = arr[j - 1];
		}
		arr[put_idx] = v;
	}
	for (int i = 0; i < N; i++) {
		cout << arr[i] << '\n';
	}

}