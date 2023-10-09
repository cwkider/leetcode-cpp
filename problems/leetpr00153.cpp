/*
* leetpr00153.cpp
* 153. Find Minimum in Rotated Sorted Array
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int findMin(vector<int>& nums) {
		int ret = 0;

		int sz = nums.size() - 1;
		if (sz == 0) return nums[0];
		int low = 0;
		int high = sz;
		int mid, prev, next;

		while (low <= high) {
			mid = (low + high) / 2;
			prev = mid - 1;
			if (prev < 0) prev = sz;
			next = mid + 1;
			if (next > sz) next = 0;
			if (nums[mid] > nums[next]) return nums[next];

			if (nums[low] > nums[mid]) high = mid - 1;
			else low = mid + 1;
		}

		return ret;
	}
};