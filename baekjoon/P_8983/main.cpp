#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct animal {
	int x, y;
	bool operator() (animal a, animal b) { return (a.x < b.x); }
} animalObj;

int M, N, L, tmp_x, tmp_y;
long result = 0;
vector<animal> animals;
vector<int> cannon;

int binarySearch(int num) {
	int start = 0, end = cannon.size(), search = 0;
	while (start < end) {
		search = (start + end) / 2;
		if (cannon[search] < num) {
			start = search + 1;
		}
		else {
			end = search;
		}
	}
	if (start == cannon.size() || cannon[start] > num)start--;
	return start;
}


int main() {
	cin >> M >> N >> L;
	for (int i = 0; i < M; i++) {
		cin >> tmp_x;
		cannon.push_back(tmp_x);
	}
	for (int j = 0; j < N; j++) {
		cin >> tmp_x >> tmp_y;
		animals.push_back({ tmp_x, tmp_y});
	}
	//sort(animals.begin(), animals.end(), animalObj);
	/*for (int i = 0; i < animals.size(); i++) {
		cout << animals[i].x << " ";
	}
	cout << endl;*/
	sort(cannon.begin(), cannon.end());
	/*for (int i = 0; i < cannon.size(); i++) {
		cout << cannon[i] << " ";
	}
	cout << endl;*/
	for (int i = 0; i < N; i++) {
		tmp_x = binarySearch(animals[i].x);
		if (tmp_x < 0)tmp_x = 0;
		if (tmp_x == 0) {
			if (abs(cannon[0] - animals[i].x) + animals[i].y <= L) {
				result++;
			}else if (abs(cannon[1] - animals[i].x) + animals[i].y <= L) {
				result++;
			}
		}
		else if (tmp_x == cannon.size() - 1) {
			if (abs(cannon[cannon.size()-1] - animals[i].x) + animals[i].y <= L) {
				result++;
			}
			else if (abs(cannon[cannon.size() - 2] - animals[i].x) + animals[i].y <= L) {
				result++;
			}
		}
		else {
			if (abs(cannon[tmp_x-1] - animals[i].x) + animals[i].y <= L) {
				result++;
			}
			else if (abs(cannon[tmp_x + 1] - animals[i].x) + animals[i].y <= L) {
				result++;
			}
			else if (abs(cannon[tmp_x] - animals[i].x) + animals[i].y <= L) {
				result++;
			}
		}
	}
	cout << result << endl;
}