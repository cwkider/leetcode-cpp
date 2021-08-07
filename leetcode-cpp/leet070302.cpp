/*
* leet070302.cpp
* Valid Triangle Number
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int triangleNumber(vector<int>& nums) {
		int ret = 0;

		sort(nums.begin(), nums.end());
		int sz = nums.size();
		if (sz < 3) return 0;

		int k = 1;
		for (int i = 0; i <= sz - 3; ++i) {
			for (int j = i + 1; j <= sz - 2; ++j) {
				if (k < j || ret == 0) k = j;
				ret += k - j;
				while (k < sz - 1) {
					k++; 
					if (nums[i] + nums[j] > nums[k]) {
						ret++;
					}
					else {
						k--;
						break;
					}
				}
				cout << "i : " << i << " | j : " << j << " | k : " << k << " | ret : " << ret << "\n";
			}
		}

		return ret;
	}
};

int main_leet070302() {
	Solution st;
	vector<int> nums;

	nums = { 2,2,3,4 };
	//Output: 3
	cout << st.triangleNumber(nums) << "\n";
	cout << "----------------------------------\n";

	nums = { 4,2,3,4 };
	//Output: 4
	cout << st.triangleNumber(nums) << "\n";
	cout << "----------------------------------\n";

	nums = { 1,1,3,4};
	//Output: 0
	cout << st.triangleNumber(nums) << "\n";
	cout << "----------------------------------\n";

	nums = { 1, 2, 3, 4, 5, 6 };
	//Output: 7
	cout << st.triangleNumber(nums) << "\n";
	cout << "----------------------------------\n";

	nums = { 24,3,82,22,35,84,19 };
	//Output: 10
	cout << st.triangleNumber(nums) << "\n";
	cout << "----------------------------------\n";

	return 0;
}