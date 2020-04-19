#include <iostream>

using namespace std;


// 위치
struct pos {
	int x, y;
};

// 벡터 클래스
class mvector {
private:
	int size;
	int capacity;
	pos* arr;

public:
	mvector();
	void push(pos p);
	pos get(int idx);
	bool empty();
	bool full();
};

mvector::mvector() {
	size = 0;
	capacity = 10;
	arr = new pos[capacity];
}

void mvector::push(pos e) {
	if (full()) {
		pos* arr2 = new pos[capacity * 2];
		for (int i = 0; i < capacity; i++) {
			arr2[i] = arr[i];
		}
		capacity = capacity * 2;
		delete[] arr;
		arr = arr2;
	}
	arr[size++] = e;
}

pos mvector::get(int idx) {
	return arr[idx];
}

bool mvector::empty() {
	return (size == 0);
}

bool mvector::full() {
	return (size == capacity);
}

// min_dist : 정답 , MAX_DIST : 한 치킨거리의 상한값
int N, M, min_dist = 987654321, tmp, MAX_DIST = 500;
// 치킨집, 집 개수
int chickens, houses;
// 조합 값을 담고있는 배열
int* combinations;
char** map;
// 치킨집과 집 사이의 치킨거리를 담고있는 배열
int** dist;
// 치킨집, 집에 대한 정보를 담고있는 벡터
mvector chicken_arr, house_arr;

// permutation 함수 : picked는 지금까지 고른 요소의 개수
void delivery(int index, int picked) {
	if (picked > M)return;
	int sum_dist = 0;
	for (int i = 0; i < houses; i++) {
		tmp = MAX_DIST;
		for (int j = 0; j < picked; j++) {
			if (tmp > dist[i][combinations[j]]) {
				tmp = dist[i][combinations[j]];
			}
		}
		sum_dist += tmp;
	}
	if (min_dist > sum_dist) {
		min_dist = sum_dist;
	}
	for (int i = index; i < chickens; i++) {
		combinations[picked] = i;
		delivery(i + 1, picked + 1);
	}
}

int mabs(int a) {
	if (a < 0) {
		return a * -1;
	}
	return a;
}


int main() {
	cin >> N >> M;
	map = new char*[N];
	combinations = new int[N];
	houses = chickens = 0;
	for (int i = 0; i < N; i++) {
		map[i] = new char[N];
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == '1') {
				houses++;
				house_arr.push(pos({i,j}));
			}
			else if (map[i][j] == '2') {
				chickens++;
				chicken_arr.push(pos({ i,j }));
			}
		}		
	}
	dist = new int*[houses];
	for (int i = 0; i < houses; i++) {
		dist[i] = new int[chickens];
		for (int j = 0; j < chickens; j++) {
			dist[i][j] = mabs(house_arr.get(i).x - chicken_arr.get(j).x) + mabs(house_arr.get(i).y - chicken_arr.get(j).y);
		}
	}
	delivery(0, 0);
	cout << min_dist << '\n';
}