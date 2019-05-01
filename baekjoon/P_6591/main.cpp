#include <cstdio>
#pragma warning(disable: 4996)
using namespace std;

long long int  result;
int divider, n, k;
int main() {
	while (true) {
		result = divider = 1;
		scanf("%d %d", &n, &k);
		if (n == 0 && k == 0) {
			break;
		}
		if (n - k < k) {
			k = n - k;
		}
		while (k-- > 0) {
			result *= n--;
			result /= divider++;
		}
		printf("%lld\n", result);
	}
}