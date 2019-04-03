#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

int T, N, X, tmpx, tmpy, result;
bool flag;
bool visited[20][20];
int map[20][20];
int delta[4][2] = {
	{0, -1},
	{-1, 0},
	{0, 1},
	{1, 0}
};

bool checkSlider(int x, int y, int direction) {
	tmpx = x; tmpy = y;
	visited[x][y] = true;
	for (int i = 1; i < X; i++) {
		tmpx += delta[direction][0]; tmpy += delta[direction][1];
		if (tmpx < 0 || tmpx >= N || tmpy < 0 || tmpy >= N) {
			return false;
		}
		if (visited[tmpx][tmpy] || map[tmpx][tmpy] != map[x][y]) {
			return false;
		}
		visited[tmpx][tmpy] = true;
	}
	return true;
}

int main() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		result = 0;
		cin >> N >> X;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				visited[i][j] = false;
			}
		}
		// 가로줄 체크
		for (int i = 0; i < N; i++) {
			flag = true;
			for (int j = 1; j < N; j++) {
				if (map[i][j] - map[i][j - 1] == 1) {
					if (!checkSlider(i, j-1, 0)) {
						flag = false;
						break;
					}
				}
				else if (map[i][j] - map[i][j - 1] == -1) {
					if (!checkSlider(i, j, 2)) {
						flag = false;
						break;
					}
				}
				else if(map[i][j] != map[i][j-1]){ // 2이상 차이나면
					flag = false;
					break;
				}
			}
			if (flag) {
				result++;
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				visited[i][j] = false;
			}
		}
		// 세로줄 체크
		for (int i = 0; i < N; i++) {
			flag = true;
			for (int j = 1; j < N; j++) {
				if (map[j][i] - map[j-1][i] == 1) {
					if (!checkSlider(j-1, i, 1)) {
						flag = false;
						break;
					}
				}
				else if (map[j][i] - map[j-1][i] == -1) {
					if (!checkSlider(j, i, 3)) {
						flag = false;
						break;
					}
				}
				else if (map[j][i] != map[j-1][i]) { // 2이상 차이나면
					flag = false;
					break;
				}
			}
			if (flag) {
				result++;
			}
		}
		cout << '#' << t << ' ' << result << '\n';
	}
}