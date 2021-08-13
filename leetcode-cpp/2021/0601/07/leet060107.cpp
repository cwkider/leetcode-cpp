/*
* leet060107.cpp
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		int ret = 1;
		int lng = nums.size();
		if (lng == 0) return 0;

		sort(nums.begin(), nums.end());
		nums.erase(unique(nums.begin(), nums.end()), nums.end());
		lng = nums.size();

		int cnt = 1;
		int now = nums[0];
		for (int i = 1; i < lng; ++i) {
			if (now + 1 == nums[i]) {
				cnt += 1;
				ret = max(ret, cnt);
			}
			else {
				cnt = 1;
			}
			now = nums[i];
		}

		return ret;
	}
};

int main_leet060107() {
	Solution st;
	vector<int> nums;

	nums = { 100,4,200,1,3,2 };
	// Output: 4
	cout << st.longestConsecutive(nums) << "\n";
	cout << "---------------------------------------\n";

	nums = { 0,3,7,2,5,8,4,6,0,1 };
	// Output: 9
	cout << st.longestConsecutive(nums) << "\n";
	cout << "---------------------------------------\n";

	nums = { 1,2,0,1 };
	// Output: 3
	cout << st.longestConsecutive(nums) << "\n";
	cout << "---------------------------------------\n";

	return 0;
}