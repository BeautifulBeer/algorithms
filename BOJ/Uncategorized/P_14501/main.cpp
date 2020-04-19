#include <iostream>

using namespace std;

// variable for counseling information, start from 1
int schedule[15+1][2];
int N, T, P, max_value;

// index is day, sum is amount of profit
void search(int index, int sum) {
	// if counseling is scheduled after quit
	if (index > N + 1) {
		return;
	}
	if (sum > max_value) {
		max_value = sum;
	}
	if (index == N + 1) {
		return;
	}
	//didn't counseling
	search(index + 1, sum);
	//did
	search(index + schedule[index][0], sum + schedule[index][1]);
}

int main(){
	cin >> N;
	max_value = 0;
	for (int i = 1; i <= N; i++) {
		cin >> T >> P;
		schedule[i][0] = T; schedule[i][1] = P;
	}
	search(1, 0);
	cout << max_value << endl;
}