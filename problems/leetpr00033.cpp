/*
* leetpr00033.cpp
* 33. Search in Rotated Sorted Array
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int ret = -1;

		int lng = nums.size();
		int low = 0; 
		int high = lng - 1;
		int mid = -1;
		int n = -1;
		int prev = 0;
		int next = 0;
		int target2 = -10001;
		while (low <= high) {
			mid = (low + high) / 2;
			next = mid + 1;
			if (next == lng) next = 0;
			if (nums[mid] > nums[next]) {
				n = mid;
				break;
			}
			if (nums[low] > nums[mid]) {
				high = mid - 1;
			}
			else {
				low = mid + 1;
			}
		}

		//cout << "n : " << n << "\n";
		low = n + 1;
		high = n + lng;
		//if (nums[low] == target) return n;
		int mid2;
		while (low <= high) {
			mid2 = (low + high) / 2;
			mid = mid2 % lng;
			if (nums[mid] < target) {
				low = mid2 + 1;
			}
			else if (nums[mid] > target) {
				high = mid2 - 1;
			}
			else {
				ret = mid;
				break;
			}
		}

		//cout << "n : " << n << "\n";

		return ret;
	}
};

int main00033() {
	vector<int> nums;
	int target;
	int ret;
	Solution st;
	
	nums = { 4,5,6,7,0,1,2 };
	target = 0;
	//output : 4
	ret = st.search(nums, target);
	cout << "ret : " << ret << "\n";
	cout << "===============================\n";

	nums = { 4,5,6,7,0,1,2 };
	target = 5;
	//output : 1
	ret = st.search(nums, target);
	cout << "ret : " << ret << "\n";
	cout << "===============================\n";

	nums = { 4,5,6,7,0,1,2 };
	target = 2;
	//output : 6
	ret = st.search(nums, target);
	cout << "ret : " << ret << "\n";
	cout << "===============================\n";

	nums = { 4,5,6,7,0,1,2 };
	target = 4;
	//output : 0
	ret = st.search(nums, target);
	cout << "ret : " << ret << "\n";
	cout << "===============================\n";

	nums = { 5,1,3 };
	target = 5;
	//output : 0
	ret = st.search(nums, target);
	cout << "ret : " << ret << "\n";
	cout << "===============================\n";

	return 0;
}

