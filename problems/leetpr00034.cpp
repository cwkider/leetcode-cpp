/*
* leetpr00034.cpp
* 34. Find First and Last Position of Element in Sorted Array
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> result = { -1, -1 };

		int lng = nums.size();
		if (lng == 0) return result;

		int low = 0;
		int high = lng - 1;
		int mid = 0;
		while (low <= high) {
			//cout << "low : " << low << " | high : " << high << "\n";
			mid = (low + high) / 2;
			if (nums[mid] > target) high = mid - 1;
			else if (nums[mid] < target) low = mid + 1;
			else {
				result[0] = 0;
				for (int i = mid - 1; i >= 0; --i) {
					if (nums[i] != target) {
						result[0] = i + 1;
						break;
					}
				}
				result[1] = lng - 1;
				for (int i = mid + 1; i < lng; ++i) {
					if (nums[i] != target) {
						result[1] = i - 1;
						break;
					}
				}

				break;
			}
		}

		return result;
	}
};

int main00034() {
	vector<int> nums;
	int target;
	Solution st;
	vector<int> result;

	nums = { 5, 7, 7, 8, 8, 10 };
	target = 8;
	result = st.searchRange(nums, target);
	cout << result[0] << " " << result[1] << "\n";
	cout << "=================================\n";

	nums = { 5,7,7,8,8,10 };
	target = 6;
	result = st.searchRange(nums, target);
	cout << result[0] << " " << result[1] << "\n";
	cout << "=================================\n";

	return 0;
}