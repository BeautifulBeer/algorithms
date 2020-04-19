#include <cstdio>

struct node {
	int value;
	node* next;

	node(int num) {
		value = num;
		next = nullptr;
	}
};

class mqueue {
private:
	int capacity;
	node* front;
	node* rear;

public:
	mqueue();
	bool empty();
	void push(int num);
	int pop();
	int size();
};

mqueue::mqueue() {
	capacity = 0;
	front = rear = nullptr;
}

bool mqueue::empty() {
	return (capacity == 0);
}

void mqueue::push(int num) {
	if (empty()) {
		rear = new node(num);
		front = rear;
	}
	else {
		rear->next = new node(num);
		rear = rear->next;
	}
	capacity++;
}

int mqueue::pop() {
	int return_value = -1;
	if (front != nullptr) {
		return_value = front->value;
		node* discarded = front;
		front = front->next;
		delete discarded;
		capacity--;
		if (empty()) {
			front = rear = nullptr;
		}
	}
	return return_value;
}

int mqueue::size() {
	return capacity;
}


int main() {
	int N, K;
	mqueue queue;
	scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; i++) {
		queue.push(i);
	}
	int idx = 1, tmp;
	printf("<");
	while (queue.size() > 1) {
		tmp = queue.pop();
		if (idx == K) {
			printf("%d, ", tmp);
			idx = 1;
		}
		else {
			queue.push(tmp);
			idx++;
		}
	}
	printf("%d", queue.pop());
	printf(">");
}