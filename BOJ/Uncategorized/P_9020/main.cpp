#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

int main() {
	int N, T, prime_a, prime_b, max=10000;
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
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		for (int i = N / 2; i < N-1; i++) {
			if (sieves[i] && sieves[N - i]) {
				prime_a = N-i;
				prime_b = i;
				break;
			}
		}
		cout << prime_a << ' ' << prime_b << '\n';
	}
}


