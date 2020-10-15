#include <cstdio>

using namespace std;

struct pos {
	int x, y;
};
struct node {
	pos v;
	node* next;
	node(pos a) {
		v = a;
		next = nullptr;
	}
};

inline int abs(int a);
bool move_population();
bool check_diff(pos a, pos b);
bool bfs(pos a);

int N, L, R, tmp, tmpx, tmpy;
int delta[4][2] = {
	{0, -1},
	{-1, 0},
	{0, 1},
	{1, 0}
};
int map[50 + 2][50 + 2];
bool visited[50 + 2][50 + 2];

class mqueue {
private:
	node* front;
	node* rear;
	int size;
public:
	mqueue();
	bool empty();
	void push(pos a);
	pos pop();
};

mqueue::mqueue() {
	front = rear = nullptr;
	size = 0;
}

bool mqueue::empty() {
	return (size == 0);
}

void mqueue::push(pos a) {
	if (empty()) {
		rear = new node(a);
		front = rear;
	}
	else {
		rear->next = new node(a);
		rear = rear->next;
	}
	size++;
}

pos mqueue::pop() {
	pos result;
	node* n = front;
	result = n->v;
	front = front->next;
	size--;
	if (empty()) {
		front = rear = nullptr;
	}
	delete n;
	return result;
}
mqueue q1, q2;


inline int abs(int a) {
	return (a > 0) ? a : a * -1;
}

bool check_diff(pos a, pos b) {
	tmp = abs(map[a.x][a.y] - map[b.x][b.y]);
	if (tmp >= L && tmp <= R) {
		return true;
	}
	else {
		return false;
	}
}

bool move_population() {
	bool flag = false;
	// init array
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			visited[i][j] = false;
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!visited[i][j]) {
				visited[i][j] = true;
				flag |= bfs(pos({i, j}));
			}
		}
	}
	return flag;
}

bool bfs(pos a) {
	while (!q1.empty())q1.pop();
	while (!q2.empty())q2.pop();
	int cnt = 1, total_sum = map[a.x][a.y];
	q1.push(a);
	q2.push(a);
	pos t;
	while (!q1.empty()) {
		t = q1.pop();
		for (int i = 0; i < 4; i++) {
			tmpx = t.x + delta[i][0]; tmpy = t.y + delta[i][1];
			if (!visited[tmpx][tmpy] && check_diff(t, pos({tmpx, tmpy}))) {
				visited[tmpx][tmpy] = true;
				q1.push(pos({ tmpx, tmpy }));
				q2.push(pos({ tmpx, tmpy }));
				cnt++;
				total_sum += map[tmpx][tmpy];
			}
		}
	}
	total_sum = total_sum / cnt;
	// 이동할 수 있는 나라들끼리 인구수 맞춰줌
	while (!q2.empty()) {
		t = q2.pop();
		map[t.x][t.y] = total_sum;
	}
	if (cnt > 1) {
		return true;
	}
	return false;
}



int main() {
	scanf("%d %d %d", &N, &L, &R);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf(" %d", &map[i][j]);
		}
	}
	// 경계 체크를 하지 않기 위해서 경계에 큰 값을 줌
	for (int i = 0; i <= N + 1; i++) {
		map[0][i] = map[i][0] = map[N + 1][i] = map[i][N + 1] = 1000;
	}
	// 인구 이동은 2000번을 넘지 않기 때문에 2000번까지만.
	for (int i = 0; i < 2000; i++) {
		// 한번도 움직이지 않으면 끝.
		if (!move_population()) {
			printf("%d\n", i);
			break;
		}
	}
}