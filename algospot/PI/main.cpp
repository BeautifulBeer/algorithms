#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>

#pragma warning(disable: 4996)
using namespace std;

int MAX_INT = 987654321;
int C, dp[10001];
string str;

int getlevel(int start, int end) {
	char tmp1, tmp2;
	int ch;
	bool flag = true;
	ch = str[start + 1] - str[start];
	// 단조증가 check
	if (ch > 0) {
		for (int i = start + 2; i <= end; i++) {
			if (ch != (int)(str[i] - str[i - 1])) {
				flag = false;
				break;
			}
		}
		if (flag) {
			if (ch == 1) {
				return 2;
			}
			// 등차수열
			else {
				return 5;
			}
		}
	}
	// 같은 거 check
	else if (ch == 0) {
		for (int i = start + 2; i <= end; i++) {
			if (str[start] != str[i]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			return 1;
		}
	}
	// 단조감소 check
	else {
		for (int i = start + 2; i <= end; i++) {
			if (ch != (int)(str[i] - str[i - 1])) {
				flag = false;
				break;
			}
		}
		if (flag) {
			if (ch == -1) {
				return 2;
			}
			// 등차수열
			else {
				return 5;
			}
		}
	}
	// 번갈아가면서 나타날때
	flag = true;
	tmp1 = str[start];
	tmp2 = str[start + 1];
	for (int i = start + 2; i <= end; i++) {
		if (i % 2 == start % 2) {
			if (str[i] != tmp1) {
				flag = false;
				break;
			}
		}
		else {
			if (str[i] != tmp2) {
				flag = false;
				break;
			}
		}
	}
	if (flag) {
		return 4;
	}
	return 10;
}

int mmin(int a, int b) {
	return (a > b) ? b : a;
}

int memorize(int begin) {
	if (begin == str.size())return 0;
	int& ret = dp[begin];
	if (ret != -1)return ret;
	ret = MAX_INT;
	for (int L = 3; L <= 5; L++) {
		if (begin + L <= str.size()) {
			ret = min(ret, memorize(begin + L) + getlevel(begin, begin + L - 1));
		}
	}
	return ret;
}

int main() {	
	cin >> C;
	for (int c = 0; c < C; c++) {
		cin >> str;
		for (int i = 0; i < str.size(); i++) {
			dp[i] = -1;
		}
		cout << memorize(0) << '\n';

	}
}