#include <iostream>
#include <queue>
#include <cstdarg>

using namespace std;

int T, n, max_sticker;
//��ƼĿ�� ������ �����ϴ� �迭
int sticker[100000][2];
//ó������ ���� ��ġ���� ��,�Ʒ� ��ƼĿ�� �پ����� �Ⱥپ������� ���¿� ���� �ִ�
int cache[100000][3];

int mmax(int num, ...) {
	int result = 0, tmp;
	va_list vl;
	va_start(vl, num);
	for (int i = 0; i < num; i++) {
		tmp = va_arg(vl, int);
		if (result < tmp) {
			result = tmp;
		}
	}
	va_end(vl);
	return result;
}

int main() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		max_sticker = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> sticker[i][0];
		}
		for (int i = 0; i < n; i++) {
			cin >> sticker[i][1];
			cache[i][0] = cache[i][1] = cache[i][2] = 0;
		}
		cache[0][0] = sticker[0][0];
		cache[0][2] = sticker[0][1];

		for (int i = 1; i < n; i++) {
			cache[i][0] = mmax(2, cache[i - 1][1], cache[i - 1][2]);
			cache[i][0] += sticker[i][0];
			cache[i][1] = mmax(3, cache[i - 1][0], cache[i - 1][1], cache[i - 1][2]);
			cache[i][2] = mmax(2, cache[i - 1][1], cache[i - 1][0]);
			cache[i][2] += sticker[i][1];
		}
		max_sticker = mmax(3, cache[n - 1][0], cache[n - 1][1], cache[n - 1][2]);
		cout << max_sticker << '\n';
	}
}