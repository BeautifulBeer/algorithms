#include <cstdio>
#pragma warning(disable: 4996)
using namespace std;

int T, N;
long long int length[101];

int main() {
	scanf("%d", &T);
	length[1] = 1; length[2] = 1; length[3] = 1;
	length[4] = 2; length[5] = 2; length[6] = 3;
	length[7] = 4; length[8] = 5; length[9] = 7; length[10] = 9;
	for (int i = 11; i <= 100; i++) {
		length[i] = length[i - 1] + length[i - 5];
	}
	for (int t = 1; t <= T; t++) {
		scanf("%d", &N);
		printf("%lld\n", length[N]);
	}
}