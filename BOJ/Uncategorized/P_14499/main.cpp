#include <iostream>

using namespace std;

// structure for dice, each surface
struct dice {
	int value;
	dice* up;
	dice* down;
	dice* left;
	dice* right;

	dice() {
		value = 0;
		up = nullptr;
		down = nullptr;
		left = nullptr;
		right = nullptr;
	}
};

/*
	x, y : current position of a dice
	direction : move instruction of a dice
	N, M : size of a map
	K : the number of instruction
*/
int N, M, x, y, K, tmp, tmpx, tmpy, direction;
int map[20][20]{0};
// delta value of moving
int delta[5][2] = {
	{0,0}, // meaningless
	{0, 1}, // east = 1
	{0, -1}, // west = 2
	{-1, 0}, // north = 3
	{1, 0} // south = 4
};
// a dice
dice* top;

// move dice to direction
void move_dice(int direct) {
	dice* cur;
	tmp = top->value;
	cur = top;
	for (int i = 0; i < 3; i++) {
		switch (direct) {
		case 1: // east
			cur->value = cur->left->value;
			cur = cur->left;
			break;
		case 2: // west
			cur->value = cur->right->value;
			cur = cur->right;
			break;
		case 3: // north
			cur->value = cur->down->value;
			cur = cur->down;
			break;
		case 4: // south
			cur->value = cur->up->value;
			cur = cur->up;
			break;
		}
	}
	cur->value = tmp;
}
int main(){
	//make dice, each surface
	dice* one = new dice();
	dice* two = new dice();
	dice* three = new dice();
	dice* four = new dice();
	dice* five = new dice();
	dice* six = new dice();
	// top surface
	top = one;

	top->left = two; two->right = top;
	two->left = three; three->right = two;
	three->left = four; four->right = three;
	four->left = top; top->right = four;

	top->up = five; five->down = top;
	five->up = three; three->down = five;
	three->up = six; six->down = three;
	six->up = top; top->down = six;
	
	cin >> N >> M >> x >> y >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> tmp;
			map[i][j] = tmp;
		}
	}
	for (int i = 0; i < K; i++) {
		cin >> direction;
		tmpx = x + delta[direction][0];
		tmpy = y + delta[direction][1];
		// ignore case in out of boundary
		if (tmpx < 0 || tmpx >= N || tmpy < 0 || tmpy >= M) {
			continue;
		}
		move_dice(direction);
		x = tmpx; y = tmpy;
		// if dice is on the zero value
		if (map[x][y] == 0) {
			map[x][y] = top->right->right->value;
		}
		else {
			top->right->right->value = map[x][y];
			map[x][y] = 0;
		}
		cout << top->value << '\n';
	}
}