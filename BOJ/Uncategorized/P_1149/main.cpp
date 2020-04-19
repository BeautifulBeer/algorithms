#include <iostream>
#include <algorithm>

using namespace std;
int N, red, green, blue;
// rgb��
int** rgbs;
// N��° ���� red, green, blue�� ĥ���������� �ּҰ��� �����ϴ� DP�迭
long** cache;


int main() {
	cin >> N;
	rgbs = new int*[N];
	cache = new long*[N];
	for (int i = 0; i < N; i++) {
		rgbs[i] = new int[3];
		cache[i] = new long[3];
		cin >> red >> green >> blue;
		rgbs[i][0] = red;
		rgbs[i][1] = green;
		rgbs[i][2] = blue;
		cache[i][0] = cache[i][1] = cache[i][2] = 0;
	}
	cache[0][0] = rgbs[0][0];
	cache[0][1] = rgbs[0][1];
	cache[0][2] = rgbs[0][2];
	for (int i = 1; i < N; i++) {
		//i��° red�� ĥ�Ҷ�, i-1��° blue�� ĥ���� ���� �ּڰ��� i-1��° green�� ĥ���� ���� �ּڰ��� ����Ͽ� ���
		cache[i][0] = min(rgbs[i][0] + cache[i - 1][1], rgbs[i][0] + cache[i - 1][2]);
		cache[i][1] = min(rgbs[i][1] + cache[i - 1][0], rgbs[i][1] + cache[i - 1][2]);
		cache[i][2] = min(rgbs[i][2] + cache[i - 1][0], rgbs[i][2] + cache[i - 1][1]);
	}
	long result = 987654321L;
	for (int i = 0; i < 3; i++) {
		result = min(result, cache[N - 1][i]);
	}
	cout << result << '\n';
}