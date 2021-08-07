/*
* leet060103.cpp
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		bool ret = false;

		if (s1.length() + s2.length() != s3.length()) return false;

		if (s1.length() == 0) {
			if (s2.compare(s3) == 0) return true;
			else return false;
		}
		if (s2.length() == 0) {
			if (s1.compare(s3) == 0) return true;
			else return false;
		}

		int cache[100][100];
		for (int i = 0; i < 100; ++i)
			for (int j = 0; j < 100; ++j)
				cache[i][j] = -1;
		ret = checkInter(0, 0, 0, s1, s2, s3, cache);

		return ret;
	}

	int checkInter(int idx1, int idx2, int idx3, string& s1, string& s2, string& s3, int cache[100][100]) {
		//cout << "1] s1 : " << s1 << " | s2 : " << s2 << " | s3 : " << s3 << " | idx1 : " << idx1 << " | idx2 : " << idx2 << " | idx3 : " << idx3 << "\n";

		int lng1 = s1.length();
		int lng2 = s2.length();
		int lng3 = s3.length();
		if (idx1 == lng1 && idx2 == lng2) return 1;

		int& ret = cache[idx1][idx2];
		if (ret != -1) return ret;

		//if (lng1 - idx1 > lng3 - idx3) return false;
		//if (lng2 - idx2 > lng3 - idx3) return false;

		if (idx1 == lng1) {
			if (s2.substr(idx2, lng2 - idx2).compare(s3.substr(idx3, lng3 - idx3)) == 0) ret = 1;
			else ret = 0;

			return ret;
		}

		if (idx2 == lng2) {
			if (s1.substr(idx1, lng1 - idx1).compare(s3.substr(idx3, lng3 - idx3)) == 0) ret = 1;
			else ret = 0;

			return ret;
		}

		char c3 = s3[idx3];
		char c1 = s1[idx1];
		char c2 = s2[idx2];

		if (idx1 < lng1) {
			if (c1 == c3) {
				ret = checkInter(idx1 + 1, idx2, idx3 + 1, s1, s2, s3, cache);
			}
			else {
				if (idx2 == lng2) return 0;
				if(c2 == c3) ret = checkInter(idx1, idx2 + 1, idx3 + 1, s1, s2, s3, cache);
				else ret = 0;
			}
			if (ret == 1) return ret;
		}

		if (idx2 < lng2) {
			if (c1 == c3 && c2 == c3) ret = checkInter(idx1, idx2 + 1, idx3 + 1, s1, s2, s3, cache);
			else {
				if (idx1 == lng1) ret = 0;
				if (c1 != c3) ret = 0;
			}
			if (ret == 1) return ret;
		}

		return ret;
	}
};

int main_leet060103() {
	Solution st;
	string s1, s2, s3;

	s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac";
	//Output: true / 1
	cout << st.isInterleave(s1, s2, s3) << "\n";
	cout << "--------------------------\n";

	s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc";
	//Output: false / 0
	cout << st.isInterleave(s1, s2, s3) << "\n";
	cout << "--------------------------\n";

	s1 = "", s2 = "", s3 = "";
	//Output: true / 1
	cout << st.isInterleave(s1, s2, s3) << "\n";
	cout << "--------------------------\n";

	s1 = "cacbbbaaabbacbbbbabbcaccccabaaacacbcaacababbaabbaccacbaabac";
	s2 = "cbcccabbbbaaacbaccbabaabbccbbbabacbaacccbbcaabaabbbcbcbab";
	s3 = "ccbcccacbabbbbbbaaaaabbaaccbabbbbacbcbcbaacccbacabbaccbaaabcacbbcabaabacbbcaacaccbbacaabababaabbbaccbbcacbbacabbaacb";
	//Output: false / 0
	cout << st.isInterleave(s1, s2, s3) << "\n";
	cout << "--------------------------\n";

	s1 = "";
	s2 = "b";
	s3 = "b";
	//Output: true / 1
	cout << st.isInterleave(s1, s2, s3) << "\n";
	cout << "--------------------------\n";

	s1 = "a";
	s2 = "b";
	s3 = "ab";
	//Output: true / 1
	cout << st.isInterleave(s1, s2, s3) << "\n";
	cout << "--------------------------\n";

	s1 = "aabcc";
	s2 = "dbbca";
	s3 = "aadbbcbcac";
	//Output: true / 1
	cout << st.isInterleave(s1, s2, s3) << "\n";
	cout << "--------------------------\n";

	s1 = "bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa";
	s2 = "babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab";
	s3 = "babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab";
	//Output: false / 0
	cout << st.isInterleave(s1, s2, s3) << "\n";
	cout << "--------------------------\n";

	return 0;
}