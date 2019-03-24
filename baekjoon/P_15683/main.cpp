#include <iostream>

using namespace std;

/*
	watachable_area : 초기 0 개수
	min_area : 모든 경우에서의 최소 사각지대
	ct_cctv : cctv 개수
*/
int N, M, ct_cctv = 0, watchable_area = 0, min_area = INT32_MAX;
int map[8+2][8+2];
// 왼쪽, 위쪽, 오른쪽, 아래쪽 방향으로 이동하는 변화값
int delta[4][2] = {
	{0, -1},
	{-1, 0},
	{0, 1},
	{1, 0}
};
// 방문체크를 위한 배열
bool visited[8+2][8+2];
// 각 cctv 정보를 위한 구조체
struct cctv {
	int kind, direction, x, y;
};
// cctv 배열
cctv cctvs[8];


// 현 cctv 위치에서 상하좌우 방향에 대해 감시할 수 있는 영역의 개수를 반환
int watch(int x, int y, int direction) {
	int ct = 0, tmpx = x, tmpy = y;
	do {
		if (!visited[tmpx][tmpy] && map[tmpx][tmpy] == 0) {
			visited[tmpx][tmpy] = true;
			ct++;
		}
		tmpx = tmpx + delta[direction][0];
		tmpy = tmpy + delta[direction][1];
	} while (map[tmpx][tmpy] != 6);
	return ct;
}

// CCTV가 가질 수 있는 각각의 방향에 대한 모든 경우의 수 완전탐색
void brute_force(int depth) {
	// 각 CCTV마다 방향을 조정하고 모든 CCTV의 방향 조정이 끝났을 경우.
	if (depth == ct_cctv) {
		//
		int ct_area = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				visited[i][j] = false;
			}
		}
		for (int i = 0; i < ct_cctv; i++) {
			if (cctvs[i].kind == 1) {
				ct_area += watch(cctvs[i].x, cctvs[i].y, cctvs[i].direction);
			}else if (cctvs[i].kind == 2) {
				ct_area += watch(cctvs[i].x, cctvs[i].y, cctvs[i].direction) +
					watch(cctvs[i].x, cctvs[i].y, (cctvs[i].direction + 2) % 4);
			}else if (cctvs[i].kind == 3) {
				ct_area += watch(cctvs[i].x, cctvs[i].y, cctvs[i].direction) +
					watch(cctvs[i].x, cctvs[i].y, (cctvs[i].direction + 1) % 4);
			}else if (cctvs[i].kind == 4) {
				ct_area += watch(cctvs[i].x, cctvs[i].y, cctvs[i].direction) +
					watch(cctvs[i].x, cctvs[i].y, (cctvs[i].direction + 1) % 4) + 
					watch(cctvs[i].x, cctvs[i].y, (cctvs[i].direction + 2) % 4);
			}else if (cctvs[i].kind == 5) {
				ct_area += watch(cctvs[i].x, cctvs[i].y, cctvs[i].direction) +
					watch(cctvs[i].x, cctvs[i].y, (cctvs[i].direction + 1) % 4) +
					watch(cctvs[i].x, cctvs[i].y, (cctvs[i].direction + 2) % 4) +
					watch(cctvs[i].x, cctvs[i].y, (cctvs[i].direction + 3) % 4);
			}
		}
		// 실제 감시 아래에 놓여진 영역의 개수
		int tmp = watchable_area - ct_area;
		if (min_area > tmp) {
			min_area = tmp;
		}
		return;
	}
	// 5번 CCTV의 경우 방향전환이 무의미하기 때문에 바로 다음 CCTV로 넘어감
	if (cctvs[depth].kind == 5) {
		brute_force(depth + 1);
	}
	// 2번 CCTV의 경우 2번의 방향전환만 해주면 나머지 2번은 중복되는 경우이므로, 제외
	else if (cctvs[depth].kind == 2) {
		for (int i = 0; i < 2; i++) {
			cctvs[depth].direction = i;
			brute_force(depth + 1);
		}
	}
	// 나머지의 경우, 상하좌우 방향전환
	else {
		for (int i = 0; i < 4; i++) {
			cctvs[depth].direction = i;
			brute_force(depth + 1);
		}
	}	
}

int main(){
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) {
				watchable_area++;
			}else if(map[i][j] != 6){
				cctvs[ct_cctv].kind = map[i][j];
				cctvs[ct_cctv].x = i;
				cctvs[ct_cctv].y = j;
				cctvs[ct_cctv].direction = 0;
				ct_cctv++;
			}
		}
	}
	for (int i = 0; i <= N + 1; i++) {
		map[i][0] = 6;
		map[i][M + 1] = 6;
	}
	for (int i = 0; i <= M + 1; i++) {
		map[0][i] = 6;
		map[N + 1][i] = 6;
	}
	brute_force(0);
	cout << min_area << '\n';
}