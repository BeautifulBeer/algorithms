#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

#pragma warning(disable: 4996)
using namespace std;

int cache[101][101];
string W, S;
vector<string> strs;

bool matchMemoized(int w, int s) {
	int& ret = cache[w][s];
	if (ret != -1) return ret;

	if (w < W.size() && s < S.size() &&
		(W[w] == '?' || W[w] == S[s]))
		return ret = matchMemoized(w + 1, s + 1);

	if (w == W.size()) return ret = (s == S.size());

	if (W[w] == '*') {
		if (matchMemoized(w + 1, s) ||
			(s < S.size() && matchMemoized(w, s + 1)))
			return ret = 1;
	}
	return 0;
}

int main() {
	int C, N;
	cin >> C;
	for (int c = 1; c <= C; c++) {
		strs.clear();
		cin >> W;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> S;
			memset(cache, -1, sizeof(cache));
			if (matchMemoized(0, 0)) {
				strs.push_back(S);
			}
		}
		sort(strs.begin(), strs.end());
		for (int i = 0; i < strs.size(); i++) {
			cout << strs[i] << '\n';
		}
	}
	return 0;
}