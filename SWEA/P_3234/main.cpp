#include <iostream>
#define MAXN 10

int N, T, result;
int weights[MAXN];
bool visit[MAXN];
int cache[20000];
int mul[MAXN] = { 1, 3, 9, 27, 81, 243, 729, 2187, 6561 };
int mul2[MAXN] = { 2, 6, 18, 54, 162, 486, 1458, 4374, 13122 };

using namespace std;

inline int dp(int left, int right, int depth, int state) {
	if (depth == N) {
		return 1;
	}
	int &ret = cache[state];
	if (ret > 0)return ret;
	int cnt = 0;
	for (register int i = 0; i < N; i++) {
		if (!visit[i]) {
			visit[i] = true;
			cnt += dp(left + weights[i], right, depth + 1, state + mul[i]);
			if (left >= right + weights[i]) {
				cnt += dp(left, right + weights[i], depth + 1, state + mul2[i]);
			}
			visit[i] = false;
		}
	}
	return ret = cnt;
}

int main() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		result = 0;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> weights[i];
		}
		for (int i = 0; i < 20000; i++) {
			cache[i] = 0;
		}
		cout << '#' << t << ' ' << dp(0, 0, 0, 0) << '\n';
	}
}