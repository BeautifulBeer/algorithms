#include <iostream>

using namespace std;

int N, M, max_value, tmp, tmpx, tmpy;
int map[500][500];
int delta[4][2] = {
	{0, -1},
	{-1, 0},
	{0, 1},
	{1, 0}
};

/* x, y is current position, length is shape length, flag  true is generate shapes to the right way / false is to the left
 this function can cover 3 shapes
               け     けけ
 けけけけ  けけけ   けけ
*/
void dfs(int x, int y, int length, int sum, bool flag) {
	if (length == 4) {
		if (max_value < sum) {
			max_value = sum;
		}
		return;
	}
	if (x < 0 || y < 0 || x >= N || y >= M) {
		return;
	}
	sum += map[x][y];
	length++;
	if (flag) {
		dfs(x + 1, y, length, sum, flag);
		dfs(x, y + 1, length, sum, flag);
	}
	else {
		dfs(x - 1, y, length, sum, flag);
		dfs(x, y + 1, length, sum, flag);
	}
}

// x y should be < N-1
/*
  けけ
  けけ
*/
void check_square(int x, int y) {
	int sum = map[x][y] + map[x + 1][y] + map[x][y + 1] + map[x + 1][y + 1];
	if (max_value < sum) {
		max_value = sum;
	}
}

/*     
               け    
    check    けけけ
*/
void check_center(int x, int y) {
	int sum, idx;
	for (int i = 0; i < 4; i++) {
		sum = map[x][y]; idx = i;
		for (int j = 0; j < 3; j++) {
			idx = (idx + j) % 4;
			tmpx = x + delta[idx][0];
			tmpy = y + delta[idx][1];
			if (tmpx < 0 || tmpx >= N || tmpy < 0 || tmpy >= M) {
				break;
			}
			sum += map[tmpx][tmpy];
		}
		if (max_value < sum) {
			max_value = sum;
		}
	}
}

int main(){
	max_value = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> tmp;
			map[i][j] = tmp;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			dfs(i, j, 0, 0, true);
			dfs(i, j, 0, 0, false);
			check_center(i, j);
		}
	}
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < M - 1; j++) {
			check_square(i, j);
		}
	}
	cout << max_value << endl;
}