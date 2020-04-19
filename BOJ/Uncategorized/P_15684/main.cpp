#include <iostream>

using namespace std;

/*
	�� ������, ��ٸ��� ���ƾ��ϴ� �ּ� ������ 3�� �̻��̰ų� �� �� ������ -1�� ����Ѵ�.
	��, 3���ε� ������ ������Ű�� ���Ѵٸ� ������ ���� �����ص� �ȴ�.
*/

struct ladder {
	bool left, right;
};

int N, M, H, boundary, result, a, b;
// map�� N�� �¿츦 üũ�ؾ��ϱ� ������ +2. N�� H�� 1���� �����ϱ� ������ +1
ladder map[30 + 1][10 + 2];

// ��ٸ�Ÿ�� �����ؼ� ���ǿ� �ȸ����� false ��ȯ
bool play() {
	bool flag = true;
	int tmpx, tmpy;
	for (int i = 1; i <= N; i++) {
		tmpx = 1; tmpy = i;
		while (tmpx <= H) {
			//����Ǿ� ������ �̵�
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

// ��� ����� ��ٸ��� ���ƺ���
void brute_force(int x, int y, int depth) {
	// �̹� boundary�� ������ ��찡 �ִ� ���� Ȯ���ϸ�, ���̻� ���� �ʴ´�.
	if (result != -1) {
		return;
	}
	// ���� ��ٸ� ������ boundary��,
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
		// �ּڰ��̹Ƿ�.
		if (result != -1) {
			break;
		}
	}
	cout << result << '\n';
}