#include <cstdio>
#pragma warning(disable: 4996)
using namespace std;

struct node {
	int v;
	node* next;

	node(int n) {
		v = n;
		next = nullptr;
	}
};

class mqueue {
private:
	int size;
	node* head;
	node* tail;

public:
	mqueue();
	void push(int x);
	int pop();
	int get_size();	
	int empty();
	int front();
	int back();
};

mqueue::mqueue() {
	size = 0;
	head = tail = nullptr;
}

void mqueue::push(int x) {
	node* tmp = new node(x);
	if (empty()) {
		head = tail = tmp;
	}
	else {
		tail->next = tmp;
		tail = tail->next;
	}
	size++;
}

int mqueue::pop() {
	node* tmp = nullptr;
	int result = -1;
	if (!empty()) {
		result = head->v;
		tmp = head;
		if (size == 1) {
			head = tail = nullptr;
		}
		else {
			head = head->next;
		}
		delete tmp;
		size--;
	}
	return result;
}

int mqueue::get_size() {
	return size;
 }

int mqueue::empty() {
	return size == 0;
}

int mqueue::front() {
	if (empty()) {
		return -1;
	}
	else {
		return head->v;
	}
}

int mqueue::back() {
	if (empty()) {
		return -1;
	}
	else {
		return tail->v;
	}
}

bool strcmp(const char* str, char buf[]) {
	bool flag = true;
	int idx = -1;
	while (str[++idx] != '\0') {
		if (str[idx] != buf[idx]) {
			flag = false;
		}
	}
	return flag;
}

int main() {
	mqueue queue;
	int N, num, tmp;
	char buf[6];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf(" %s", buf);
		if (strcmp("push", buf)) {
			scanf(" %d", &num);
			queue.push(num);
		}
		else if (strcmp("pop", buf)) {
			printf("%d\n", queue.pop());
		}
		else if (strcmp("size", buf)) {
			printf("%d\n", queue.get_size());
		}
		else if (strcmp("empty", buf)) {
			printf("%d\n", queue.empty());
		}
		else if (strcmp("front", buf)) {
			printf("%d\n", queue.front());
		}
		else if (strcmp("back", buf)) {
			printf("%d\n", queue.back());
		}
	}
}