#include <cstdio>
#pragma warning(disable: 4996)
using namespace std;

int T;
char buf[51];

class mstack {
private:
	int pointer;
	char* arr;
	int capacity;

public:
	mstack();
	char pop();
	void push(char ch);
	bool empty();
	bool full();
};


mstack::mstack() {
	pointer = 0;
	capacity = 20;
	arr = new char[capacity];
}

char mstack::pop() {
	if (empty()) {
		return '\0';
	}
	return arr[--pointer];
}

void mstack::push(char ch) {
	if (full()) {
		char* arr2 = new char[capacity * 2];
		for (int i = 0; i < capacity; i++) {
			arr2[i] = arr[i];
		}
		capacity = capacity * 2;
		arr = arr2;
	}
	arr[pointer++] = ch;
}

bool mstack::empty() {
	return (pointer == 0);
}

bool mstack::full() {
	return (capacity == pointer);
}

int main() {
	bool flag;
	mstack st;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		flag = true;
		while (!st.empty())st.pop();
		scanf(" %s", buf);
		int idx = 0;
		while (buf[idx] != '\0') {
			if (buf[idx] == '(') {
				st.push(buf[idx]);
			}
			else {
				if (!st.empty()) {
					st.pop();
				}
				else {
					flag = false;
					break;
				}
			}
			idx++;
		}
		if (!flag || !st.empty()) {
			printf("NO\n");
		}
		else {
			printf("YES\n");
		}
	}
}