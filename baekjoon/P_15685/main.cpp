#include <iostream>
#include <vector>

using namespace std;

struct dot {
	int x, y;
};

dot tmp_dot;
int N, x, y, d, g, standard;
bool map[100+1][100+1];
// 1개의 드래곤 커브 점들
vector<dot> dots;
int delta[4][2] = {
	{0, 1},
	{-1, 0},
	{0, -1},
	{1, 0}
};


// a를 기준으로 점 b를 90도 회전
dot rotation(dot a, dot b) {
	dot result;
	result.x = a.x + a.y - b.y;
	result.y = b.x + a.y - a.x;
	return result;
}

// 4점이 모두 드래곤 커브에 속한 정사각형 개수 반환
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
		// map은 y좌표가 행에 해당하므로 [y][x] 로 넣어준다
		map[y][x] = true;
		dots.push_back(dot({ x + delta[d][1],y + delta[d][0] }));
		map[y + delta[d][0]][x + delta[d][1]] = true;
		for (int j = 0; j < g; j++) {
			// 기준이 되는 점
			standard = dots.size() - 1;
			// 이전 점들을 다 90도 회전시킴
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