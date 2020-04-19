#include <iostream>
#include <list>
#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;


int main() {	
	int N, M, a, b, result = 0;
	queue<int> queue;
	bool* visited;
	bool** edges;
	scanf("%d %d", &N, &M);
	edges = new bool*[N + 1]();
	visited = new bool[N + 1]();
	for (int i = 0; i <= N; i++) {
		edges[i] = new bool[N + 1]();
	}
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		edges[a][b] = true;
		edges[b][a] = true;
	}

	for (int i = 1; i <= N; i++) {
		if (visited[i])continue;
		result++;
		while (!queue.empty())queue.pop();
		queue.push(i);
		visited[i] = true;
		while (!queue.empty()) {
			a = queue.front();
			queue.pop();	
			for (int j = 1; j <= N; j++) {
				if (!visited[j] && edges[a][j]) {
					queue.push(j);
					visited[j] = true;
				}
			}
		}
	}
	printf("%d\n", result);
}
