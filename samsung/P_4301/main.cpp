#include <iostream>

using namespace std;

int N, M, result, T, a, b;

int main() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		result = 0;
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				a = (i / 2) % 2; b = (j / 2) % 2;
				if ((a ^ b) == 0) {
					result++;
				}
			}
		}
		cout << '#' << t << ' ' << result << '\n';
	}
}