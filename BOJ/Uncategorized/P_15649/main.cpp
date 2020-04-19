#include <iostream>

using namespace std;

int N, M;
bool used[9];
int* perm;

void permutation(int length) {
	if (length == M) {
		for (int i = 0; i < M; i++) {
			cout << perm[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (!used[i]) {
			used[i] = true;
			perm[length] = i;
			permutation(length + 1);
			used[i] = false;
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < 9; i++) {
		used[i] = false;
	}
	perm = new int[M];
	permutation(0);
}