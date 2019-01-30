#include <iostream>
#include <string>
#include <tuple>
using namespace std;

string quad_tree(bool** arr, int start_x, int start_y, int end_x, int end_y) {
	bool tmp = arr[start_x][start_y];
	bool same = true;
	if (end_x - start_x <= 1 && end_y - start_y <= 1) {
		return (tmp) ? "1" : "0";
	}
	
	for (int i = start_x; i < end_x; i++) {
		for (int j = start_y; j < end_y; j++) {
			if (tmp != arr[i][j]) {
				same = false;
				//break outer for loop
				i = end_x;
				break;
			}
		}
	}
	if (same) {
		return (tmp) ? "1" : "0";
	}
	else {
		return "(" +
			quad_tree(arr, start_x, start_y, (start_x + end_x) / 2, (start_y + end_y) / 2) +
			quad_tree(arr, start_x, (start_y + end_y) / 2, (start_x + end_x) / 2, end_y) +
			quad_tree(arr, (start_x + end_x) / 2, start_y, end_x, (start_y + end_y) / 2) +
			quad_tree(arr, (start_x + end_x) / 2, (start_y + end_y) / 2, end_x, end_y) +
			")";
	}
}


int main() {	
	int N;
	string line, result;
	bool** arr;

	cin >> N;
	//init arr
	arr = new bool*[N];
	for (int i = 0; i < N; i++) {
		arr[i] = new bool[N];
	}

	for (int i = 0; i < N; i++) {
		cin >> line;
		for (int j = 0; j < N; j++) {
			arr[i][j] = (line[j] == '0') ? false : true;
		}
	}

	result = quad_tree(arr, 0, 0, N, N);
	cout << result;
}
