#include <cstdio>
#pragma warning(disable: 4996)
using namespace std;

int main() {
	int n, k;
	int cache[10000 + 1] = { 0 };
	int value[100 + 1];
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &value[i]);
	}
	cache[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = value[i]; j <= k; j++) {
			cache[j] += cache[j - value[i]];
		}
	}
	printf("%d\n", cache[k]);
}