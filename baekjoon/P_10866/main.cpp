#include <cstdio>
#pragma warning(disable: 4996)
using namespace std;

struct node {
	int v;
	node* left;
	node* right;

	node(int num) {
		v = num;
		left = right = nullptr;
	}
};

class mdeque {
private:
	int size;
	node* head;
	node* tail;

public:
	mdeque();
	void push_front(int x);
	void push_back(int x);
	int pop_front();
	int pop_back();
	int get_size();
	bool empty();
	int front();
	int back();
};

mdeque::mdeque() {
	size = 0;
	head = tail = nullptr;
}

void mdeque::push_front(int x) {
	node* tmp = new node(x);
	if (empty()) {
		head = tail = tmp;
	}
	else {
		head->left = tmp;
		tmp->right = head;
		head = head->left;
	}
	size++;
}

void mdeque::push_back(int x) {
	node* tmp = new node(x);
	if (empty()) {
		head = tail = tmp;
	}
	else {
		tail->right = tmp;
		tmp->left = tail;
		tail = tail->right;
	}
	size++;
}

int mdeque::pop_front() {
	int result = -1;
	if (!empty()) {
		node* tmp = head;
		if (size == 1) {
			head = tail = nullptr;
		}
		else {
			head = head->right;
			head->left = nullptr;
		}
		result = tmp->v;
		delete tmp;
		size--;
	}
	return result;
}

int mdeque::pop_back() {
	int result = -1;
	if (!empty()) {
		node* tmp = tail;
		if (size == 1) {
			head = tail = nullptr;
		}
		else {
			tail = tail->left;
			tail->right = nullptr;
		}
		result = tmp->v;
		delete tmp;
		size--;
	}
	return result;
}

int mdeque::get_size() {
	return size;
}

bool mdeque::empty() {
	return size == 0;
}

int mdeque::front() {
	if (empty()) {
		return -1;
	}
	return head->v;
}

int mdeque::back() {
	if (empty()) {
		return -1;
	}
	return tail->v;
}

bool strcmp(const char* str, char buf[]) {
	bool flag = true;
	int idx = -1;
	while (str[++idx] != '\0') {
		if (str[idx] != buf[idx]) {
			flag = false;
			break;
		}
	}
	return flag;
}

int main() {
	mdeque deque;
	int N, num;
	char buf[11];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf(" %s", buf);
		if (strcmp("push_front", buf)) {
			scanf(" %d", &num);
			deque.push_front(num);
		}else if (strcmp("push_back", buf)) {
			scanf(" %d", &num);
			deque.push_back(num);
		}
		else if (strcmp("pop_front", buf)) {
			printf("%d\n", deque.pop_front());
		}
		else if (strcmp("pop_back", buf)) {
			printf("%d\n", deque.pop_back());
		}
		else if (strcmp("size", buf)) {
			printf("%d\n", deque.get_size());
		}
		else if (strcmp("empty", buf)) {
			printf("%d\n", deque.empty());
		}
		else if (strcmp("front", buf)) {
			printf("%d\n", deque.front());
		}
		else if (strcmp("back", buf)) {
			printf("%d\n", deque.back());
		}
	}
}