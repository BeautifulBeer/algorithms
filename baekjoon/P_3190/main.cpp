#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

struct pos {
	int x, y;
};

// direction,  0 = left , 1 = up , 2 = right , 3 = down
// x : worm , # : wall, . : empty space , o : apple
int main() {
	int N, K, L, direction, time, ax, ay, tmp_idx;
	char dirchar;
	int** map;
	int* timearr;
	char* dirarr;
	int direct[4][2] = { {0, -1},{-1, 0},{0, 1},{1, 0} };
	cin >> N >> K;
	map = new int*[N + 2];
	for (int i = 0; i < N + 2; i++) {
		map[i] = new int[N + 2];
	}
	for (int i = 0; i < N + 2; i++) {
		map[0][i] = '#';
		map[N + 1][i] = '#';
		map[i][0] = '#';
		map[i][N + 1] = '#';
	}
	for (int i = 0; i < K; i++) {
		cin >> ax >> ay;
		map[ax][ay] = 'o';
	}
	cin >> L;
	timearr = new int[L];
	dirarr = new char[L];
	for (int i = 0; i < L; i++) {
		cin >> time >> dirchar;
		timearr[i] = time;
		dirarr[i] = dirchar;
	}
	// timer
	time = 0;
	// index for timearr, dirarr
	tmp_idx = 0;
	// init direction
	direction = 2;
	// start position
	pos head = { 1,1 }, tail;
	// worm body coor
	queue<pos> qe;
	qe.push(head);
	map[head.x][head.y] = 'x';
	while (true) {
		head.x += direct[direction][0];
		head.y += direct[direction][1];
		time++;
		if (map[head.x][head.y] == '#' || map[head.x][head.y] == 'x') {
			break;
		}
		qe.push(head);
		if (map[head.x][head.y] != 'o') {
			tail = qe.front(); qe.pop();
			map[tail.x][tail.y] = '.';
		}
		map[head.x][head.y] = 'x';
		if (tmp_idx < L && time == timearr[tmp_idx]) {
			switch (dirarr[tmp_idx]) {
			case 'L':
				// if current direction is left, change to down
				if (direction == 0) {
					direction = 3;
				}
				// if current direction is up, change to left
				else if (direction == 1) {
					direction = 0;
				}
				// if current direction is right, change to up
				else if (direction == 2) {
					direction = 1;
				}
				// if current direction is down, change to right
				else if (direction == 3) {
					direction = 2;
				}
				break;
			case 'D':
				// if current direction is left, change to up
				if (direction == 0) {
					direction = 1;
				}
				// if current direction is up, change to right
				else if (direction == 1) {
					direction = 2;
				}
				// if current direction is right, change to down
				else if (direction == 2) {
					direction = 3;
				}
				// if current direction is down, change to left
				else if (direction == 3) {
					direction = 0;
				}
				break;
			}
			tmp_idx++;
		}
	}
	cout << time << endl;
}