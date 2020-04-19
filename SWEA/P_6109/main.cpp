#include <iostream>
#include <fstream>
#include <deque>
#include <vector>
#include <string>

using namespace std;

int main() {
	ifstream input_file;
	string instruction;
	int test_case, array_size, tmp, deque_count;
	vector<deque<int>> data(20);
	input_file.open("P_6109.input");
	input_file >> test_case;
	while (test_case--) {
		//load data
		input_file >> array_size;
		input_file >> instruction;
		//clear deque
		for (int i = 0; i < array_size; i++) {
			data[i].clear();
		}
		for (int i = 0; i < array_size; i++) {
			for (int j = 0; j < array_size; j++) {
				input_file >> tmp;
				if (instruction == "up" || instruction == "down") {
					if(tmp)data[i].emplace_back(tmp); // insert element only non zero
				}
				else if (instruction == "left" || instruction == "right") {
					if (tmp)data[j].emplace_back(tmp);
				}
			}
		}
		//process data
		for (int i = 0; i < array_size; i++) {
			tmp = data[i].size();
			deque_count = 0;
			while (deque_count < tmp) {

			}
		}
		
	}
}
