#include <cstdio>
#pragma warning(disable: 4996)
using namespace std;

int length_a, length_b;
char buf_a[1001];
char buf_b[1001];
int dp[1001][1001];

int max(int a, int b) {
	return (a > b) ? a : b;
}

int main() {
	scanf(" %s %s", buf_a, buf_b);
	for (int i = 0; i < 1001; i++) {
		if (buf_a[i] == '\0') {
			length_a = i;
			break;
		}
	}
	for (int i = 0; i < 1001; i++) {
		if (buf_b[i] == '\0') {
			length_b = i;
			break;
		}
	}
	for (int i = 1; i <= length_a; i++) {
		for (int j = 1; j <= length_b; j++) {
			if (buf_a[i - 1] == buf_b[j - 1]) {
				dp[i][j] = max(dp[i][j-1], dp[i-1][j-1]+1);
			}
			else {
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
	}
	printf("%d", dp[length_a][length_b]);
}