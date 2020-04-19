#include <iostream>
#include <algorithm>

using namespace std;

static int tmpx, tmpy;
static int map[19+1][19+1];
static int delta[4][2] = {
	{0, 1},
	{1, 1},
	{1, 0},
	{1, -1}
};

//오목인지 체크하는 함수
static bool checkWin(int x, int y, int direction) {
	bool flag = true;
	tmpx = x; tmpy = y;
	// 5개를 먼저 체크
	for (int i = 0; i < 4; i++) {
		tmpx += delta[direction][0]; tmpy += delta[direction][1];
		if (map[tmpx][tmpy] != map[x][y]) {
			flag = false;
			break;
		}
	}
	// 앞뒤 체크
	tmpx += delta[direction][0]; tmpy += delta[direction][1];
	if (flag && tmpx >= 1 && tmpx <= 19 && tmpy >= 1 && tmpy <= 19) {
		if (map[tmpx][tmpy] == map[x][y]) {
			flag = false;
		}
	}
	// 앞뒤 체크
	tmpx = x - delta[direction][0]; tmpy = y - delta[direction][1];
	if (flag && tmpx >= 1 && tmpx <= 19 && tmpy >= 1 && tmpy <= 19) {
		if (map[tmpx][tmpy] == map[x][y]) {
			flag = false;
		}
	}
	return flag;
}

int main() {
	for (int i = 1; i <= 19; i++) {
		for (int j = 1; j <= 19; j++) {
			cin >> map[i][j];
		}
	}
	int win = 0, win_x, win_y;
	for (int i = 1; i <= 19; i++) {
		for (int j = 1; j <= 19; j++) {
			if (map[i][j] == 0)continue;
			for (int k = 0; k < 4; k++) {
				if (checkWin(i, j, k)) {
					win = map[i][j];
					if (k == 3) {
						win_x = i + 4;
						win_y = j - 4;
					}
					else {
						win_x = i;
						win_y = j;
					}
					goto outer;
				}
			}
		}
	}
	outer:
	if (win == 0) {
		cout << win << '\n';
	}
	else {
		cout << win << '\n' << win_x << ' ' << win_y << '\n';
	}
}