/*
* leetcode050407.cpp
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;



class Solution {
public:
	static bool comp(const string &s1, const string &s2) {

		if (s1.size() == s2.size()) {
			return s1 < s2;
		}
		return s1.size() < s2.size();
	}

	bool checkCommon(const string &s1, const string &s2) {
		bool ret = false;

		int idx1 = 0, idx2 = 0;
		int lng1 = s1.length();
		int lng2 = s2.length();

		while (idx1 < lng1 || idx2 < lng2) {
			if (s1[idx1] < s2[idx2]) {
				if (idx1 < lng1 - 1) idx1++;
				else break;
			}
			else if (s1[idx1] == s2[idx2]) {
				ret = true;
				break;
			}
			else {
				if (idx2 < lng2 - 1) idx2++;
				else break;
			}
		}

		return ret;
	}

	int maxProduct(vector<string>& words) {
		int ret = 0;
		int lng = words.size();

		sort(words.begin(), words.end(), Solution::comp);
		for (int i = 0; i < lng; ++i) {
			sort(words[i].begin(), words[i].end());
			//cout << words[i] << "\n";
		}

		for (int i = 0; i < lng; ++i) {
			sort(words[i].begin(), words[i].end());
			//cout << words[i] << "\n";
		}

		int temp = 0, temp2 = 0;
		for (int i = lng - 1; i >= 0; --i) {
			for (int j = i - 1; j >= 0; --j) {
				//cout << "1. words[i] : " << words[i] << " | words[j] : " << words[j] << "\n";
				temp2 = words[i].size() * words[j].size();
				if (temp2 <= ret) break;
				if (checkCommon(words[i], words[j])) {
					//cout << "2. exists common" << "\n";
					continue;
				}
				else {
					temp = words[i].size() * words[j].size();
					//cout << "3. Not exists common, ret : " << ret << "\n";
					break;
				}
			}

			ret = max(ret, temp);
		}

		return ret;
	}
};

int main_leetcode050407() {
	Solution st;
	vector<string> words;

	words = { "a", "ab", "abc", "d", "cd", "bcd", "abcd" };
	//	Output: 4
	cout << st.maxProduct(words) << "\n";
	cout << "----------------------------------\n";


	words = { "abcw","baz","foo","bar","xtfn","abcdef" };
	//	Output: 16
	cout << st.maxProduct(words) << "\n";
	cout << "----------------------------------\n";

	words = { "a","aa","aaa","aaaa" };
	//	Output: 0
	cout << st.maxProduct(words) << "\n";
	cout << "----------------------------------\n";

	words = { "eae","ea","aaf","bda","fcf","dc","ac","ce","cefde","dabae" };
	//	Output: 15
	cout << st.maxProduct(words) << "\n";
	cout << "----------------------------------\n";

	return 0;
}