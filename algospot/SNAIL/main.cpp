#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>

#pragma warning(disable: 4996)
using namespace std;

int C, n, m;
double total, dp[1000 + 1][2000 + 1];



int main() {
	cin >> C;
	memset(dp, 0, sizeof(dp));
	dp[1][1] = 0.25; dp[1][2] = 0.75;
	for (int i = 2; i <= 1000; i++) {
		for (int j = i; j <= (i << 1); j++) {
			dp[i][j] = 0.75 * dp[i - 1][j - 2] + 0.25 * dp[i - 1][j - 1];
		}
	}
	for (int c = 1; c <= C; c++) {
		cin >> n >> m;
		total = 0;
		for (int i = n; i <= (m << 1); i++) {
			total += dp[m][i];
		}
		printf("%.10lf\n", total);
	}
}