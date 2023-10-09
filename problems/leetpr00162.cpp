/*
* leetpr00162.cpp
* 162. Find Peak Element
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		int ret = 0;
		int len = nums.size() - 1;
		if (len == 0) return 0;
		int low = 0;
		int high = len;
		int mid;
		while (low <= high) {
			mid = (low + high) / 2;
			if (mid == 0 && nums[mid] > nums[mid + 1]) return mid;
			if (mid == len && nums[mid] > nums[mid - 1]) return mid;
			if (mid != 0 && mid != len && nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) return mid;

			if (mid != len && nums[mid] < nums[mid + 1]) low = mid + 1;
			else if (mid != 0 && nums[mid] < nums[mid - 1]) high = mid - 1;
		}

		return ret;
	}
};