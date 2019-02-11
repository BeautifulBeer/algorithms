#include <iostream>

using namespace std;


int main() {
	int n;
	int* cache;
	cin >> n;
	cache = new int[n + 1];
	cache[0] = 1;
	cache[1] = 1;
	for (int i = 2; i <= n; i++) {
		cache[i] = (cache[i - 1] + cache[i - 2]*2) % 10007;
	}
	cout << cache[n] << "\n";
	return 0;
}


