/*
* leetpr00560.cpp
* 560. Subarray Sum Equals K
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include "stdio.h"

using namespace std;

class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {
		int ret = 0;
		//int numsArr[2 * 10000];
		int numsSize = nums.size();
		//for (int i = 0; i < numsSize; ++i) {
		//	numsArr[i] = nums[i];
		//}

		//ret = subarraySum2(numsArr, numsSize, k);
		int sum = 0;
		for (int i = 0; i < numsSize; ++i) {
			sum = nums[i];
			if (sum == k) ret += 1;
			for (int j = i + 1; j < numsSize; ++j) {
				sum += nums[j];
				if (sum == k) ret += 1;
			}
		}

		return ret;
	}

	int subarraySum2(int* nums, int numsSize, int k) {
		int ret = 0;
		int sum = 0;
		for (int i = 0; i < numsSize; ++i) {
			sum = nums[i];
			if (sum == k) ret += 1;
			for (int j = i + 1; j < numsSize; ++j) {
				sum += nums[j];
				if (sum == k) ret += 1;
			}
		}

		return ret;
	}
};

int main00560() {
	Solution st;
	vector<int> nums;
	int k;
	int output;

	nums = { 1,1,1 };
	k = 2;
	output = st.subarraySum(nums, k);
	cout << "output : " << output << endl;

	nums = { 1,2,3 };
	k = 3;
	output = st.subarraySum(nums, k);
	cout << "output : " << output << endl;

	return 0;
}