#include <iostream>

int N;
long long cache[90+1][2];

using namespace std;

int main() {
	cin >> N;
	for (int i = 0; i <= N; i++) {
		cache[i][0] = cache[i][1] = 0;
	}
	cache[1][1] = 1;
	for (int i = 2; i <= N; i++) {
		cache[i][0] = cache[i - 1][0] + cache[i - 1][1];
		cache[i][1] = cache[i - 1][0];
	}
	long long result = (cache[N][0] + cache[N][1]);
	cout << result << '\n';
}