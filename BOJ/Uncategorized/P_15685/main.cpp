#include <iostream>
#include <vector>

using namespace std;

struct dot {
	int x, y;
};

dot tmp_dot;
int N, x, y, d, g, standard;
bool map[100+1][100+1];
// 1���� �巡�� Ŀ�� ����
vector<dot> dots;
int delta[4][2] = {
	{0, 1},
	{-1, 0},
	{0, -1},
	{1, 0}
};


// a�� �������� �� b�� 90�� ȸ��
dot rotation(dot a, dot b) {
	dot result;
	result.x = a.x + a.y - b.y;
	result.y = b.x + a.y - a.x;
	return result;
}

// 4���� ��� �巡�� Ŀ�꿡 ���� ���簢�� ���� ��ȯ
int count_square() {
	int result = 0;
	for(int i = 0; i < 100; i++){
		for (int j = 0; j < 100; j++) {
			if (map[i][j] && map[i + 1][j] && map[i][j + 1] && map[i + 1][j + 1]) {
				result++;
			}
		}
	}
	return result;
}


int main(){
	cin >> N;
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			map[i][j] = false;
		}
	}
	for (int i = 0; i < N; i++) {
		cin >> x >> y >> d >> g;
		dots.clear();
		dots.push_back(dot({ x,y }));
		// map�� y��ǥ�� �࿡ �ش��ϹǷ� [y][x] �� �־��ش�
		map[y][x] = true;
		dots.push_back(dot({ x + delta[d][1],y + delta[d][0] }));
		map[y + delta[d][0]][x + delta[d][1]] = true;
		for (int j = 0; j < g; j++) {
			// ������ �Ǵ� ��
			standard = dots.size() - 1;
			// ���� ������ �� 90�� ȸ����Ŵ
			for (int i = standard - 1; i >= 0; i--) {
				tmp_dot = rotation(dots[standard], dots[i]);
				map[tmp_dot.y][tmp_dot.x] = true;
				dots.push_back(tmp_dot);
			}
		}
	}

	int result = count_square();
	cout << result << '\n';
}