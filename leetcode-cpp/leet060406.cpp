/*
* leet060406.cpp
* Count of Smaller Numbers After Self
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> countSmaller(vector<int>& nums) {
		vector<int> ret;

		map<int, int> mp;
		int sz = nums.size();
		map<int, int>::iterator miter;
		for (int i = 0; i < sz; ++i) {
			miter = mp.find(nums[i]);
			if (miter != mp.end()) {
				miter->second += 1;
			}
			else {
				mp.insert({ nums[i], 1 });
			}
		}

		int cnt = 0;
		for (miter = mp.begin(); miter != mp.end(); ++miter) {
			cnt += miter->second;
			miter->second = cnt;
		}

		vector<int> vkey;
		vector<int> vval;
		int vidx = 0;
		for (miter = mp.begin(); miter != mp.end(); ++miter) {
			vkey.push_back(miter->first);
			vval.push_back(miter->second);
			cout << "vkey[vidx] : " << vkey[vidx] << " | vval[vidx] : " << vval[vidx] << "\n";
			vidx++;
		}

		map<int, int>::iterator miter2;
		vector<int>::iterator viter;
		for (int i = 0; i < sz; ++i) {
			cout << "nums[i] : " << nums[i] << "\n";
			viter = lower_bound(vkey.begin(), vkey.end(), nums[i]);
			int idx = -1;
			if (viter != vkey.end()) {
				idx = viter - vkey.begin();
				cout << "nums[idx] : " << nums[idx] << "\n";
				if (vkey[idx] < nums[i] && vval[idx] > 0) {
					cnt = vval[idx];
				}
				else {
					for (int j = idx - 1; j >= 0; --j) {
						if (vval[j] > 0) {
							cnt = vval[j];
							cout << "vkey[j] : " << vkey[j] << " | vval[j] : " << vval[j] << "\n";
							break;
						}
					}
				}
			}
			else {
				cout << "not found \n";
			}
			if(idx != -1) vval[idx] -= 1;
			ret.push_back(cnt);
			cnt = 0;
		}

		return ret;
	}
};

int main_leet060406() {
	Solution st;
	vector<int> nums;
	vector<int> ret;
	int lng;

	nums = { 5,2,6,1 };
	//Output: [2,1,1,0]
	ret = st.countSmaller(nums);
	lng = ret.size();
	for (int i = 0; i < lng; ++i)
		cout << ret[i] << " ";
	cout << "\n-------------------------------\n";

	//nums = { -1 };
	////Output: [0]
	//ret = st.countSmaller(nums);
	//lng = ret.size();
	//for (int i = 0; i < lng; ++i)
	//	cout << ret[i] << " ";
	//cout << "\n-------------------------------\n";

	//nums = { -1, -1 };
	////Output: [0, 0]
	//ret = st.countSmaller(nums);
	//lng = ret.size();
	//for (int i = 0; i < lng; ++i)
	//	cout << ret[i] << " ";
	//cout << "\n-------------------------------\n";

	return 0;
}