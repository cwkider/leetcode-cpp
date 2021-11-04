/*
* leetpr00034.cpp
* 34. Find First and Last Position of Element in Sorted Array
*/
#include <iostream>
#include <vector>

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int lng = nums.size();
		vector<int> result = { -1, 1 };


		return result;
	}
};

int main() {
	vector<int> nums;
	int target;
	Solution st;

	nums = { 5, 7, 7, 8, 8, 10 };
	target = 8;
	vector<int> result = st.searchRange(nums, target);
	cout << result[0] << " " << result[1] << "\n";

	return 0;
}