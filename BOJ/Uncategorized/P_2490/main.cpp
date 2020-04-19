#include <cstdio>
#pragma warning(disable: 4996)
using namespace std;

int a, b, c, d, result;

int main() {
	for (int i = 0; i < 3; i++) {
		scanf(" %d %d %d %d", &a, &b, &c, &d);
		result = a + b + c + d;
		if (result == 0) {
			printf("D\n");
		}
		else if(result == 1){
			printf("C\n");
		}
		else if (result == 2) {
			printf("B\n");
		}
		else if (result == 3) {
			printf("A\n");
		}
		else if (result == 4) {
			printf("E\n");
		}
	}
}