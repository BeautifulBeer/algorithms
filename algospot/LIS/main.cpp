#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>

#pragma warning(disable: 4996)
using namespace std;

int cache[501][501];
vector<int> nums;

int mmax(int a, int b) {
	return (a > b) ? a : b;
}

int LIS(int pos, int base) {
	if (pos == nums.size())return 0;
	int& ret = cache[pos][base];
	if (ret != -1)return ret;
	if (nums[pos] > nums[base]) {
		return ret = mmax(LIS(pos + 1, base), LIS(pos + 1, pos) + 1);
	}
	return ret = LIS(pos + 1, base);
}

int main() {	
	int C, N, tmp, result;
	cin >> C;
	for (int c = 1; c <= C; c++) {
		cin >> N;
		nums.clear();
		nums.push_back(0);
		for (int i = 1; i <= N; i++) {
			cin >> tmp;
			nums.push_back(tmp);
			for (int j = 0; j <= N; j++) {
				cache[i][j] = -1;
			}
		}
		result = LIS(1, 0);
		for (int i = 2; i <= N; i++) {
			result = mmax(result, cache[i][0]);
		}
		cout << result << '\n';
	}
}