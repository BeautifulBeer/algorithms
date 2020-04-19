#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


int main() {
	int neg = 0, pos = 0;
	string str;
	getline(cin, str);
	int index = -1;
	while ((index = str.find(":-",index+1)) != -1) {
		if (index + 2 < str.length()) {
			if (str[index + 2] == ')') {
				pos++;
			}
			else if (str[index + 2] == '(') {
				neg++;
			}
		}
	}
	if (!neg && !pos) {
		cout << "none" << "\n";
	}
	else if (neg == pos) {
		cout << "unsure" << "\n";
	}
	else if (neg > pos) {
		cout << "sad" << "\n";
	}
	else {
		cout << "happy" << "\n";
	}
}


