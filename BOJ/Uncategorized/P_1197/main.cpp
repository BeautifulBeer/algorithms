#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

struct edge {
	int to, weight;
};

int main() {
	int V, E, from, to, weight, vertex, result = 0, start;
	auto compare = [](edge e1, edge e2) {
		return e1.weight > e2.weight;
	};
	priority_queue<edge, vector<edge>, decltype(compare)> pq(compare);
	queue<edge> bfs;
	vector<edge>* edges;
	bool* visited;
	cin >> V >> E;
	edges = new vector<edge>[V+1];
	visited = new bool[V + 1]{false};
	for (int i = 0; i < E; i++) {
		cin >> from >> to >> weight;
		edges[from].push_back({to, weight});
		edges[to].push_back({from, weight });
	}
	edge tmp;
	for (int i = 1; i <= V; i++) {
		if (edges[i].size() != 0) {
			start = i;
			break;
		}
	}
	pq.push({start, 0});
	while (!pq.empty()) {
		tmp = pq.top(); pq.pop();
		if (visited[tmp.to])continue;
		visited[tmp.to] = true;
		result += tmp.weight;
		for (int i = 0; i < edges[tmp.to].size(); i++) {
			//not visit
			if (!visited[edges[tmp.to][i].to]) {
				pq.push({ edges[tmp.to][i].to, edges[tmp.to][i].weight });
			}
		}
	}
	cout << result << endl;
	return 0;
}


