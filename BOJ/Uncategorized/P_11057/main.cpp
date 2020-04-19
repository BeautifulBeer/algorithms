#include <iostream>

using namespace std;

int N, result;
int cache[1000+1][10+1];

int main() {
	result = 0;
	cin >> N;
	cache[0][10] = 1;
	for (int i = 1; i <= N; i++) {
		cache[i][1] = 1;
	}
	for (int i = 1; i <= 9; i++) {
		cache[1][i] = 1;
	}
	for (int j = 1; j <= 9; j++) {
		result = (result + cache[1][j]) % 10007;
	}
	cache[1][10] = (cache[0][10] + result) % 10007;
	for (int i = 2; i <= N; i++) {
		result = 0;
		for (int j = 2; j < 10; j++) {
			cache[i][j] = (cache[i - 1][j] + cache[i][j - 1]) % 10007;
		}
		for (int j = 1; j <= 9; j++) {
			result = (result + cache[i][j]) % 10007;
		}
		cache[i][10] = (cache[i - 1][10] + result) % 10007;
	}
	cout << cache[N][10] << '\n';
}