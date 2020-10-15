/*
	Author : Kwanwoong Yoon
	Date : 2020. 10. 14
*/

#include <limits>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>

#define INF 1000000

using namespace std;

int weight[7][7] = {
  {0,7,INF,INF,3,10,INF},
  {7,0,4,10,2,6,INF},
  {INF,4,0,2,INF,INF,INF},
  {INF,10,2,0,11,9,4},
  {3,2,INF,11,0,INF,5},
  {10,6,INF,9,INF,0,INF},
  {INF,INF,INF,4,5,INF,0}
};

int distances[7];
bool point_set[7];

int find_min() {
	int min_v = INT_MAX;
	int idx = 0;
	for (int i = 0; i < 7; i++) {
		if (!point_set[i] && min_v > distances[i]) {
			min_v = distances[i];
			idx = i;
		}
	}
	return idx;
}

int minimum(int a, int b) {
	if (a > b)return b;
	return a;
}

void dijkstra(int depart) {
	int tmp;
	for (int i = 0; i < 7; i++) {
		distances[i] = weight[depart][i];
		point_set[i] = false;
	}
	point_set[depart] = true;

	for (int i = 0; i < 6; i++) {
		tmp = find_min();
		point_set[tmp] = true;
		for (int j = 0; j < 7; j++) {
			if (!point_set[j]) {
				distances[j] = minimum(distances[j], distances[tmp] + weight[tmp][j]);
			}
		}
	}
}



int main() {
	dijkstra(0);
	for (int i = 0; i < 7; i++) {
		cout << distances[i] << ' ';
	}
	cout << '\n';
}