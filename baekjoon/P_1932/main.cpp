#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int** arr;
int** cache;

int main() {
	int N, a, b, result;
	cin >> N;
	arr = new int*[N];
	cache = new int*[N];
	for (int i = 0; i < N; i++) {
		arr[i] = new int[N];
		cache[i] = new int[N];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			if (i - 1 >= 0 && j - 1 >= 0) {
				a = arr[i][j] + cache[i - 1][j - 1];
			}
			else {
				a = arr[i][j];
			}
			if (i - 1 >= 0 && j < i) {
				b = arr[i][j] + cache[i - 1][j];
			}
			else {
				b = arr[i][j];
			}
			cache[i][j] = (a > b)?a:b;
		}
	}

	result = cache[N - 1][0];
	for (int i = 1; i < N; i++) {
		if (result < cache[N - 1][i]) {
			result = cache[N - 1][i];
		}
	}
	cout << result;
}


