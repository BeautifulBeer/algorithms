#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int N, r, c, seq = 0;
bool found = false;

void search(int x, int y, int size) {
	//cout << x << " " << y << " " << size << " " << seq << endl;
	if (found)return;
	if (size == 1) {
		if (r == x && c == y) {
			found = true;
			return;
		}
		else {
			//cout << "seq 1" << endl;
			seq++;
			return;
		}
	}
	int length = size / 2;
	if (x <= r && r < x + length && y <= c && c < y + length) {
		search(x, y, length);
		return;
	}
	else {
		seq += length * length;
		/*cout << "0 add" << x << " " << y << " " << size << " " << seq << endl;*/
	}

	if (x <= r && r < x + length && y + length <= c && c < y + length * 2) {
		search(x, y + length, length);
		return;
	}
	else {
		seq += length * length;
		//cout <<"1 add " << x << " " << y << " " << size << " " << seq << endl;
	}
	
	if (x + length <= r && r < x + length * 2 && y <= c && c < y + length) {
		search(x + length, y, length);
		return;
	}
	else {
		seq += length * length;
		//cout << " add " << x << " " << y << " " << size << " " << seq << endl;

	}
	
	if (x + length <= r && r < x + length * 2 && y + length <= c && c < y + length * 2) {
		search(x + length, y + length, length);
		return;
	}
	else {
		seq += length * length;
		//cout << " add " << x << " " << y << " " << size << " " << seq << endl;
	}
}

int main() {
	cin >> N >> r >> c;
	seq = 0;
	found = false;
	search(0, 0, (int)pow(2, N));
	cout << seq << endl;
}


