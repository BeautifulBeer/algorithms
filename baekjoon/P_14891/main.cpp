#include <iostream>
#include <cmath>
#include <string>

using namespace std;


class gear {
private:
	int index;
	int left, right;
	char arr[8];
public:
	gear(int index, const char str[8]);
	char getLeft();
	char getRight();
	int getScore();
	void move(bool flag);
};

gear::gear(int index, const char str[8]) {
	this->index = index;
	this->left = 6;
	this->right = 2;
	for (int i = 0; i < 8; i++) {
		this->arr[i] = str[i];
	}
}

char gear::getLeft() {
	return arr[left];
}
char gear::getRight() {
	return arr[right];
}

int gear::getScore() {
	int result = 0;
	int top = left;
	for (int i = 0; i < 2; i++) {
		if (top == 7) {
			top = 0;
		}
		else {
			top++;
		}
	}
	if (arr[top] == '1') {
		result = (int)pow(2, index - 1);
	}
	return result;
}

void gear::move(bool flag) {
	if (flag) {
		if (this->right == 7) {
			this->right = 0;
		}
		else {
			this->right++;
		}
		if (this->left == 7) {
			this->left = 0;
		}
		else {
			this->left++;
		}
	}
	else {
		if (this->right == 0) {
			this->right = 7;
		}
		else {
			this->right--;
		}
		if (this->left == 0) {
			this->left = 7;
		}
		else {
			this->left--;
		}
	}
}

int K, a, b, mprev, mcur, result;
gear** gears;
int state[5];
char tmp[8];

bool check(gear* left, gear* right) {
	return (left->getRight() != right->getLeft());
}
int main() {
	char ch;
	result = 0;
	gears = new gear*[5];
	for (int i = 1; i <= 4; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> ch;
			tmp[j] = ch;
		}
		gears[i] = new gear(i, tmp);
	}
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> a >> b;
		for(int i=1; i<=4; i++){
			state[i] = 0;
		}
		state[a] = b;
		mprev = mcur = a;
		for (mcur = mcur + 1; mcur <= 4; mcur++) {
			if (check(gears[mprev], gears[mcur]) && state[mprev] != 0) {
				state[mcur] = state[mprev] * -1;
			}
			mprev = mcur;
		}

		mprev = mcur = a;
		for (mcur = mcur - 1; mcur >= 1; mcur--) {
			if (check(gears[mcur], gears[mprev]) && state[mprev] != 0) {
				state[mcur] = state[mprev] * -1;
			}
			mprev = mcur;
		}
		for (int i = 1; i <= 4; i++) {
			if (state[i] == 1) {
				gears[i]->move(false);
			}
			else if(state[i] == -1) {
				gears[i]->move(true);
			}
		}
	}
	for (int i = 1; i <= 4; i++) {
		result += gears[i]->getScore();
	}
	cout << result << '\n';
}