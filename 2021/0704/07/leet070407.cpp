/*
* leet070407.cpp
* 3Sum Closest
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int ret = 0;

		if(target >= 0)
		sort(nums.begin(), nums.end());
		else 
			sort(nums.begin(), nums.end(), greater<int>());

		int sz = nums.size();
		//ret = nums[sz - 1] + nums[sz - 2] + nums[sz - 3];
		ret = nums[0] + nums[1] + nums[2];

		int sum = 0;
		int ngap = 0;
		int rgap = abs(ret - target);
		for (int i = 3; i <= sz - 1; ++i) {
			for (int j = 0; j <= i - 2; ++j) {
				int k = j + 1;
				for (; k <= i - 1; ++k) {
					//cout << "ret : " << ret << " | rgap : " << rgap << "\n";
					sum = nums[i] + nums[j] + nums[k];
					ngap = abs(sum - target);
					//cout << "sum : " << sum << " | ngap : " << ngap << "\n";
					if (ngap < rgap) {
						ret = sum;
						rgap = ngap;
					}
					else {
						if (target > 0 && sum > target) break;
						if (target < 0 && sum < target) break;
					}
				}
				if (k == j + 1) break;
			}
		}
		return ret;
	}
};

int main_leet070407() {
	Solution st;
	vector<int> nums;
	int target;

	nums = { -1, 2, 1, -4 };
	target = 1;
	//Output: 2
	cout << st.threeSumClosest(nums, target) << "\n";
	cout << "-------------------------\n";

	return 0;
}