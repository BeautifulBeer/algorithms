#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, tmp;
bool* used;
vector<int> nums;
int* perm;

void permutation(int length) {
	if (length == M) {
		for (int i = 0; i < M; i++) {
			cout << perm[i] << ' ';
		}
		cout << '\n';
	}
	for (int i = 0; i < N; i++) {
		if (!used[i]) {
			used[i] = true;
			perm[length] = nums[i];
			permutation(length + 1);
			used[i] = false;
		}

	}
}

int main() {
	cin >> N >> M;
	perm = new int[M];
	used = new bool[N];
	for (int i = 0; i < N; i++) {
		used[i] = false;
		cin >> tmp;
		nums.push_back(tmp);
	}
	sort(nums.begin(), nums.end());
	permutation(0);
}