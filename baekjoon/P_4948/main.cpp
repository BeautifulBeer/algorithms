#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

int main() {
	int N, result=0, max=123456*2;
	bool* sieves = new bool[max + 1];
	//prime check
	sieves[1] = false;
	for (int i = 2; i <= max; i++) {
		sieves[i] = true;
	}
	for (int i = 2; i <= (int)(sqrt(max)); i++) {
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
	for (int i = 2; i <= (int)(sqrt(max)); i++) {
		tmp = i * 2;
		while (tmp <= max) {
			sieves[tmp] = false;
			tmp += i;
		}
	}
	while (true) {
		cin >> N;
		result = 0;
		if (N == 0)break;
		for (int i = N + 1; i <= 2 * N; i++) {
			if (sieves[i]) {
				result++;
			}
		}
		cout << result << '\n';
	}
	return 0;

}


