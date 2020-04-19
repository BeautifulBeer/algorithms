#include <cstdio>
#pragma warning(disable: 4996)
using namespace std;

struct node {
	int num;
	node* next;

	node(int n) {
		num = n;
		next = nullptr;
	}
};

class mqueue {
private:
	node* head;
	node* tail;
	int size;
	node* cur;
	node* prev;

public:
	mqueue();
	void push(int i);
	void init();
	bool next();
	int remove();
	bool empty();
	int get_size();
};

mqueue::mqueue() {
	size = 0;
	cur = prev = head = tail = nullptr;
}

void mqueue::push(int i) {
	node* tmp = new node(i);
	if (empty()) {
		head = tail = tmp;
	}
	else {
		tail->next = tmp;
		tail = tail->next;
	}
	tail->next = head;
	size++;
}

void mqueue::init() {
	cur = head;
	prev = tail;
}

bool mqueue::empty() {
	return size == 0;
}

bool mqueue::next() {
	if (cur->next == nullptr) {
		return false;
	}
	prev = cur;
	cur = cur->next;
	return true;
}

int mqueue::remove() {
	int result = 0;
	prev->next = cur->next;
	result = cur->num;
	delete cur;
	cur = prev->next;
	size--;
	return result;
}

int mqueue::get_size() {
	return size;
}

int main() {
	int N, K;
	scanf("%d %d", &N, &K);
	mqueue queue;
	for (int i = 1; i <= N; i++) {
		queue.push(i);
	}
	queue.init();
	printf("<");
	while (queue.get_size() > 1) {
		for (int i = 1; i < K; i++) {
			queue.next();
		}
		printf("%d, ", queue.remove());
	}
	printf("%d>", queue.remove());

	return 0;
}