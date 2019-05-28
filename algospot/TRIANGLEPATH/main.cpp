#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

#pragma warning(disable: 4996)
using namespace std;

int C, n;
int triangle[100][100];
int cache[100][100];

int mmax(int a, int b) {
	return (a > b) ? a : b;
}

int dp(int x, int y) {
	if (x >= n)return 0;
	int& ret = cache[x][y];
	if (ret != 0)return ret;
	return ret = mmax(dp(x + 1, y + 1), dp(x + 1, y)) + triangle[x][y];
}

int main() {	
	cin >> C;
	for (int c = 1; c <= C; c++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= i; j++) {
				cin >> triangle[i][j];
				cache[i][j] = 0;
			}
		}
		cout << dp(0, 0) << '\n';
	}
}