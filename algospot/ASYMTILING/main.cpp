#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>

#pragma warning(disable: 4996)
using namespace std;

int C, n;
long long modular = 1000000007 , answer;
long long tile[101];
long long symtile[101];


int main() {
	tile[1] = 1; tile[2] = 2;
	symtile[1] = 1;	symtile[2] = 2;	symtile[3] = 1; symtile[4] = 3;
	for (int i = 3; i <= 100; i++) {
		tile[i] = (tile[i - 1] + tile[i - 2])% modular;
	}
	for (int i = 5; i <= 100; i++) {
		symtile[i] = (symtile[i - 2] + symtile[i - 4]) % modular;
	}
	cin >> C;
	for (int c = 1; c <= C; c++) {
		cin >> n;
		answer = (tile[n] + modular - symtile[n]) % modular;
		cout << answer << '\n';
	}
}