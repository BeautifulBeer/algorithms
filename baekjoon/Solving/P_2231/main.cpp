#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool flag = false;
int N = 0, D = 0;
int* digits;

void power_set(vector<int>& v, int cur_digit, int sum) {
	for (int num : v) {
		cout << num << " ";
	}
	cout << " , " << cur_digit << " , " << sum << endl;
	if (cur_digit < 0 || flag) {
		return;
	}
	if (cur_digit == 0 && N == sum) {
		flag = true;
		return;
	}
	int x = (N - sum) / ((int)pow(10, cur_digit) + 1);
	int max = 0, tmp = 0;
	for (int i = cur_digit-1; i >= 0; i--) {
		max += 9 * pow(10, i);
	}
	for (int i = 0; i <= x; i++) {
		tmp = i * pow(10, cur_digit) + max;
		if (N - sum <= tmp) {
			v.push_back(i);
			power_set(v, cur_digit-1, sum + i * pow(10, cur_digit));
			v.pop_back();
		}
	}
}

int main() {	
	char* ptr = new char[10];
	digits = new int[10];
	vector<int> vec;
	cin >> N;
	snprintf(ptr, 10, "%d", N);
	D = strlen(ptr); // number length
	for (int i = 0; i < D; i++) {
		digits[i] = ptr[i] - '0';
	}
	power_set(vec, D-1, 0);
	for (int num : vec) {
		cout << num << " ";
	}
	cout << endl;
}
