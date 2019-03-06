#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct edge {
	int to, weight;

};

struct cmp {
	bool operator ()(edge e1, edge e2) {
		return (e1.weight == e2.weight) ? (e1.to > e2.to) : (e1.weight > e2.weight);
	}
};

int T, N, K, W, tmp, tmp_x, tmp_y;
int buildingTime[1000 + 1], preorder[1000 + 1];
vector<int> edges[1000 + 1];
priority_queue<edge, vector<edge>, cmp> pq;

int main() {
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N >> K;
		// init
		while (!pq.empty())pq.pop();
		for (int i = 1; i <= N; i++) {
			edges[i].clear();
			preorder[i] = 0;
			cin >> tmp;
			buildingTime[i] = tmp;
		}
		for (int i = 1; i <= K; i++) {
			cin >> tmp_x >> tmp_y;
			edges[tmp_x].emplace_back(tmp_y);
			preorder[tmp_y]++;
		}
		cin >> W;
		for (int i = 1; i <= N; i++) {
			if (preorder[i] == 0) {
				pq.push(edge{i,0});
				preorder[i] = 1;
			}
		}
		edge tmp;
		while (!pq.empty()) {
			tmp = pq.top(); pq.pop();
			/*cout << "tmp : " << tmp.to << " " << tmp.weight << "\n";*/
			if (--preorder[tmp.to] == 0) {
				// pop
				if (tmp.to == W) {
					cout << tmp.weight + buildingTime[tmp.to] << "\n";
					break;
				}
				for (int i = 0; i < edges[tmp.to].size(); i++) {
					pq.push(edge{edges[tmp.to][i], tmp.weight + buildingTime[tmp.to]});
				}
			}
		}
	}
	return 0;
} 