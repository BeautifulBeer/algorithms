#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct tomato {
	int x, y, day;
};

struct cmp {
	bool operator() (tomato t1, tomato t2) {
		return (t1.day == t2.day) ? (t1.x > t2.x) : (t1.day > t2.day);
	}
};
tomato tom;
int M, N, tmp, tx, ty, max_day;
int map[1000+2][1000+2];
int delta[4][2] = {
	{0, -1},
	{-1, 0},
	{0, 1},
	{1, 0}
};
bool is_all_matured = true;
bool visited[1000+2][1000+2];
priority_queue<tomato, vector<tomato>, cmp> pq;

int main() {
	max_day = 0;
	cin >> M >> N;
	//init done
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> tmp;
			map[i][j] = tmp;
			if (map[i][j] == 0) {
				is_all_matured = false;
			}
			if (map[i][j] == 1) {
				pq.push(tomato{ i, j, 0 });
			}
			visited[i][j] = false;
			map[0][j] = map[N + 1][j] = -1;
		}
		map[i][0] = map[i][M+1] = -1;
	}
	map[0][0] = map[0][M + 1] = map[N + 1][0] = map[N + 1][M + 1] = -1;

	//for (int i = 0; i <= N+1; i++) {
	//	for (int j = 0; j <= M+1; j++) {
	//		cout << map[i][j] << " ";
	//	}
	//	cout << "\n";
	//}
	if (!is_all_matured) {
		while (!pq.empty()) {
			tom = pq.top(); pq.pop();
			/*cout << "tom : " << tom.x << " " << tom.y << " " << tom.day << "\n";*/
			if (visited[tom.x][tom.y])continue;
			visited[tom.x][tom.y] = true;
			map[tom.x][tom.y] = (tom.day == 0)?1:tom.day;
			tom.day++;
			for (int i = 0; i < 4; i++) {
				tx = tom.x + delta[i][0];
				ty = tom.y + delta[i][1];
				if (map[tx][ty] != -1 && !visited[tx][ty]) {
					pq.push(tomato{ tx, ty, tom.day });
				}
			}
		}

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (max_day < map[i][j]) {
					max_day = map[i][j];
				}
				else if (map[i][j] == 0) {
					max_day = -1;
					goto break_loop;
				}
			}
		}	
	}
	break_loop:

	//for (int i = 0; i <= N + 1; i++) {
	//	for (int j = 0; j <= M + 1; j++) {
	//		cout << map[i][j] << " ";
	//	}
	//	cout << "\n";
	//}

	cout << max_day << endl;
} 