#include <iostream>

using namespace std;

int N, L, mcur, mprev, mtmpx, mtmpy, mlines;
int** map;
int delta[4][2] = {
	{0, 1},
	{1, 0},
	{0, -1},
	{-1, 0}
};
bool flag;
bool** visited;

int main(){
	cin >> N >> L;
	map = new int*[N];
	visited = new bool*[N];
	mlines = 0;
	for (int i = 0; i < N; i++) {
		map[i] = new int[N];
		visited[i] = new bool[N];
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			visited[i][j] = false;
		}
	}
	//row
	for (int i = 0; i < N; i++) {
		mprev = map[i][0];
		flag = true;
		for (int j = 1; j < N; j++) {
			mcur = map[i][j];
			//increase 1
			if (mprev + 1 == mcur) {
				for (int k = 1; k <= L; k++) {
					mtmpx = i + delta[2][0] * k;
					mtmpy = j + delta[2][1] * k;
					if (mtmpx < 0 || mtmpx >= N || mtmpy < 0 || mtmpy >= N || map[mtmpx][mtmpy] != mprev || visited[mtmpx][mtmpy]) {
						flag = false;
						break;
					}
					visited[mtmpx][mtmpy] = true;
				}
			}
			//decrease 1
			else if (mcur + 1 == mprev) {
				visited[i][j] = true;
				for (int k = 1; k < L; k++) {
					mtmpx = i + delta[0][0] * k;
					mtmpy = j + delta[0][1] * k;
					if (mtmpx < 0 || mtmpx >= N || mtmpy < 0 || mtmpy >= N || map[mtmpx][mtmpy] != mcur || visited[mtmpx][mtmpy]) {
						flag = false;
						break;
					}
					visited[mtmpx][mtmpy] = true;
				}
			}
			else if (mprev == mcur) {

			}
			else {
				flag = false;
			}
			if (!flag)break;
			mprev = mcur;
		}
		if (flag) {
			mlines++;
			/*cout << "¶óÀÎ : " << i << '\n';*/
		}
	}
	/*cout << mlines << '\n';*/

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = false;
		}
	}

	//col
	for (int i = 0; i < N; i++) {
		mprev = map[0][i];
		flag = true;
		for (int j = 1; j < N; j++) {
			mcur = map[j][i];
			//increase 1
			if (mprev + 1 == mcur) {
				for (int k = 1; k <= L; k++) {
					mtmpx = j + delta[3][0] * k;
					mtmpy = i + delta[3][1] * k;
					if (mtmpx < 0 || mtmpx >= N || mtmpy < 0 || mtmpy >= N || map[mtmpx][mtmpy] != mprev || visited[mtmpx][mtmpy]) {
						flag = false;
						break;
					}
					visited[mtmpx][mtmpy] = true;
				}
			}
			//decrease 1
			else if (mcur + 1 == mprev) {
				visited[j][i] = true;
				for (int k = 1; k < L; k++) {
					mtmpx = j + delta[1][0] * k;
					mtmpy = i + delta[1][1] * k;
					if (mtmpx < 0 || mtmpx >= N || mtmpy < 0 || mtmpy >= N || map[mtmpx][mtmpy] != mcur || visited[mtmpx][mtmpy]) {
						flag = false;
						break;
					}
					visited[mtmpx][mtmpy] = true;
				}
			}
			else if (mprev == mcur) {

			}
			else {
				flag = false;
			}
			if (!flag)break;
			mprev = mcur;
		}
		if (flag)mlines++;
	}
	cout << mlines << '\n';
}