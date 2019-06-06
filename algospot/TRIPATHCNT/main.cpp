#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>

#pragma warning(disable: 4996)
using namespace std;

int n, C;
int tri[101][101];
int max_tri[101][101];
int cnt_tri[101][101];

int dp(int x, int y) {
	if (x == n) {
		cnt_tri[x][y] = 1;
		return tri[x][y];
	}
	int& ret = max_tri[x][y];
	if (ret != -1) return ret;
	int a = dp(x + 1, y);
	int b = dp(x + 1, y + 1);
	if (a > b) {
		cnt_tri[x][y] = cnt_tri[x + 1][y];
		ret = a;
	}
	else if (a == b) {
		cnt_tri[x][y] = cnt_tri[x + 1][y] + cnt_tri[x+1][y+1];
		ret = a;
	}
	else {
		cnt_tri[x][y] = cnt_tri[x + 1][y + 1];
		ret = b;
	}
	ret += tri[x][y];
	return ret;
}

int main() {
	cin >> C;
	for (int c = 1; c <= C; c++) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= i; j++) {
				cin >> tri[i][j];
			}
		}
		memset(max_tri, -1, sizeof(max_tri));
		memset(cnt_tri, -1, sizeof(cnt_tri));
		dp(1, 1);
		cout << cnt_tri[1][1] << '\n';
	}
}