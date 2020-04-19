#include <cstdio>
#pragma warning(disable: 4996)
using namespace std;

int total, tmp;
char buf[500];

class mstack {
private:
	int pointer;
	int* arr;
	int capacity;

public:
	mstack();
	void pop();
	int top();
	int get_size();
	int find(int op);
	void push(int num);
	bool empty();
	bool full();
};


mstack::mstack() {
	pointer = 0;
	capacity = 20;
	arr = new int[capacity];
}

int mstack::top() {
	return arr[pointer-1];
}

int mstack::get_size() {
	return pointer;
}

int mstack::find(int op){
	int result = -1;
	for (int i = pointer-1; i >= 0; i--) {
		if (arr[i] < 0) {
			if (arr[i] == op) {
				result = i;
			}
			break;
		}
	}
	return result;
}

void mstack::pop() {
	if (!empty()) {
		pointer--;
	}
}

void mstack::push(int num) {
	if (full()) {
		int* arr2 = new int[capacity*2];
		for (int i = 0; i < capacity; i++) {
			arr2[i] = arr[i];
		}
		capacity = capacity * 2;
		delete[] arr;
		arr = arr2;
	}
	arr[pointer++] = num;
}

bool mstack::empty() {
	return (pointer==0);
}

bool mstack::full() {
	return (capacity == pointer);
}

int main() {
	bool flag = true;
	int pos =0;
	mstack st;
	scanf("%s", buf);
	int idx = -1;
	while (buf[++idx] != '\0') {
		if (buf[idx] == '(') {
			//°ýÈ£ ( ¸¦ -2·Î Á¤ÀÇ
			st.push(-2);
		}
		else if (buf[idx] == ')') {
			pos = st.find(-2);
			//¹®ÀÚ¿­ Ã¼Å©
			if (pos == -1) {
				flag = false;
				break;
			}
			tmp = 0;
			//°ýÈ£ µ¡¼À Ã³¸®
			while (st.get_size()-1 > pos) {
				tmp += st.top(); st.pop();
			}
			st.pop();
			//¸¸¾à °ýÈ£ ¾ÈÀÌ ºóÄ­ÀÌ¶ó¸é?
			if (tmp == 0) {
				tmp = 1;
			}
			st.push(2 * tmp);
		}
		//°ýÈ£ [ ¸¦ -3·Î Á¤ÀÇ
		else if (buf[idx] == '[') {
			st.push(-3);
		}
		else if (buf[idx] == ']') {
			pos = st.find(-3);
			if (pos == -1) {
				flag = false;
				break;
			}
			tmp = 0;
			while (st.get_size() - 1 > pos) {
				tmp += st.top(); st.pop();
			}
			st.pop();
			if (tmp == 0) {
				tmp = 1;
			}
			st.push(3 * tmp);
		}
	}
	total = 0;
	while (!st.empty()) {
		tmp = st.top(); st.pop();
		if (tmp < 0) {
			flag = false;
			break;
		}
		total += tmp;
	}
	if (!flag) {
		printf("0\n");
	}
	else {
		printf("%d\n", total);
	}
}