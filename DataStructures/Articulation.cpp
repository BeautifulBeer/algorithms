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
int dfsn[100];
int lows[100];
int number = 1;

inline int min(int a, int b) {
	if (a > b) {
		return b;
	}
	return a;
}

void articulation(vector<vector<int>>& adj, int parent, int child) {
	dfsn[child] = lows[child] = number++;
	visited[child] = true;
	for (int i = 0; i < adj[child].size(); i++) {
		if (!visited[adj[child][i]]) {
			articulation(adj, child, adj[child][i]);
			if (lows[child] <= lows[adj[child][i]]) {
				cout << "CUT : " << child << '\n';
			}
			lows[child] = min(lows[child], lows[adj[child][i]]);
		}
		else {
			if (adj[child][i] != parent) {
				lows[child] = min(lows[child], lows[adj[child][i]]);
			}
		}
	}
}


int main() {
	vector<vector<int>> graph({
		{1},
		{0, 2, 3},
		{1, 4},
		{1, 4, 5},
		{2, 3},
		{3, 7, 6},
		{5, 7},
		{5, 6, 8, 9},
		{7},
		{7}
		});
	for (int i = 0; i < graph.size(); i++) {
		visited[i] = false;
	}
	articulation(graph, -1, 0);
	for (int i = 0; i < graph.size(); i++) {
		cout << dfsn[i] << ' ';
	}
	cout << '\n';
	for (int i = 0; i < graph.size(); i++) {
		cout << lows[i] << ' ';
	}
	cout << '\n';
}