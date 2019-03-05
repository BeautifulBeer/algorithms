#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int max_length, max_room;
int map[1000+2][1000+2];
int dfs_cache[1000+2][1000+2];
int direct[4][2] = { {0, -1},{-1, 0},{0, 1},{1, 0} };

void dfs(int x, int y) {
	int length = 0, tmp_x, tmp_y;
	for (int i = 0; i < 4; i++) {
		// if matched condition ( a+1 = b )
		tmp_x = x + direct[i][0];
		tmp_y = y + direct[i][1];
		if (map[tmp_x][tmp_y] == map[x][y] + 1) {
			// if didnt search
			if (dfs_cache[tmp_x][tmp_y] == 0) {
				dfs(tmp_x, tmp_y);
			}
			length = (length > dfs_cache[tmp_x][tmp_y]) ? length : dfs_cache[tmp_x][tmp_y];
		}
	}
	length++;
	/*cout << length << " " << x << " " << y << endl;*/
	dfs_cache[x][y] = length;
}

int main() {
	int T, N, tmp_x, tmp_y;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		max_length = 0; max_room = 0;
		cin >> N;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cin >> tmp_x;
				map[i][j] = tmp_x;
				dfs_cache[i][j] = 0;
			}
		}
		//init boundary
		for (int i = 1; i <= N; i++) {
			map[N+1][i] = 0;
			map[i][N+1] = 0;
		}
		
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (dfs_cache[i][j] == 0) {
					dfs(i, j);
					if (max_length < dfs_cache[i][j]) {
						max_length = dfs_cache[i][j];
						max_room = map[i][j];
					}
					else if (max_length == dfs_cache[i][j]) {
						if (max_room > map[i][j]) {
							max_room = map[i][j];
						}
					}
				}
			}
		}
		//for (int i = 1; i <= N; i++) {
		//	for (int j = 1; j <= N; j++) {
		//		cout << dfs_cache[i][j] << " ";
		//	}
		//	cout << "\n";
		//}
		cout << "#" << t << " " << max_room << " " << max_length << "\n";
	}
	return 0;
}