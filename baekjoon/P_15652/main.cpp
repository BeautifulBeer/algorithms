#include <iostream>

using namespace std;

int N, M;
int* perm;


void permutation(int index, int length) {
	if (length == M) {
		for (int i = 0; i < M; i++) {
			cout << perm[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = index; i <= N; i++) {
		perm[length] = i;
		permutation(i, length + 1);
	}
}

int main() {
	cin >> N >> M;
	perm = new int[M];
	permutation(1, 0);
}