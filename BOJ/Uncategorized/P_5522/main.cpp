#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


int main() {
	int result = 0, tmp;
	for (int i = 0; i < 5; i++) {
		cin >> tmp;
		result += tmp;
	}
	cout << result << "\n";
}


