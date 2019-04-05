#include <iostream>
#include <cmath>

using namespace std;

int T, length_a, length_b, tmp;
char buf_a[40 + 1];
char buf_b[40 + 1];
char tmp_a, tmp_b;

inline int string_length(char* str) {
	int idx = 0;
	if (str == nullptr) {
		return 0;
	}
	while (str[idx] != '\0') {
		idx++;
	}
	return idx;
}

inline int check() {
	int a=0, b=0;
	for (int i = 0; i < length_a; i++) {
		a += (buf_a[i]-'0') * pow(2, length_a - 1 - i);
	}
	for (int i = 0; i < length_b; i++) {
		b += (buf_b[i]-'0') * pow(3, length_b - 1 - i);
	}
	if (a == b) {
		return a;
	}
	else {
		return -1;
	}
}

int main() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		length_a = length_b = 0;
		scanf("%s", buf_a);
		scanf("%s", buf_b);
		length_a = string_length(buf_a);
		length_b = string_length(buf_b);
		for (int i = 0; i < length_a; i++) {
			tmp_a = buf_a[i];
			for (int j = 0; j < 2; j++) {
				buf_a[i] = j+'0';
				for (int k = 0; k < length_b; k++) {
					tmp_b = buf_b[k];
					for (int l = 0; l < 3; l++) {
						buf_b[k] = l+'0';
						tmp = check();
						if (tmp != -1) {
							goto outer;
						}
					}
					buf_b[k] = tmp_b;
				}
			}
			buf_a[i] = tmp_a;
		}
		outer:
		cout << '#' << t << ' ' << tmp << '\n';
	}
}