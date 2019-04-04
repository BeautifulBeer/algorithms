#include <iostream>
#include <set>
#include <cmath>
#include <queue>
#include <string>

using namespace std;

int T, N, K, length, result;
char buf[28+1];
char word[7+1];

int hexValue(char ch) {
	switch (ch) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		return ch - '0';
		break;
	case 'A':
		return 10;
		break;
	case 'B':
		return 11;
		break;
	case 'C':
		return 12;
		break;
	case 'D':
		return 13;
		break;
	case 'E':
		return 14;
		break;
	case 'F':
		return 15;
		break;
	}
	return -1;
}

int convertValue(string str) {
	int result = 0;
	for (int i = 0; i < str.length(); i++) {
		result += hexValue(str[i]) * pow(16, str.length()-1-i);
	}
	return result;
}

int main() {
	set<string> s;
	priority_queue<int> pq;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		while (!pq.empty())pq.pop();
		s.clear();
		scanf("%d %d", &N, &K);
		scanf("%s", buf);
		length = N / 4;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < length; j++) {
				word[j] = buf[(i+j)%N];
			}
			word[length] = '\0';
			s.insert(string(word));
		}
		for (set<string>::iterator it = s.begin(); it != s.end(); it++) {
			pq.push(convertValue(*it));
		}
		for (int i = 0; i < K; i++) {
			result = pq.top(); pq.pop();
		}
		cout << '#' << t << ' ' << result << '\n';
	}	
}