#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>

#pragma warning(disable: 4996)
using namespace std;

const long long NEGINF = numeric_limits<long long>::min();
int n, m, A[100], B[100];
int cache[101][101];

int jlis(int indexA, int indexB) {
	int& ret = cache[indexA + 1][indexB + 1];
	if (ret != -1)return ret;
	ret = 0;
	long long a = (indexA == -1 ? NEGINF : A[indexA]);
	long long b = (indexB == -1 ? NEGINF : B[indexB]);
	long long maxElement = max(a, b);

	for (int nextA = indexA + 1; nextA < n; ++nextA) {
		if (maxElement < A[nextA]) {
			ret = max(ret, jlis(nextA, indexB) + 1);
		}
	}
	for (int nextB = indexB + 1; nextB < m; ++nextB) {
		if (maxElement < B[nextB]) {
			ret = max(ret, jlis(indexA, nextB) + 1);
		}
	}
	return ret;
}

int main() {	
	int C;
	cin >> C;
	for (int c = 0; c < C; c++) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> A[i];
		}
		for (int j = 0; j < m; j++) {
			cin >> B[j];
		}
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= m; j++) {
				cache[i][j] = -1;
			}
		}
		cout << jlis(-1, -1) << '\n';
	}
}