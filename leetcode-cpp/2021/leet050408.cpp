/*
* leet050408.cpp
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maximumUniqueSubarray(vector<int>& nums) {
		int lng = nums.size();

		int start = 0, end = 0;

		int now;
		now = nums[start];
		int ret = now;
		int subs[10001];
		memset(subs, 0, sizeof(int) * 10000);
		subs[nums[start]] = 1;
		while (end < lng - 1) {
			end++;
			
			if (subs[nums[end]] == 1) {
				while (nums[start] != nums[end]) {
					now -= nums[start];
					subs[nums[start]] = 0;
					start++;
				}
				now -= nums[start];
				subs[nums[start]] = 0;
				start++;
			}

			now += nums[end];
			subs[nums[end]] = 1;
			ret = max(ret, now);
		}

		return ret;
	}
};

int main_leet050408() {
	Solution st;
	vector<int> nums;

	nums.clear();
	nums = { 4, 2, 4, 5, 6 };
	//Output: 17
	cout << st.maximumUniqueSubarray(nums) << "\n";
	cout << "-----------------------------------\n";

	nums.clear();
	nums = { 5,2,1,2,5,2,1,2,5 };
	//Output: 8
	cout << st.maximumUniqueSubarray(nums) << "\n";
	cout << "-----------------------------------\n";

	nums.clear();
	nums = { 187, 470, 25, 436, 538, 809, 441, 167, 477, 110, 275, 133, 666, 345, 411, 459, 490, 266, 987, 965, 429, 166, 809, 340, 467, 318, 125, 165, 809, 610, 31, 585, 970, 306, 42, 189, 169, 743, 78, 810, 70, 382, 367, 490, 787, 670, 476, 278, 775, 673, 299, 19, 893, 817, 971, 458, 409, 886, 434 };
	//Output: 16911
	cout << st.maximumUniqueSubarray(nums) << "\n";
	cout << "-----------------------------------\n";

	nums.clear();
	nums = { 10000 };
	//Output: 10000
	cout << st.maximumUniqueSubarray(nums) << "\n";
	cout << "-----------------------------------\n";

	return 0;
}