#include <cstdio>

int tmpx, tmpy, n;
int map[20][20];

struct pos {
	int x, y;
};

struct babyshark {
	int size, remains, x, y;
	babyshark();
	void eat(int x, int y);
};

babyshark::babyshark() {
	size = 2;
	remains = 2;
}

void babyshark::eat(int x, int y) {
	if (--remains == 0) {
		remains = ++size;
	}
	this->x = x;
	this->y = y;
}

struct node {
	pos p;
	node* next;

	node(pos p) {
		this->p = p;
	}
};

class mqueue {
private:
	int size;
	node* front;
	node* rear;

public:
	mqueue();
	bool empty();
	void push(pos p);
	pos pop();
	int get_size();
};

mqueue::mqueue() {
	size = 0;
	front = rear = nullptr;
}

bool mqueue::empty() {
	return size == 0;
}

int mqueue::get_size() {
	return size;
}

void mqueue::push(pos p) {
	if (empty()) {
		rear = new node(p);
		front = rear;
	}
	else {
		rear->next = new node(p);
		rear = rear->next;
	}
	size++;
}

pos mqueue::pop() {
	pos result;
	node* discarded = front;
	result = front->p;
	if (size == 1) {
		front = rear = nullptr;
	}
	else {
		front = front->next;
	}
	delete discarded;
	size--;
	return result;
}

class mpqueue {
private:
	int size;
	int capacity;
	pos* arr;

public:
	mpqueue();
	bool empty();
	bool full();
	void push(pos p);
	pos pop();
	bool compare(pos p1, pos p2);
};

mpqueue::mpqueue() {
	capacity = 20;
	size = 0;
	arr = new pos[capacity + 1];
}

bool mpqueue::empty() {
	return size == 0;
}

bool mpqueue::full() {
	return size == capacity;
}

void mpqueue::push(pos p) {
	if (full()) {
		pos* arr2 = new pos[capacity*2+1];
		for (int i = 1; i <= capacity; i++) {
			arr2[i] = arr[i];
		}
		capacity = capacity * 2;
		delete[] arr;
		arr = arr2;
	}
	size++;
	arr[size] = p;
	int idx = size;
	pos tmp;
	while (idx != 1) {
		if (compare(arr[idx], arr[idx/2])) {
			tmp = arr[idx / 2];
			arr[idx / 2] = arr[idx];
			arr[idx] = tmp;
			idx = idx / 2;
		}
		else {
			break;
		}
	}
}

pos mpqueue::pop() {
	bool flag;
	pos result = arr[1];
	arr[1] = arr[size];
	size--;
	pos tmp;
	int idx = 1;
	while (true) {
		if (idx * 2 + 1 <= size) { // left, right 다 존재하는 경우
			flag = compare(arr[idx * 2], arr[idx * 2 + 1]); // left가 더 클 경우 left를, right가 더 클 경우 right를 넣어줌
			idx = (flag) ? idx * 2 : idx * 2 + 1; 
			if (compare(arr[idx], arr[idx / 2])) { // 자식 중에 우선순위가 더 큰 값을 비교
				tmp = arr[idx];
				arr[idx] = arr[idx / 2];
				arr[idx / 2] = tmp;
			}
			else {
				break;
			}
		}
		else if (idx * 2 <= size) {// left밖에 없는 경우
			idx = idx * 2;
			if (compare(arr[idx], arr[idx/2])) { // left가 더 큰 경우
				tmp = arr[idx];
				arr[idx] = arr[idx / 2];
				arr[idx / 2] = tmp;
			}
			else {
				break;
			}
		}
		else {
			break;
		}
	}
	return result;
}

bool mpqueue::compare(pos p1, pos p2) {
	return (p1.x == p2.x) ? (p1.y < p2.y) : (p1.x < p2.x);
}

int delta[4][2] = {
	{0, -1},
	{-1, 0},
	{0, 1},
	{1, 0}
};
int time;
babyshark bs;
bool visited[20][20];
mpqueue priority_queue;
mqueue queue;

bool bfs() {
	while (!queue.empty())queue.pop();
	while (!priority_queue.empty())priority_queue.pop();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = false;
		}
	}
	visited[bs.x][bs.y] = true;
	pos tmp;
	int distance = 0, size;
	queue.push(pos({bs.x, bs.y}));
	while (!queue.empty()) {
		size = queue.get_size();
		distance++;
		for (int i = 0; i < size; i++) {
			tmp = queue.pop();
			for (int j = 0; j < 4; j++) {
				tmpx = tmp.x + delta[j][0];
				tmpy = tmp.y + delta[j][1];
				if (tmpx < 0 || tmpx >= n || tmpy < 0 || tmpy >= n) {
					continue;
				}
				if (!visited[tmpx][tmpy] && map[tmpx][tmpy] <= bs.size) {
					visited[tmpx][tmpy] = true;
					queue.push(pos({tmpx, tmpy}));
					if (map[tmpx][tmpy] > 0 && map[tmpx][tmpy] < bs.size) {
						priority_queue.push(pos({tmpx, tmpy}));
					}
				}
			}
		}
		if (!priority_queue.empty()) {
			tmp = priority_queue.pop();
			bs.eat(tmp.x, tmp.y);
			map[tmp.x][tmp.y] = 0;
			time += distance;
			return true;
		}
	}
	return false;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 9) {
				bs.x = i;
				bs.y = j;
				map[i][j] = 0;
			}
		}
	}
	time = 0;
	while (bfs());
	printf("%d", time);
}