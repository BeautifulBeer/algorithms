#include <iostream>
#include <queue>

using namespace std;

int N, W, H, result_min, T;
int map[15][12];
int backup[15][12];
int perm[4];
int delta[4][2] = {
	{0, -1},
	{-1, 0},
	{0, 1},
	{1, 0}
};
queue<int> q;
//구슬을 쏘는 방법을 만들어주는 함수
void permutation(int depth);
//블록을 정리해주는 함수
void arrange();
//블록을 연쇄적으로 제거하는 함수
void block(int x, int y);
//구슬을 특정 열로 쏘는 함수
void drop(int col);
//남은 블럭들을 세어주는 함수
int count_block();
//배열을 복사해주는 함수
void copy(int from[][12], int to[][12]);


void permutation(int depth) {
	if (depth == N) {
		copy(backup, map);
		for (int i = 0; i < N; i++) {
			drop(perm[i]);
			arrange();
		}
		
		int blocks = count_block();
		if (result_min > blocks) {
			result_min = blocks;
		}
		return;
	}
	for (int i = 0; i < W; i++) {
		perm[depth] = i;
		permutation(depth + 1);
	}
}


void arrange() {
	for (int i = 0; i < W; i++) {
		while (!q.empty())q.pop();
		for (int j = H - 1; j >= 0; j--) {
			if (map[j][i] != 0) {
				q.push(map[j][i]);
				map[j][i] = 0;
			}
		}
		for (int j = H - 1; j >= 0; j--) {
			if (q.empty())break;
			map[j][i] = q.front(); q.pop();
		}
	}
}


void block(int x, int y) {
	int tmpx, tmpy;
	int length = map[x][y];
	map[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		tmpx = x; tmpy = y;
		for (int j = 1; j < length; j++) {
			tmpx += delta[i][0]; tmpy += delta[i][1];
			// in boundary
			if (tmpx >= 0 && tmpx < H && tmpy >= 0 && tmpy < W) {
				if (map[tmpx][tmpy] > 1) {
					block(tmpx, tmpy);
				}
			}
			else {
				break;
			}
			map[tmpx][tmpy] = 0;
		}
	}
}

int count_block() {
	int blocks = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (map[i][j] != 0) {
				blocks++;
			}
		}
	}
	return blocks;
}

void drop(int col) {
	for (int i = 0; i < H; i++) {
		if (map[i][col] != 0) {
			block(i, col);
			break;
		}
	}
}

void copy(int from[][12], int to[][12]) {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			to[i][j] = from[i][j];
		}
	}
}


int main() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		result_min = 987654321;
		cin >> N >> W >> H;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> map[i][j];
			}
		}
		copy(map, backup);
		permutation(0);
		cout << '#' << t << ' ' << result_min << '\n';
	}
}