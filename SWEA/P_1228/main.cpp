#include <iostream>
#include <string>
#include <list>

using namespace std;



int main() {
	char command;
	int N, cipher, insert_index, insert_number;
	list<int> ciphers;
	//test case 
	for (int i = 1; i <= 10; i++) {
		ciphers.clear();
		cin >> N;
		for (int j = 0; j < N; j++) {
			cin >> cipher;
			ciphers.emplace_back(cipher);
		}
		cin >> N;
		for (int j = 0; j < N; j++) {
			cin >> command >> insert_index >> insert_number;
			list<int>::iterator it = ciphers.begin();
			for (int k = 0; k < insert_index; k++) {
				it++;
			}
			for (int k = 0; k < insert_number; k++) {
				cin >> cipher;
				ciphers.insert(it, cipher);
				/*for (auto num : ciphers) {
					cout << num << " ";
				}
				cout << endl;*/
			}
		}
		cout << "#" << i << " ";
		list<int>::iterator it = ciphers.begin();
		for (int j = 0; j < 10; j++) {
			cout << *it++ << " ";
		}
		
	}
}
