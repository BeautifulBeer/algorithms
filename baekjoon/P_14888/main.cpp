#include <iostream>
#include <limits.h>

using namespace std;

int N, result, value, max_value = INT32_MIN, min_value = INT32_MAX, multiply_v, subtract_v, plus_v, divide_v;
int* num;
char tmp;
char* operations;

void permutation(int depth) {
	if (depth == N) {
		value = num[0];
		for (int i = 1; i < N; i++) {
			switch (operations[i]) {
			case '+':
				value = value + num[i];
				break;
			case '-':
				value = value - num[i];
				break;
			case '*':
				value = value * num[i];
				break;
			case '/':
				value = value / num[i];
				break;
			}
		}
		if (value > max_value) {
			max_value = value;
		}
		if (value < min_value) {
			min_value = value;
		}
		return;
	}
	for (int i = depth; i < N; i++) {
		tmp = operations[depth];
		operations[depth] = operations[i];
		operations[i] = tmp;

		permutation(depth + 1);

		tmp = operations[depth];
		operations[depth] = operations[i];
		operations[i] = tmp;
	}
}

int main(){
	cin >> N;
	num = new int[N];
	operations = new char[N];
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	cin >> plus_v >> subtract_v >> multiply_v >> divide_v;
	int tmpIdx = 1;
	while (tmpIdx < N) {
		if (plus_v > 0) {
			operations[tmpIdx] = '+';
			plus_v--;
		}
		else if (subtract_v > 0) {
			operations[tmpIdx] = '-';
			subtract_v--;
		}
		else if (multiply_v > 0) {
			operations[tmpIdx] = '*';
			multiply_v--;
		}
		else if (divide_v > 0) {
			operations[tmpIdx] = '/';
			divide_v--;
		}
		tmpIdx++;
	}
	permutation(1);
	cout << max_value << '\n' << min_value << '\n';
}