#include <set>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

struct comp
{
	template<typename T>
	bool operator()(const T& lhs, const T& rhs) const {
		if (lhs[0] == rhs[0]) {
			if (lhs[1] == rhs[1]) {
				return lhs[2] < rhs[2];
			}
			return lhs[1] < rhs[1];
		}
		return lhs[0] < rhs[0];
	}
};

class Solution {
public:
	short counts[2000001];
	int offset = 100000;
	vector<int> triplet(int a, int b, int c) {
		vector<int> result;
		result.emplace_back(a);
		result.emplace_back(b);
		result.emplace_back(c);
		sort(result.begin(), result.end());
		return result;
	}
	vector<vector<int>> threeSum(vector<int>& nums) {
		int* numbers;
		int size, remain;
		set<int> s;
		vector<int>::iterator viter;
		set<int>::iterator siter;
		set<vector<int>>::iterator stiter;
		set<vector<int>, comp> sresult;
		vector<vector<int>> result;
		for (viter = nums.begin(); viter != nums.end(); viter++) {
			s.insert(*viter);
			counts[offset + *viter]++;
		}
		size = s.size();
		numbers = new int[size];
		size = 0;
		for (siter = s.begin(); siter != s.end(); siter++) {
			numbers[size++] = *siter;
		}
		if (counts[offset] > 2) {
			sresult.insert(triplet(0, 0, 0));
		}
		for (int i = 0; i < size - 1; i++) {
			for (int j = i + 1; j < size; j++) {
				remain = (numbers[i] + numbers[j]) * -1;
				if (remain >= -100000 && remain <= 100000 && counts[offset + remain] > 0) {
					if (remain == numbers[i] || remain == numbers[j]) {
						if (remain != 0 && counts[offset + remain] > 1) {
							sresult.insert(triplet(remain, numbers[i], numbers[j]));
						}
					}
					else {
						sresult.insert(triplet(remain, numbers[i], numbers[j]));
					}
				}
			}
		}
		for (int i = 0; i < size; i++) {
			if (counts[offset + numbers[i]] > 1) {
				remain = numbers[i] * -2;
				if (remain != 0 && remain >= -100000 && remain <= 100000 && counts[offset + remain] > 0) {
					sresult.insert(triplet(remain, numbers[i], numbers[i]));
				}
			}
		}

		for (stiter = sresult.begin(); stiter != sresult.end(); stiter++) {
            result.emplace_back(*stiter);
        }
		return result;
	}
};

