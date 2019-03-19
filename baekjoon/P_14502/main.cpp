#include <iostream>
#include <queue>

using namespace std;

int N, M, result, sections, count_section, count_virus, tmpx, tmpy;
int delta[4][2] = {
	{0, -1},
	{-1, 0},
	{0, 1},
	{1, 0}
};

struct pos {
	int x, y;
};

char tmp;
char map[8 + 2][8 + 2];
pos virus[10];
bool visited[8 + 2][8 + 2];
bool backup[8 + 2][8 + 2];
queue<pos> q;



void copy_arr(bool origin[][10], bool tmp[][10]) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			origin[i][j] = tmp[i][j];
		}
	}
}

void bfs() {
	while (!q.empty())q.pop();
	count_section = 0;
	pos cur;
	for (int i = 0; i < count_virus; i++) {
		q.push(virus[i]);
	}
	while (!q.empty()) {
		cur = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			tmpx = cur.x + delta[i][0];
			tmpy = cur.y + delta[i][1];
			if (map[tmpx][tmpy] == '0' && !visited[tmpx][tmpy]) {
				visited[tmpx][tmpy] = true;
				++count_section;
				pos next = { tmpx, tmpy };
				q.push(next);
			}
		}
	}
	count_section = sections - count_section;
	if (result < count_section) {
		result = count_section;
	}
}


int main() {
	cin >> N >> M;
	sections = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> tmp;
			if (tmp == '0')++sections;
			if (tmp == '2') {
				virus[count_virus++] = {i, j};
			}
			map[i][j] = tmp;
		}
	}
	sections -= 3;
	for (int i = 0; i <= N + 1; i++) {
		map[i][0] = '1';
		map[i][M + 1] = '1';
	}
	for (int i = 0; i <= M + 1; i++) {
		map[0][i] = '1';
		map[N + 1][i] = '1';
	}

	//for (int i = 0; i <= N + 1; i++) {
	//	for (int j = 0; j <= M + 1; j++) {
	//		cout << map[i][j] << ' ';
	//	}
	//	cout << '\n';
	//}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (map[i][j] != '0')continue;
			visited[i][j] = true;
			// second door
			for (int k = i; k <= N; k++) {
				for (int l = (k==i)?j:1; l <= M; l++) {
					if (map[k][l] != '0' || visited[k][l])continue;
					visited[k][l] = true;
					// third door
					for (int o = k; o <= N; o++) {
						for (int p = (o == k) ? l : 1; p <= M; p++) {
							if (map[o][p] != '0' || visited[o][p])continue;
							visited[o][p] = true;
							copy_arr(backup, visited);
							bfs();
							/*cout << i << ' ' << j << ',' << k << ' ' << l << ',' << o << ' ' << p << " / " << count_section << '\n';*/
							copy_arr(visited, backup);
							visited[o][p] = false;
						}
					}
					visited[k][l] = false;
				}
			}
			visited[i][j] = false;
		}
	}
	cout << result << '\n';
}