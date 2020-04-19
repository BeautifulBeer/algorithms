#include <cstdio>
#pragma warning(disable: 4996)
using namespace std;

struct node {
	int num;
	node* left;
	node* right;

	node(int v) {
		num = v;
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
	void push_back(int v);
	void pop_front();
	bool empty();
	void move_right();
	void move_left();
	int find_right(int v);
	int find_left(int v);
	node* getHead() { return head; };
};

mdeque::mdeque() {
	size = 0;
	head = tail = nullptr;
}

void mdeque::push_back(int v) {
	node* tmp = new node(v);
	if (empty()) {
		head = tail = tmp;
	}
	else {
		tail->right = tmp;
		tmp->left = tail;
		tail = tail->right;
		tail->right = head;
		head->left = tail;
	}
	size++;
}

void mdeque::pop_front() {
	node* tmp = head;
	if (size == 1) {
		head = tail = nullptr;
	}
	else {
		head = head->right;
		tail->right = head;
		head->left = tail;
	}
	delete tmp;
	size--;
}

bool mdeque::empty() {
	return size == 0;
}

void mdeque::move_left() {
	if (size > 1) {
		head = head->right;
		tail = tail->right;
	}
}

void mdeque::move_right() {
	if (size > 1) {
		head = head->left;
		tail = tail->left;
	}
}

int mdeque::find_left(int v) {
	int result = 0;
	node* cur = head;
	while (cur->num != v) {
		cur = cur->left;
		result++;
	}
	return result;
}

int mdeque::find_right(int v) {
	int result = 0;
	node* cur = head;
	while (cur->num != v) {
		cur = cur->right;
		result++;
	}
	return result;
}

int main() {
	int N, M, num, left_tmp, right_tmp ,total=0;
	mdeque queue;
	scanf("%d \%d", &N, &M);
	for (int i = 1; i <= N; i++) {
		queue.push_back(i);
	}
	for (int i = 0; i < M; i++) {
		scanf("%d", &num);
		left_tmp = queue.find_left(num);
		right_tmp = queue.find_right(num);
		if (left_tmp > right_tmp) {
			total += right_tmp;
			for (int j = 0; j < right_tmp; j++) {
				queue.move_left();
			}
			queue.pop_front();
		}
		else {
			total += left_tmp;
			for (int j = 0; j < left_tmp; j++) {
				queue.move_right();
			}
			queue.pop_front();
		}
	}
	printf("%d\n", total);
}