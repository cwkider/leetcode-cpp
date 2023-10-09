/*
* leet080305.cpp
* Decode Ways
*/
#include <iostream>
#include <cstring>

using namespace std;

class Solution {
	int cache[100];
public:
	int numDecodings(string s) {
		for (int i = 0; i < 100; ++i)
			cache[i] = -1;

		return getWayNums(0, s);
	}

	int getWayNums(int now, string& s) {
		int sz = s.length();
		int val = s[now] - '0';
		if (val == 0) return 0;
		if (now == sz - 1) {
			return 1;
		}

		int &ret = cache[now];
		if (ret > -1) return ret;
		ret = 0;
		ret += getWayNums(now + 1, s);
		int val2 = s[now + 1] - '0';
		int val3 = (val * 10) + val2;
		if (val3 <= 26) {
			if (now <= sz - 3) ret += getWayNums(now + 2, s);
			else ret += 1;
		}

		return ret;
	}
};

int main_leet080305() {
	Solution st;
	string s;
	
	s = "12";
	//Output: 2
	cout << st.numDecodings(s) << "\n";
	cout << "-------------------------------\n";

	s = "226";
	//Output: 3
	cout << st.numDecodings(s) << "\n";
	cout << "-------------------------------\n";

	s = "0";
	//Output: 0
	cout << st.numDecodings(s) << "\n";
	cout << "-------------------------------\n";

	s = "27";
	//Output: 1
	cout << st.numDecodings(s) << "\n";
	cout << "-------------------------------\n";
	return 0;
}