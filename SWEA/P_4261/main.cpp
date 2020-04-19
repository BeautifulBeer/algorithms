#include <iostream>

using namespace std;

int T, N, input_length, word_length, result;
char buf[1024];
char word[1000];
char input[1000];

char get_key_pad(char ch) {
	if (ch >= 'a' && ch <= 'c') {
		return '2';
	}
	else if (ch >= 'd' && ch <= 'f') {
		return '3';
	}
	else if (ch >= 'g' && ch <= 'i') {
		return '4';
	}
	else if (ch >= 'j' && ch <= 'l') {
		return '5';
	}
	else if (ch >= 'm' && ch <= 'o') {
		return '6';
	}
	else if (ch >= 'p' && ch <= 's') {
		return '7';
	}
	else if (ch >= 't' && ch <= 'v') {
		return '8';
	}
	else if (ch >= 'w' && ch <= 'z') {
		return '9';
	}
}

bool is_equal() {
	if (input_length != word_length)return false;
	for (int i = 0; i < input_length; i++) {
		if (input[i] != word[i]) {
			return false;
		}
	}
	return true;
}

int main() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		result = 0;
		scanf("%s %d", buf, &N);
		input_length = 0;
		while (buf[input_length] != '\0') {
			input[input_length] = get_key_pad(buf[input_length]);
			input_length++;
		}
		for (int i = 0; i < N; i++) {
			scanf("%s", buf);
			word_length = 0;
			while (buf[word_length] != '\0') {
				word[word_length] = get_key_pad(buf[word_length]);
				word_length++;
			}
			if (is_equal()) {
				result++;
			}
		}
		cout << '#' << t << ' ' << result << '\n';
	}
}