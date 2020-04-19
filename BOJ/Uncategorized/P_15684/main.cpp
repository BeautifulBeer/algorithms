#include <iostream>

using namespace std;

/*
	이 문제는, 사다리를 놓아야하는 최소 갯수가 3개 이상이거나 갈 수 없으면 -1을 출력한다.
	즉, 3개로도 조건을 충족시키지 못한다면 못가는 경우로 생각해도 된다.
*/

struct ladder {
	bool left, right;
};

int N, M, H, boundary, result, a, b;
// map은 N은 좌우를 체크해야하기 때문에 +2. N과 H는 1부터 시작하기 때문에 +1
ladder map[30 + 1][10 + 2];

// 사다리타기 게임해서 조건에 안맞으면 false 반환
bool play() {
	bool flag = true;
	int tmpx, tmpy;
	for (int i = 1; i <= N; i++) {
		tmpx = 1; tmpy = i;
		while (tmpx <= H) {
			//연결되어 있으면 이동
			if (map[tmpx][tmpy].left) {
				tmpy--;
			}
			else if (map[tmpx][tmpy].right) {
				tmpy++;
			}
			tmpx++;
		}
		if (tmpy != i) {
			flag = false;
			break;
		}
	}
	return flag;
}

// 모든 경우의 사다리를 놓아본다
void brute_force(int x, int y, int depth) {
	// 이미 boundary로 가능한 경우가 있는 것을 확인하면, 더이상 하지 않는다.
	if (result != -1) {
		return;
	}
	// 놓은 사다리 갯수가 boundary면,
	if (depth == boundary) {
		if (play()) {
			result = depth;
		}
		return;
	}
	for (int i = x; i <= H; i++) {
		for (int j = (i == x)?y:1; j < N; j++) {
			if (!map[i][j].left && !map[i][j].right) {
				map[i][j].right = map[i][j + 1].left = true;
				brute_force(i, j+2, depth + 1);
				map[i][j].right = map[i][j + 1].left = false;
			}
		}
	}
}

int main(){
	cin >> N >> M >> H;
	for (int i = 0; i < H+1; i++) {
		for (int j = 0; j < N + 2; j++) {
			map[i][j].left = map[i][j].right = false;
		}
	}
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		map[a][b].right = map[a][b + 1].left = true;
	}
	for (int i = 0; i <= 3; i++) {
		result = -1; boundary = i;
		brute_force(1, 1, 0);
		// 최솟값이므로.
		if (result != -1) {
			break;
		}
	}
	cout << result << '\n';
}