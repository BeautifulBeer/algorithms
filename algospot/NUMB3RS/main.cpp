#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>

#pragma warning(disable: 4996)
using namespace std;

int C, N, D, P, cardinality[50], adjacent[50][50];
double total, cache[101][50];

void precalc() {
	// 노드의 cardinality 계산
	for (int i = 0; i < N; i++) {
		cardinality[i] = 0;
		for (int j = 0; j < N; j++) {
			if (adjacent[i][j] == 1) {
				cardinality[i]++;
			}
		}
	}
	// cache 배열 초기화
	for (int i = 0; i <= D; i++) {
		for (int j = 0; j < N; j++) {
			cache[i][j] = -1;
		}
	}
	for (int i = 0; i < N; i++) {
		cache[0][i] = 0;
	}
	// 0일에는 교도소에 있음
	cache[0][P] = 1;

}

double dp(int day, int idx) {
	double& ret = cache[day][idx];
	if (ret != -1)return ret;
	ret = 0;
	for (int i = 0; i < N; i++) {
		if (adjacent[idx][i] == 1) {
			ret += dp(day - 1, i) / cardinality[i];
		}
	}
	return ret;
}

int main() {
	int t, tmp;
	cin >> C;
	for (int c = 1; c <= C; c++) {
		cin >> N >> D >> P;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> adjacent[i][j];
			}
		}
		precalc();
		cin >> t;
		for (int i = 0; i < t; i++) {
			cin >> tmp;
			printf("%.8lf ", dp(D, tmp));
		}
		printf("\n");
	}
}