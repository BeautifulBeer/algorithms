#include <iostream>

using namespace std;

/*
	watachable_area : �ʱ� 0 ����
	min_area : ��� ��쿡���� �ּ� �簢����
	ct_cctv : cctv ����
*/
int N, M, ct_cctv = 0, watchable_area = 0, min_area = INT32_MAX;
int map[8+2][8+2];
// ����, ����, ������, �Ʒ��� �������� �̵��ϴ� ��ȭ��
int delta[4][2] = {
	{0, -1},
	{-1, 0},
	{0, 1},
	{1, 0}
};
// �湮üũ�� ���� �迭
bool visited[8+2][8+2];
// �� cctv ������ ���� ����ü
struct cctv {
	int kind, direction, x, y;
};
// cctv �迭
cctv cctvs[8];


// �� cctv ��ġ���� �����¿� ���⿡ ���� ������ �� �ִ� ������ ������ ��ȯ
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

// CCTV�� ���� �� �ִ� ������ ���⿡ ���� ��� ����� �� ����Ž��
void brute_force(int depth) {
	// �� CCTV���� ������ �����ϰ� ��� CCTV�� ���� ������ ������ ���.
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
		// ���� ���� �Ʒ��� ������ ������ ����
		int tmp = watchable_area - ct_area;
		if (min_area > tmp) {
			min_area = tmp;
		}
		return;
	}
	// 5�� CCTV�� ��� ������ȯ�� ���ǹ��ϱ� ������ �ٷ� ���� CCTV�� �Ѿ
	if (cctvs[depth].kind == 5) {
		brute_force(depth + 1);
	}
	// 2�� CCTV�� ��� 2���� ������ȯ�� ���ָ� ������ 2���� �ߺ��Ǵ� ����̹Ƿ�, ����
	else if (cctvs[depth].kind == 2) {
		for (int i = 0; i < 2; i++) {
			cctvs[depth].direction = i;
			brute_force(depth + 1);
		}
	}
	// �������� ���, �����¿� ������ȯ
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