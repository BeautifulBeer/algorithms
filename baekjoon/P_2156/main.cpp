#include <iostream>
#include <queue>
#include <cstdarg>

using namespace std;

int n;
int wines[10000];
int cache[10000][3];

int mmax(int num, ...) {
	int result = 0, tmp;
	va_list vl;
	va_start(vl, num);
	for (int i = 0; i < num; i++) {
		tmp = va_arg(vl, int);
		if (result < tmp) {
			result = tmp;
		}
	}
	va_end(vl);
	return result;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> wines[i];
		cache[i][0] = cache[i][1] = cache[i][2] = 0;
	}
	cache[0][0] = wines[0];
	for (int i = 1; i < n; i++) {
		//윗줄 스티커 제거했을때
		cache[i][0] = cache[i - 1][2] + wines[i];
		//아랫줄 스티커 제거했을때
		cache[i][1] = cache[i - 1][0] + wines[i];
		//둘다 제거 안했을때
		cache[i][2] = mmax(3, cache[i - 1][0], cache[i - 1][1], cache[i-1][2]);
	}
	int result = mmax(3, cache[n - 1][0], cache[n - 1][1], cache[n - 1][2]);
	cout << result << '\n';
}