/*
* leet080405.cpp
* Sum of Square Numbers Solution
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
	vector<int> nums;
public:
	bool judgeSquareSum(int c) {
		bool ret = false;

		if (c == 0) return true;

		int sz = nums.size();
		if (sz == 0) {
			int maxk = 1;
			for (int i = 0; i < 30; ++i) {
				maxk = maxk << 1;
				maxk += 1;
			}
			maxk -= 1;
			int mhalfk = maxk / 2;
			if (maxk % 2 == 1) mhalfk += 1;
			for (int i = 1; i <= mhalfk; ++i) {
				int pwi = i * i;
				if (pwi <= mhalfk) {
					nums.push_back(pwi);
				}
				else break;
			}
		}

		if (isSqrtInt(c)) return true;
		int halfc = c / 2;
		if (halfc % 2 == 1) halfc += 1;
		sz = nums.size();
		for (int i = 0; i < sz; ++i) {
			if (nums[i] > halfc) break;
			int rest = c - nums[i];
			if (rest <= 0) break;
			if (isSqrtInt(rest)) return true;
		}

		return ret;
	}

	bool isSqrtInt(int n) {
		int s = sqrt(n);
		if (s * s == n) return true;
		else return false;
	}
};