#include <cstdio>

int memo[1000][1000];

int go(int n, int k) {
	if (n < k) {
		return 0;
	}
	if (memo[n][k] != -1) {
		return memo[n][k];
	}
	int result = (go(n - 1, k) + go(n - 1, k - 1)) % 10007;
	memo[n][k] = result;
	return result;
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			memo[i][j] = -1;
			if (j == 0) {
				memo[i][j] = 1;
			}
			else if (i == j) {
				memo[i][j] = 1;
			}
		}
	}
	printf("%d", go(n, k));
}