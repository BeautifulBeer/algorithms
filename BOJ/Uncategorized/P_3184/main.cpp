#include <fstream>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int row, col, sheep, wolf;
char** data_arr;
bool** check_visited;

void search(stack<int>& stack, int ridx, int cidx) {
	stack.push(cidx);
	stack.push(ridx);
	while (!stack.empty()) {
		ridx = stack.top();
		stack.pop();
		cidx = stack.top();
		stack.pop();

		// check bound, check visited
		if (ridx < 0 || cidx < 0 || ridx >= row || cidx >= col || check_visited[ridx][cidx]) {
			continue;
		}
		if (data_arr[ridx][cidx] == 'o') {
			sheep++;
		}
		else if (data_arr[ridx][cidx] == 'v') {
			wolf++;
		}
		check_visited[ridx][cidx] = true;

		stack.push(cidx);
		stack.push(ridx - 1);
		stack.push(cidx);
		stack.push(ridx + 1);
		stack.push(cidx - 1);
		stack.push(ridx);
		stack.push(cidx + 1);
		stack.push(ridx);
	}
}

int main() {
	stack<int> stack;
	//ifstream in("../../input/sample_input.txt");
	int total_sheep, total_wolf, test_case;
	char tmp;
	cin >> row >> col;
	//cout << row << col;
	data_arr = new char*[row];
	check_visited = new bool*[row];
	// init arr
	for (int i = 0; i < row; i++) {
		data_arr[i] = new char[col];
		check_visited[i] = new bool[col];
	}
	total_sheep = 0;
	total_wolf = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> tmp;
			data_arr[i][j] = tmp;
			//cout << tmp << " ";
			if (tmp == '#') {
				check_visited[i][j] = true;
			}
			else {
				check_visited[i][j] = false;
			}

		}
		//cout << endl;
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (!check_visited[i][j]) {
				sheep = 0;
				wolf = 0;
				search(stack, i, j);
				if (sheep > wolf) {
					total_sheep += sheep;
				}
				else {
					total_wolf += wolf;
				}

			}
		}
	}
	cout << total_sheep << " " << total_wolf << endl;
}
