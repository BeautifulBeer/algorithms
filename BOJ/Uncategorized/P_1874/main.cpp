#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int n, tmp, idx, cur;
char result[200002];

class mstack {
private:
	int top_pointer;
	int arr[100001];
public:
	mstack();
	bool empty();
	void push(int a);
	int top();
	void pop();
};

mstack::mstack() {
	top_pointer = 0;
}

bool mstack::empty() {
	return top_pointer == 0;
}

void mstack::push(int a) {
	arr[top_pointer++] = a;
}

int mstack::top() {
	if (empty())return -1;
	return arr[top_pointer-1];
}

void mstack::pop() {
	top_pointer--;
}


int main() {
	scanf("%d", &n);
	mstack st;
	st.push(1);
	cur = 1;
	result[idx++] = '+';
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		while (tmp > st.top()) {
			st.push(++cur);
			result[idx++] = '+';
		}
		if (tmp == st.top()) {
			st.pop();
			result[idx++] = '-';
		}
	}
	if (st.empty()) {
		for (int i = 0; i < idx; i++) {
			printf("%c\n", result[i]);
		}
	}
	else {
		printf("NO\n");
	}
	
}