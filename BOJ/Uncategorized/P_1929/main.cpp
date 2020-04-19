#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

int main() {
	int N, M;
	bool* sieves = new bool[1000000 + 1];
	//prime check
	sieves[1] = false;
	for (int i = 2; i <= 1000000; i++) {
		sieves[i] = true;
	}
	cin >> N >> M;
	for (int i = 2; i <= (int)(sqrt(M)); i++) {
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
	for (int i = 2; i <= (int)(sqrt(M)); i++) {
		tmp = i*2;
		while (tmp <= M) {
			sieves[tmp] = false;
			tmp += i;
		}
	}
	for (int i = N; i <= M; i++) {
		if (sieves[i]) {
			cout << i << '\n';
		}
	}
	return 0;
}


