#include <iostream>

using namespace std;

struct pos {
	int x, y;
};

pos robot;
char** map;
bool** clean;
int direction, N, M, tmpx, tmpy, tmp, result;
int delta[4][2] = {
	{-1, 0},
	{0, -1},
	{1, 0},
	{0, 1}
};
bool flag;

int main() {
	cin >> N >> M;
	map = new char*[N];
	clean = new bool*[N];
	cin >> tmpx >> tmpy >> direction;
	if (direction == 1) {
		direction = 3;
	}
	else if (direction == 3) {
		direction = 1;
	}
	robot = pos({tmpx, tmpy});
	for (int i = 0; i < N; i++) {
		map[i] = new char[M];
		clean[i] = new bool[M];
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			clean[i][j] = false;
		}
	}
	result = 0;
	while (true) {
		if (!clean[robot.x][robot.y]) {
			result++;
		}
		clean[robot.x][robot.y] = true;
		flag = true;
		for (int i = 1; i <= 4; i++) {
			tmp = (direction + i) % 4;
			tmpx = robot.x + delta[tmp][0];
			tmpy = robot.y + delta[tmp][1];
			if (!clean[tmpx][tmpy] && map[tmpx][tmpy] == '0') {
				robot.x = tmpx; robot.y = tmpy; direction = tmp;
				flag = false;
				break;
			}
		}
		//check behind condition
		if (flag) {
			tmp = (direction + 2) % 4;
			tmpx = robot.x + delta[tmp][0];
			tmpy = robot.y + delta[tmp][1];
			if (map[tmpx][tmpy] == '1') {
				break;
			}
			else {
				robot.x = tmpx; robot.y = tmpy;
			}
		}
	}
	cout << result << '\n';
}