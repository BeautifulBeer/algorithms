#include <cstdio>
#pragma warning(disable: 4996)
using namespace std;

int main() {
	bool flag;
	int n,tmp;
	int count[3];
	scanf("%d", &n);
	for (int i = 0; i < 3; i++) {
		count[i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		tmp = i;
		while (tmp % 2 == 0) {
			count[0]++;
			tmp = tmp / 2;
		}
		while (tmp % 5 == 0) {
			count[1]++;
			tmp = tmp / 5;
		}
	}
	count[2] = (count[0] > count[1]) ? count[1] : count[0];
	printf("%d\n", count[2]);
}