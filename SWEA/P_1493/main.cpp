#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <cmath>

using namespace std;

tuple<int, int> getRange(int num) {
	int x = 0, y = 0;
	x = (int)floor((1+sqrt(8*num-7))/2);
	y = (int)ceil((sqrt(8*num+1)-1)/2);
	return make_tuple(x, y);
}

int getValue(int x, int y) {
	return (int)(pow(x + y, 2) / 2 - (3 * x + y) / 2 + 1);
}

int main() {
	int T, p, q, result, tx, ty, tmp;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		result = 0;
		cin >> p >> q;
		auto range = getRange(p);
		tx = get<0>(range);
		ty = get<1>(range);
		tmp = getValue(tx, 1);
		/*cout << tmp << " " << tx << " , " << ty << "\n";*/
		tx -= abs(tmp - p);
		tmp = getValue(1, ty);
		ty -= abs(tmp - p);
		/*cout << tmp << " " << tx << " , " << ty << "\n";*/
		auto p_coor = make_tuple(tx, ty);
		range = getRange(q);
		tx = get<0>(range);
		ty = get<1>(range);
		tmp = getValue(tx, 1);
		/*cout << tmp << " " << tx << " , " << ty << "\n";*/
		tx -= abs(tmp - q);
		tmp = getValue(1, ty);
		ty -= abs(tmp - q);
		/*cout << tmp << " " << tx << " , " << ty << "\n";*/
		auto q_coor = make_tuple(tx, ty);
		result = getValue(get<0>(p_coor) + get<0>(q_coor), get<1>(p_coor) + get<1>(q_coor));
		cout << '#' << t << ' ' << result << '\n';
	}
} 