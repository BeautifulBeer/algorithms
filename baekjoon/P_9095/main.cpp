#include <iostream>

using namespace std;


int main() {
	int n, testCase;
	int* cache;
	cin >> testCase;
	cache = new int[11+1];
	for (int i = 0; i < testCase; i++) {
		cin >> n;
		cache[0] = 1;
		cache[1] = 1;
		cache[2] = 2;
		for (int i = 3; i <= n; i++) {
			cache[i] = cache[i - 1] + cache[i - 2] + cache[i - 3];
		}
		cout << cache[n] << "\n";
	}
	return 0;
}


