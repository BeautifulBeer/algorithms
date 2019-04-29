#include <cstdio>
#include <string>
#pragma warning(disable:4996)

using namespace std;

bool reverse_flag, error;
int T, front, back, N, idx;
char ch;
char op_buf[100001];
char buf[4];
int num_buf[100001];

bool empty() {
	return (front > back);
}

int main() {
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		reverse_flag = error = false;
		scanf(" %s", op_buf);
		scanf(" %d", &N);
		int i = 0; idx = 0;
		while ((ch = getchar()) != ']') {
			if (ch >= '0' && ch <= '9') {
				buf[idx++] = ch;
			}
			else if (ch == ',') {
				buf[idx++] = '\0';
				if (idx > 1) {
					num_buf[i++]= atoi(buf);
				}
				idx = 0;
			}
		}
		buf[idx++] = '\0';
		if (idx > 1) {
			num_buf[i++] = atoi(buf);
		}
		idx = -1; front = 0; back = N - 1;
		while (op_buf[++idx] != '\0') {
			if (op_buf[idx] == 'R') {
				reverse_flag = (reverse_flag)?false:true;
			}
			else {
				if (!empty()) {
					if (reverse_flag) {
						back--;
					}
					else {
						front++;
					}
				}
				else {
					error = true;
					break;
				}
			}
		}
		if (!error) {
			printf("[");
			if (!empty()) {
				if (reverse_flag) {
					for (i = back; i > front; i--) {
						printf("%d,", num_buf[i]);
					}
					printf("%d", num_buf[front]);
				}
				else {
					for (i = front; i < back; i++) {
						printf("%d,", num_buf[i]);
					}
					printf("%d", num_buf[back]);
				}
			}
			printf("]\n");
		}
		else {
			printf("error\n");
		}
	}
}