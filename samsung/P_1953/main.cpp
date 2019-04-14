#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

struct rubbery {
	int x, y, time;
};

int result, T, N, M, L, R, C, length, tmpx, tmpy;
int map[50][50];
bool visited[50][50];
rubbery start;
queue<rubbery> mqueue;
int delta[4][2] = {
	{0, -1},
	{-1, 0},
	{0, 1},
	{1, 0}
};

int pipe_move[7 + 1][4 + 1] = {
	{0, 0, 0, 0, 0},
	{4, 0, 1, 2, 3},
	{2, 1, 3, 0, 0},
	{2, 0, 2, 0, 0},
	{2, 1, 2, 0, 0},
	{2, 3, 2, 0, 0},
	{2, 0, 3, 0, 0},
	{2, 0, 1, 0, 0}
};

bool connected(int pos, int next) {
	if (pos == 1) {
		if (next == 1 || next == 2 || next == 5 || next == 6)return true;
	}
	else if (pos == 3) {
		if (next == 1 || next == 2 || next == 4 || next == 7)return true;
	}else if (pos == 0) {
		if (next == 1 || next == 3 || next == 4 || next == 5)return true;
	}
	else if (pos == 2) {
		if (next == 1 || next == 3 || next == 6 || next == 7)return true;
	}
	return false;
}

void bfs() {
	while (!mqueue.empty())mqueue.pop();
	mqueue.push(start);
	visited[start.x][start.y] = true;
	result++;
	rubbery tmp;
	while (!mqueue.empty()) {
		tmp = mqueue.front(); mqueue.pop();
		if (tmp.time >= L)break;
		length = pipe_move[map[tmp.x][tmp.y]][0];
		for (int i = 1; i <= length; i++) {
			tmpx = tmp.x + delta[pipe_move[map[tmp.x][tmp.y]][i]][0];
			tmpy = tmp.y + delta[pipe_move[map[tmp.x][tmp.y]][i]][1];
			if (tmpx < 0 || tmpx >= N || tmpy < 0 || tmpy >= M) {
				continue;
			}
			if (!connected(pipe_move[map[tmp.x][tmp.y]][i], map[tmpx][tmpy]))continue;
			if (!visited[tmpx][tmpy] && map[tmpx][tmpy] != 0) {
				visited[tmpx][tmpy] = true;
				result++;
				mqueue.push(rubbery({tmpx, tmpy, tmp.time+1}));
			}
		}
	}
}

int main() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> M >> R >> C >> L;
		result = 0;
		start = rubbery({R, C, 1});
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> map[i][j];
				visited[i][j] = false;
			}
		}
		bfs();
		cout << '#' << t << ' ' << result << '\n';
	}
}