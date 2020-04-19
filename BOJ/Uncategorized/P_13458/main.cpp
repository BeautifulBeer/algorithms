#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> convert(int num) {
	vector<int> a;
	while (num != 0) {
		a.emplace_back(num % 10);
		num = num / 10;
	}
	return a;
}

string number_string(vector<int> num) {
	string result = "";
	reverse(num.begin(), num.end());
	for (auto digit : num) {
		result += digit + '0';
	}
	return result;
}


vector<int> big_int_add(vector<int>& a, vector<int>& b) {
	vector<int> c;
	int aIdx = 0, bIdx = 0, tmp = 0, up = 0, quot = 0;
	while (aIdx < a.size() && bIdx < b.size()) {
		up = a[aIdx++] + b[bIdx++] + tmp;
		quot = up % 10;
		c.emplace_back(quot);
		tmp = up / 10;
	}
	while (aIdx < a.size()) {
		up = a[aIdx++] + tmp;
		c.emplace_back(up % 10);
		tmp = up / 10;
	}
	while (bIdx < b.size()) {
		up = b[bIdx++] + tmp;
		c.emplace_back(up % 10);
		tmp = up / 10;
	}
	if (tmp != 0) {
		c.emplace_back(tmp);
	}
	return c;
}

int main() {
	int N, B, C, tmp, directors = 0;
	vector<int> total, a;
	int* test;
	cin >> N;
	test = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		test[i] = tmp;
	}
	cin >> B >> C;
	for (int i = 0; i < N; i++) {
		directors = 0;
		if (test[i] > B) {
			test[i] -= B;
			directors++;
			directors += test[i] / C;
			if (test[i] % C != 0) {
				directors++;
			}
		}
		else {
			directors++;
		}
		a = convert(directors);
		total = big_int_add(total, a);
	}
	cout << number_string(total).c_str() << endl;
	return 0;
}