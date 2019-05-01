#include <cstdio>
#pragma warning(disable: 4996)
using namespace std;
int n;
long long int fibo[46];
int main() {
	scanf("%d", &n);
	fibo[0] = 0;
	fibo[1] = 1;
	for (int i = 2; i <= n; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}
	printf("%lld", fibo[n]);
}