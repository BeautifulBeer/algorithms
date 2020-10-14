/*
	Author : Kwanwoong Yoon
	Date : 2020. 10. 14
*/

#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

bool visited[100];

void DFS(vector<vector<int>>& adj, int start) {
	stack<int> st; int tmp;
	st.push(start);
	for (int i = 0; i < adj.size(); i++) {
		visited[i] = false;
	}
	while (!st.empty()) {
		tmp = st.top(); st.pop();
		if (visited[tmp])continue;
		visited[tmp] = true;
		cout << tmp << ' ';
		for (int i = 0; i < adj[tmp].size(); i++) {
			if (!visited[adj[tmp][i]]) {
				st.push(adj[tmp][i]);
			}
		}
	}
	cout << '\n';
}

void BFS(vector<vector<int>>& adj, int start) {
	queue<int> q; int tmp;
	q.push(start);
	for (int i = 0; i < adj.size(); i++) {
		visited[i] = false;
	}
	while (!q.empty()) {
		tmp = q.front(); q.pop();
		if (visited[tmp])continue;
		visited[tmp] = true;
		cout << tmp << ' ';
		for (int i = 0; i < adj[tmp].size(); i++) {
			if (!visited[adj[tmp][i]]) {
				q.push(adj[tmp][i]);
			}
		}
	}
	cout << '\n';
}

int main() {
	vector<vector<int>> graph({ {1, 2, 3}, {0}, {0, 5}, {0, 4}, {3, 5}, {2, 4} });
	DFS(graph, 0);
	cout << "----------------------" << '\n';
	BFS(graph, 0);
}