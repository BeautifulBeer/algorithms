#include <cstdio>
#include <vector>

using namespace std;

int n, C, m, fa, fb, result;
bool matched[10];
vector<int> friends[10];

void brute_force(int depth, int count) {
	if (count == n) {
		result++;
	}
	for (int i = depth; i < n; i++) {
		if (!matched[i]) {
			matched[i] = true;
			for (int j = 0; j < friends[i].size(); j++) {
				if (!matched[friends[i][j]]) {
					matched[friends[i][j]] = true;
					brute_force(i+1, count + 2);
					matched[friends[i][j]] = false;
				}
			}
			matched[i] = false; 
		}
	}
}

int main() {
	scanf("%d", &C);
	for (int c = 1; c <= C; c++) {
		result = 0;
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++) {
			friends[i].clear();
			matched[i] = false;
		}
		for (int i = 0; i < m; i++) {
			scanf("%d %d", &fa, &fb);
			friends[fa].push_back(fb);
		}
		brute_force(0, 0);
		printf("%d\n", result);
	}
	
}