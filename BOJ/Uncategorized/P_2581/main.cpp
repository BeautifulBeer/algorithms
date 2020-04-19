#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main() {
	int N, M, min=10001;
	long sum = 0;
	bool* sieves = new bool[10000 + 1];
	//prime check
	sieves[1] = false;
	for (int i = 2; i <= 10000; i++) {
		sieves[i] = true;
	}
	for (int i = 2; i <= 100; i++) {
		for (int j = 2; j < i; j++) {
			if (sieves[j]) {
				if (i % j == 0) {
					sieves[i] = false;
					break;
				}
			}
		}
	}
	int tmp;
	for (int i = 2; i <= 100; i++) {
		tmp = i*2;
		while (tmp <= 10000) {
			sieves[tmp] = false;
			tmp += i;
		}
	}
	cin >> N >> M;
	for (int i = N; i <= M; i++) {
		if (sieves[i]) {
			if (min > i) {
				min = i;
			}
			sum += i;
		}
	}
	if (sum == 0) {
		cout << -1 << endl;
	}
	else {
		cout << sum << "\n" << min;
	}
	return 0;
}


