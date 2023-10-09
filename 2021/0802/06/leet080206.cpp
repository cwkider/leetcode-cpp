/*
* leet080206.cpp
* Group Anagrams
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> ret;

		vector<pair<string, int>> sorted;
		int sz = strs.size();
		for (int i = 0; i < sz; ++i) {
			string str = strs[i];
			sort(str.begin(), str.end());
			sorted.push_back({ str, i });
		}
		sort(sorted.begin(), sorted.end());
		//    	for(int i = 0; i < sz; ++i)
		//    		cout << sorted[i].first << endl;

		vector<string> ret1;
		ret1.push_back(strs[sorted[0].second]);
		if (sz == 1) ret.push_back(ret1);
		for (int i = 1; i < sz; ++i) {
			if (sorted[i - 1].first.compare(sorted[i].first) == 0) {
				ret1.push_back(strs[sorted[i].second]);
				if (i == sz - 1) ret.push_back(ret1);
			}
			else {
				int sz1 = ret1.size();
				vector<string> ret2(sz1);
				copy(ret1.begin(), ret1.end(), ret2.begin());
				ret.push_back(ret2);
				ret1.clear();
				ret1.resize(0);
				ret1.push_back(strs[sorted[i].second]);
				if (i == sz - 1) ret.push_back(ret1);
			}
		}

		return ret;
	}
};

int main_leet080206() {
	Solution st;
	vector<string> strs;
	vector<vector<string>> ret;
	int sz1, sz2;

	strs = { "eat", "tea", "tan", "ate", "nat", "bat" };
	//Output: [["bat"], ["nat", "tan"], ["ate", "eat", "tea"]]
	ret = st.groupAnagrams(strs);
	sz1 = ret.size();
	for (int i = 0; i < sz1; ++i) {
		for (int j = 0; j < sz2; ++j) {
			cout << ret[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "-----------------\n";


	return 0;
}