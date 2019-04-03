#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

string str;
int op, n, m, T, a, b;
int parent[1000000+1];

void makeSet(int a) {
	parent[a] = a;
}

int findSet(int a) {
	if (parent[a] == a) {
		return a;
	}
	int tmp = findSet(parent[a]);
	parent[a] = tmp;
	return tmp;
}

void unionSet(int a, int b) {
	int parentA = findSet(a);
	int parentB = findSet(b);
	if (parentA != parentB) {
		parent[parentB] = parentA;
	}
}


int main() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		str = "";
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			makeSet(i);
		}
		for (int i = 0; i < m; i++) {
			cin >> op >> a >> b;
			if (op == 0) {
				unionSet(a, b);
			}
			else if(op==1){
				if (findSet(a) == findSet(b)) {
					str += "1";
				}
				else {
					str += "0";
				}
			}
		}
		cout << '#' << t << ' ' << str.c_str() << '\n';
	}
}