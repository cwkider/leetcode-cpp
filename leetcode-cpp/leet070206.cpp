/*
* leet070206.cpp
* Isomorphic Strings
*/

#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
	map<char, int> scnt;
	map<char, int> tcnt;
	vector<pair<int, char>> svt;
	vector<pair<int, char>> tvt;
	map<char, char> mp;
public:
	bool isIsomorphic(string s, string t) {
		//cout << "s : " << s << " | t : " << t << "\n";
		bool ret = true;

		int lng = s.length();
		int idx = 0;
		char ctemp;
		scnt.clear();
		tcnt.clear();
		map<char, int>::iterator citer;
		for (int i = 0; i < lng; ++i) {
			ctemp = s[i];
			citer = scnt.find(ctemp);
			if (citer != scnt.end()) {
				citer->second++;
			}
			else {
				scnt.insert({ ctemp, 1 });
			}

			ctemp = t[i];
			citer = tcnt.find(ctemp);
			if (citer != tcnt.end()) {
				citer->second++;
			}
			else {
				tcnt.insert({ ctemp, 1 });
			}
		}

		svt.assign(0, { 0, 0 });
		tvt.assign(0, { 0, 0 });
		int ssz = scnt.size();
		int tsz = tcnt.size();

		if (ssz != tsz) return false;

		for (citer = scnt.begin(); citer != scnt.end(); citer++) {
			svt.push_back({ citer->second, citer->first });
		}

		for (citer = tcnt.begin(); citer != tcnt.end(); citer++) {
			tvt.push_back({ citer->second, citer->first });
		}

		sort(svt.begin(), svt.end(), greater<>());
		sort(tvt.begin(), tvt.end(), greater<>());
		for (int i = 0; i < ssz; ++i) {
			//cout << "i : " << i << " | svt[i].first : " << svt[i].first << " | svt[i].second : " << svt[i].second << " | tvt[i].first : " << tvt[i].first << " | tvt[i].second : " << tvt[i].second << "\n";
			if (svt[i].first != tvt[i].first) return false;
		}

		mp.clear();
		char stemp, mtemp, ttemp;
		map<char, char>::iterator miter;
		for (int i = 0; i < lng; ++i) {
			stemp = s[i];
			miter = mp.find(stemp);
			ttemp = t[i];
			if (miter != mp.end()) {
				mtemp = miter->second;
				if (mtemp != ttemp) return false;
			}
			else {
				int sidx = stemp - 'a';
				int tidx = ttemp - 'a';
				if (scnt[sidx] == tcnt[tidx]) {
					mp.insert({ stemp, ttemp });
				}
				else {
					return false;
				}
			}
		}

		return ret;
	}
};

int main_leet070206() {
	Solution st;
	string s, t;

	s = "egg", t = "add";
	// Output: true / 1
	cout << st.isIsomorphic(s, t) << "\n";

	s = "foo", t = "bar";
	// Output: false / 0
	cout << st.isIsomorphic(s, t) << "\n";

	s  = "paper", t = "title";
	// Output: true / 1
	cout << st.isIsomorphic(s, t) << "\n";

	s = "aaeaa", t = "uuxyy";
	// Output: false / 0
	cout << st.isIsomorphic(s, t) << "\n";

	return 0;
}