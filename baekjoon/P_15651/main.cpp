#include <iostream>

using namespace std;

int N, M;
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
		perm[length] = i;
		permutation(length + 1);
	}
}

int main() {
	cin >> N >> M;
	perm = new int[M];
	permutation(0);
}