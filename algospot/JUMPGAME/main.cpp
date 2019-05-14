#include <cstdio>
#include <vector>
#include <algorithm>
#pragma warning(disable: 4996)
using namespace std;

int N, C, tmpx, tmpy, tmpx1, tmpy1;
int map[100][100];
int cache[100][100];

bool isInBound(int x, int y) {
	return (x >= 0 && x < N && y >= 0 && y < N);
}



int jump(int x, int y) {
	if (!isInBound(x, y)) {
		return 0;
	}
	if (x == N - 1 && y == N - 1) {
		return 1;
	}
	int& ret = cache[x][y];
	if (ret != -1) return ret;
	ret = jump(x + map[x][y], y) + jump(x, y + map[x][y]);
	return ret;
}

int main() {
	scanf("%d", &C);
	for (int c = 0; c < C; c++) {
		scanf(" %d", &N);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf(" %d", &map[i][j]);
				cache[i][j] = -1;
			}
		}
		if (jump(0, 0)) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
}