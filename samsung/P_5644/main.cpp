#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

// 위치
struct pos {
	int x, y;
};

// 배터리 충전기
struct battery {
	int c, p;
	pos position;
};


int T, M, A, x, y, sum;
pos user_a, user_b;
int instruction[100][2];
int chgA[8];
int chgB[8];
//battery bc[8];
vector<battery> bc;
int delta[5][2] = {
	{0, 0},
	{0, -1},
	{1, 0},
	{0, 1},
	{-1, 0}
};

void move(pos& user, int direction) {
	user.x += delta[direction][0];
	user.y += delta[direction][1];
}

int distance(pos& a, pos& b) {
	return abs(a.x - b.x) + abs(a.y - b.y);
}



int charge() {
	int charging = 0;
	int chargerA = 0, chargerB = 0;
	for (int i = 0; i < A; i++) {
		if (bc[i].c >= distance(user_a, bc[i].position)) {
			chgA[chargerA++] = i;
		}
		if (bc[i].c >= distance(user_b, bc[i].position)) {
			chgB[chargerB++] = i;
		}
	}
	if (chargerA == 0 && chargerB != 0) {
		charging = bc[chgB[0]].p;
	}
	else if(chargerB == 0 && chargerA != 0){
		charging = bc[chgA[0]].p;
	}
	else if(chargerB != 0 && chargerA != 0){
		for (int i = 0; i < chargerA; i++) {
			for (int j = 0; j < chargerB; j++) {
				if (chgA[i] == chgB[j]) {
					if (charging < bc[chgA[i]].p) {
						charging = bc[chgA[i]].p;
					}
				}
				else {
					if (charging < bc[chgA[i]].p + bc[chgB[j]].p) {
						charging = bc[chgA[i]].p + bc[chgB[j]].p;
					}
				}
			}
		}
	}
	return charging;
}

bool compare(const battery& b1, const battery& b2) {
	return (b1.p > b2.p);
}

int main() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		user_a = pos({1, 1});
		user_b = pos({ 10, 10 });
		bc.clear();
		cin >> M >> A;
		sum = 0;
		for (int i = 0; i < M; i++) {
			cin >> instruction[i][0];
		}
		for (int i = 0; i < M; i++) {
			cin >> instruction[i][1];
		}
		
		for (int i = 0; i < A; i++) {
			cin >> x >> y;
			battery tmp;
			tmp.position = pos({ x, y });
			cin >> tmp.c;
			cin >> tmp.p;
			bc.push_back(tmp);
		}
		sort(bc.begin(), bc.end(), compare);
		sum += charge();
		for (int i = 0; i < M; i++) {
			move(user_a, instruction[i][0]);
			move(user_b, instruction[i][1]);
			sum += charge();
		}
		cout << "#" << t << " " << sum << '\n';
	}
}