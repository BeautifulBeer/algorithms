#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int dfs(char** arr, int N, int ridx, int cidx) {
	if (ridx < 0 || ridx >= N || cidx < 0 || cidx >= N || arr[ridx][cidx] != '1') {
		return 0;
	}
	arr[ridx][cidx] = '2';
	return 1 + dfs(arr, N, ridx + 1, cidx) +
		dfs(arr, N, ridx - 1, cidx) +
		dfs(arr, N, ridx, cidx + 1) +
		dfs(arr, N, ridx, cidx - 1);
}

int main() {	
	int N, num, total = 0;
	char tmp = '\0';
	char** arr;
	string str;
	vector<int> number_buildings;
	scanf("%d", &N);
	arr = new char*[N];

	for (int i = 0; i < N; i++) {
		arr[i] = new char[N];
	}
	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int j = 0; j < N; j++) {
			arr[i][j] = str[j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == '1') {
				total++;
				number_buildings.push_back(dfs(arr, N, i, j));
			}
		}
	}

	sort(number_buildings.begin(), number_buildings.end());
	printf("%d\n", total);
	for (int num : number_buildings) {
		printf("%d\n", num);
	}


}
