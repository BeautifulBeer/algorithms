#include <iostream>
#include <limits.h>
#include <cmath>

using namespace std;

int N, team_size, mcount, tmpIdx, total, mstart, mlink, mmin = INT32_MAX, mtmp;
int** map;
int* choosen;
int* nchoosen;
bool* checked;

void search(int index, int depth) {
	if (depth == team_size) {
		//process
		mstart = 0; mlink = 0;
		/*for (int i = 0; i < team_size; i++) {
			cout << choosen[i] << ' ';
		}
		cout << '\n';*/
		for (int i = 0; i < N; i++) {
			checked[i] = false;
		}
		for (int i = 0; i < team_size; i++) {
			checked[choosen[i]] = true;
			for (int j = 0; j < team_size; j++) {
				mstart += map[choosen[i]][choosen[j]];
			}
		}
		tmpIdx = 0;
		for (int i = 0; i < N; i++) {
			if (!checked[i]) {
				nchoosen[tmpIdx++] = i;
			}
		}

		for (int i = 0; i < team_size; i++) {
			for (int j = 0; j < team_size; j++) {
				mlink += map[nchoosen[i]][nchoosen[j]];
			}
		}
		/*cout << "start / link : " << mstart << ' ' << mlink << '\n';*/
		mtmp = abs(mstart - mlink);
		mmin = (mmin > mtmp) ? mtmp : mmin;
		return;
	}
	for(int i=index; i<N; i++){
		choosen[depth] = i;
		search(i + 1, depth + 1);
	}
}

int main(){
	cin >> N;
	team_size = (int)N / 2;
	map = new int*[N];
	choosen = new int[N];
	nchoosen = new int[N];
	checked = new bool[N];
	for (int i = 0; i < N; i++) {
		map[i] = new int[N];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	search(0,0);
	cout << mmin << '\n';
}