#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>

#pragma warning(disable: 4996)
using namespace std;

int C, cnt, cache[101][101];

int dp(int n, int first) {
	if (n == first)return 1;
	int& ret = cache[n][first];
	if (ret != -1)return ret;
	ret = 0;
	for (int i = 1; i <= n - first; i++) {
		ret =  (ret + (first + i - 1) * dp(n - first, i))%10000000;
	}
	return ret;
}

int main() {
	int total;
	cin >> C;
	for (int c = 1; c <= C; c++) {
		total = 0;
		cin >> cnt;
		memset(cache, -1, sizeof(cache));
		for (int i = 1; i <= cnt; i++) {
			total = (total + dp(cnt, i))%10000000;
		}
		cout << total << '\n';
	}
}