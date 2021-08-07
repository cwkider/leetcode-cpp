/*
* leet070303.cpp
* 4Sum
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> ret;

		int sz = nums.size();

		if (sz < 4) return ret;
		sort(nums.begin(), nums.end());

		int i = 0, j = 0, p = 0, q = 0;
		vector<int> temp;
		for (i = 0; i <= sz - 4; ++i) {
			if (i > 0 && nums[i - 1] == nums[i]) continue;
			for (j = i + 1; j <= sz - 3; ++j) {
				if (j > i + 1 && nums[j - 1] == nums[j]) continue;
				for (p = j + 1; p <= sz - 2; ++p) {
					if (p > j + 1 && nums[p - 1] == nums[p]) continue;
					for (q = p + 1; q <= sz - 1; ++q) {
						if (q > p + 1 && nums[q - 1] == nums[q]) continue;
						int sum = nums[i] + nums[j] + nums[p] + nums[q];
						if (sum == target) {
							
							temp.push_back(nums[i]);
							temp.push_back(nums[j]);
							temp.push_back(nums[p]);
							temp.push_back(nums[q]);
							int rsz = ret.size();
							bool sameyn = false;
							//for (int k = 0; k < rsz; ++k) {
							//	if (nums[i] == ret[k][0] && nums[j] == ret[k][1] && nums[p] == ret[k][2] && nums[q] == ret[k][3]) {

							if(rsz > 0) {
								if (nums[i] == ret[rsz - 1][0] && nums[j] == ret[rsz - 1][1] && nums[p] == ret[rsz - 1][2] && nums[q] == ret[rsz - 1][3]) {
									sameyn = true;
									break;
								}
							}
							if(sameyn == false) ret.push_back(temp);
						}
						else if (sum > target) {
							break;
						}
					}
				}
			}
		}
		return ret;
	}
};

int main_leet070303() {
	Solution st;
	vector<int> nums;
	int target;
	vector<vector<int>> ret;
	int sz;

	nums = {1, 0, -1, 0, -2, 2};
	target = 0;
	//Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
	ret = st.fourSum(nums, target);
	sz = ret.size();
	for (int i = 0; i < sz; ++i) {
		for (int j = 0; j < 4; ++j) {
			cout << ret[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "------------------------------\n";

	nums = { 2,2,2,2,2 };
	target = 8;
	//Output: [[2,2,2,2]]
	ret = st.fourSum(nums, target);
	sz = ret.size();
	for (int i = 0; i < sz; ++i) {
		for (int j = 0; j < 4; ++j) {
			cout << ret[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "------------------------------\n";

	return 0;
}