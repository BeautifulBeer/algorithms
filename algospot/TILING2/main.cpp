#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>

#pragma warning(disable: 4996)
using namespace std;

long long dp[101];

int main() {
	int C, n;
	cin >> C;
	memset(dp, -1, sizeof(dp));
	dp[0] = 0; dp[1] = 1; dp[2] = 2;
	for (int i = 3; i <= 100; i++) {
		dp[i] = (dp[i-1] + dp[i-2]) % 1000000007;
	}
	for (int c = 1; c <= C; c++) {
		cin >> n;
		cout << dp[n] << '\n';
	}
}