#include <iostream>
#include <algorithm>

using namespace std;


int main() {
	char swap;
	char* arr;
	char* ans;
	int test_case, num, cnt, size, tmp, tmp2, tmp3;
	cin >> test_case;
	arr = new char[6];
	ans = new char[6];
	for (int i = 1; i <= test_case; i++) {
		cin >> num >> cnt;
		size = (int)log10(num) + 1;
		tmp = size-1;
		do {
			arr[tmp] = num % 10 + '0';
			ans[tmp] = arr[tmp];
			num = num / 10;
			tmp--;
		} while (num != 0);

		sort(ans, ans + size, greater<char>());

		for (int j = 1; j <= cnt; j++) {
			tmp = 0; tmp2 = 0;
			while (arr[tmp] == ans[tmp2] && tmp < size) {
				tmp++;
				tmp2++;
			}
			if (tmp == size) {
				tmp--;
				for (int k = 1; k < size; k++) {
					if (arr[k] == arr[k - 1]) {
						tmp = k;
						break;
					}
				}
				swap = arr[tmp];
				arr[tmp] = arr[tmp-1];
				arr[tmp-1] = swap;
			}
			else {
				tmp = size - 1;
				while (ans[tmp] != arr[tmp2]) { tmp--; }
				if (arr[tmp] == ans[tmp2]) {
					swap = arr[tmp];
					arr[tmp] = arr[tmp2];
					arr[tmp2] = swap;
				}
				else {
					tmp = size - 1;
					while (arr[tmp] != ans[tmp2]) { tmp--; }
					swap = arr[tmp];
					arr[tmp] = arr[tmp2];
					arr[tmp2] = swap;
				}
			}
		}

		cout << '#' << i << ' ';
		for (int k = 0; k < size; k++) {
			cout << arr[k];
		}
		cout << '\n';
	}
	
	return 0;
}


