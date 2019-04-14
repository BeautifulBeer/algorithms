#include <cstdio>

int main() {
	int n;
	long long int fibo[90+1];
	scanf("%d", &n);
	for (int i = 0; i <= n; i++) {
		fibo[i] = 0;
	}
	fibo[1] = 1;
	for (int i = 2; i <= n; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}
	printf("%lld\n", fibo[n]);
}