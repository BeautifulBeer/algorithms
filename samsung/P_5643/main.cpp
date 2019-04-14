#include <iostream>

using namespace std;
int T, N, M, a , b, INF = 87654321, tmp;
/*
	Floyd Warshall �˰����� ���� �迭 ::
	dist = �Ÿ���
	pv = ���� ���� ����
*/
int** dist;
int** pv;
int* counts;

int main() {
	cin >> T;
	dist = new int*[500 + 1];
	pv = new int*[500 + 1];
	counts = new int[500 + 1];
	for (int i = 0; i <= 500; i++) {
		dist[i] = new int[500 + 1];
		pv[i] = new int[500 + 1];
	}
	for (int t = 1; t <= T; t++) {
		cin >> N >> M;
		for (int i = 0; i <= N; i++) {
			counts[i] = 0;
			for (int j = 0; j <= N; j++) {
				dist[i][j] = INF;
				pv[i][j] = -1;
			}
		}
		for (int i = 0; i < M; i++) {
			cin >> a >> b;
			dist[a][b] = 1;
			pv[a][b] = a;
		}

		for (int k = 1; k <= N; k++) {
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= N; j++) {
					if (dist[i][j] > dist[i][k] + dist[k][j]) {
						pv[i][j] = k;
						dist[i][j] = dist[i][k] + dist[k][j];
					}
				}
			}
		}
		// �ڽ��� ��ġ�� �˱����ؼ��� �ڽ����� ������ ������ ������ �ڽ����κ��� �� �� �ִ� ������ ������ ���� ��ü ���� - 1 �� �Ǿ���Ѵ�.
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				//�ڽ����κ��� �� �� �ִ� ������ ����
				if (pv[i][j] != -1) {
					counts[i]++;
				}
				//�ٸ� �������� �ڽ����� �� �� �ִ� ������ ����
				if (pv[j][i] != -1) {
					counts[i]++;
				}
			}
			counts[i]++;
		}
		int result = 0;
		for (int i = 1; i <= N; i++) {
			if (counts[i] == N) {
				result++;
			}
		}
		cout << '#' << t << ' ' << result << '\n';
	}
	return 0;
}