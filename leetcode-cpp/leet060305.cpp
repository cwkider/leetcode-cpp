/*
*leet060305.cpp
* Range Sum Query - Mutable
*/

#include <iostream>
#include <vector>

using namespace std;

class NumArray {
vector<int>& onums;
int sum;
public:
	NumArray(vector<int>& nums) : onums(nums) {
		int lng = nums.size();
		sum = 0;
		for (int i = 0; i < lng; ++i) {
			//onums.push_back(nums[i]);
			sum += nums[i];
		}
		//onums = nums;
	}

	void update(int index, int val) {
		sum -= onums[index];
		onums[index] = val;
		sum += val;
	}

	int sumRange(int left, int right) {
		int rsum = sum;
		int lng = onums.size();
		for (int i = 0; i < left; ++i) {
			rsum -= onums[i];
		}
		for (int i = right + 1; i < lng; ++i) {
			rsum -= onums[i];
		}

		return rsum;
	}
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

int main_leet060305() {
	vector<int> nums;
	int index;
	int val;
	int left, right;

	nums = { 1, 3, 5 };
	NumArray* obj = new NumArray(nums);
	left = 0;
	right = 2;
	cout << obj->sumRange(left, right) << "\n";
	index = 1;
	val = 2;
	obj->update(index, val);
	left = 0;
	right = 2;
	cout << obj->sumRange(left, right) << "\n";
	cout << "-------------------------------------------\n";

	return 0;
}