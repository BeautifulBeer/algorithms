#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <tuple>

using namespace std;


int main() {	
	int M, N, K, area, tmp_x, tmp_y, total_areas = 0;
	int x1, y1, x2, y2;
	int dx[] = {-1, 1, 0, 0};
	int dy[] = {0, 0, 1, -1};
	bool** arr;
	queue<tuple<int, int>> queue;
	vector<int> areas;
	scanf("%d %d %d", &M, &N, &K);
	arr = new bool*[M];
	for (int i = 0; i < M; i++) {
		arr[i] = new bool[N];
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			arr[i][j] = true;
		}
	}

	for (int i = 0; i < K; i++) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		for (int j = x1; j < x2; j++) {
			for (int k = y1; k < y2; k++) {
				arr[M - 1 - k][j] = false;
			}
		}
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			//BFS
			if (arr[i][j]) {
				total_areas++;
				area = 0;
				while (!queue.empty())queue.pop();
				queue.push(make_tuple(i, j));
				while (!queue.empty()) {
					auto point = queue.front();
					queue.pop();
					if (!arr[get<0>(point)][get<1>(point)]) {
						continue;
					}
					area++;
					arr[get<0>(point)][get<1>(point)] = false;
					for (int k = 0; k < 4; k++) {
						tmp_x = get<0>(point) + dx[k];
						tmp_y = get<1>(point) + dy[k];
						if (tmp_x >= 0 && tmp_x < M && tmp_y >= 0 && tmp_y < N && arr[tmp_x][tmp_y]) {
							queue.push(make_pair(tmp_x, tmp_y));
						}
					}
				}
				areas.push_back(area);
			}
		}
	}
	sort(areas.begin(), areas.end());
	printf("%d\n", total_areas);
	for (int num : areas) {
		printf("%d ", num);
	}
	printf("\n");

	
}
