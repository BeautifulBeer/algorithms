#include <cstdio>
#pragma warning(disable: 4996)
using namespace std;

//피사노의 주기를 이용한 피보나치 수열 나머지 구하기 문제
const int PERIOD = 1500000;
int fibo[PERIOD];

int main() {
	long long int N;
	scanf("%lld", &N);
	N = N % PERIOD;
	fibo[0] = 0;
	fibo[1] = 1;
	for (int i = 2; i < PERIOD; i++) {
		fibo[i] = (fibo[i - 1] + fibo[i - 2])%1000000;
	}
	printf("%d\n", fibo[N]);
}