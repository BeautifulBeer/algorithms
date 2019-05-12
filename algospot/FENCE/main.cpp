#include <cstdio>
#pragma warning(disable: 4996)
using namespace std;

int C, N;
int heights[20000];

inline int mmax(int a, int b) {
	return (a > b) ? a : b;
}

inline int mmin(int a, int b) {
	return (a > b) ? b : a;
}

int divide_conquer(int start, int end) {
	if (start == end) {
		return heights[start];
	}
	int mid = (start + end) / 2;
	int min_height = heights[mid], width = 1;
	int left = mid - 1, right = mid + 1, ret = min_height;
	while (left >= start && right <= end) {
		if (heights[left] > heights[right]) {
			min_height = mmin(min_height, heights[left]);
			left--;
		}
		else {
			min_height = mmin(min_height, heights[right]);
			right++;
		}
		width++;
		ret = mmax(ret, min_height * width);
	}
	while (left >= start) {
		min_height = mmin(min_height, heights[left]);
		left--;
		width++;
		ret = mmax(ret, min_height * width);
	}
	while (right <= end) {
		min_height = mmin(min_height, heights[right]);
		right++;
		width++;
		ret = mmax(ret, min_height * width);
	}
	ret = mmax(ret, divide_conquer(start, mid));
	ret = mmax(ret, divide_conquer(mid+1, end));
	return ret;
}

int main() {
	scanf("%d", &C);
	for (int c = 0; c < C; c++) {
		scanf(" %d", &N);
		for (int i = 0; i < N; i++) {
			scanf(" %d", &heights[i]);
		}
		printf("%d\n", divide_conquer(0, N-1));
	}
}