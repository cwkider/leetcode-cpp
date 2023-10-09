/*
* leetpr00015.cpp
* 15. 3Sum
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> ret = {};

		sort(nums.begin(), nums.end());
		int sz = nums.size();
		if (sz < 3) return ret;
		for (int i = 0; i < sz - 2; ++i) {
			if (i != 0 && nums[i - 1] == nums[i]) continue;
			int sum = 0;
			int right = sz - 1;
			int j = i + 1;
			while (j < sz - 1 && j < right) {
				if (j != i + 1 && nums[j - 1] == nums[j]) {
					j++;
					continue;
				}
				sum = nums[i] + nums[j] + nums[right];
				if (sum < 0) {
					j++;
					continue;
				}
				else if (sum > 0) {
					right--;
				}
				else { // sum == 0
					//cout << "i : " << i << " | j : " << j << " | right : " << right << " | ret size : " << ret.size() << "\n";
					//int rsz = ret.size();
					ret.push_back({ nums[i], nums[j], nums[right] });

					j++;
				}
			}
		}
		
		return ret;
	}
};

int main00015() {
	Solution st;
	vector<int> nums;
	vector<vector<int>> output;
	int sz;
	
	nums = { -1,0,1,2,-1,-4 };
	output = st.threeSum(nums);
	sz = output.size();
	cout << "output size : " << sz << "\n";
	cout << "[";
	for (int i = 0; i < sz; ++i) {
		cout << "[" << output[i][0] << "," << output[i][1] << "," << output[i][2] << "]";
		if (i != sz - 1) cout << ",";
	}
	cout << "]";

	return 0;
}