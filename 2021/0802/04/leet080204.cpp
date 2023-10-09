/*
* leet080204.cpp
* Flip String to Monotone Increasing
*/
#include <iostream>

using namespace std;

class Solution {
public:
	int minFlipsMonoIncr(string s) {
		int ret = 0;

		int zerocnt = 0;
		int onecnt = 0;
		int sz = s.size();
		for (int i = 0; i < sz; ++i) {
			if (s[i] == '0') zerocnt++;
		}
		ret = zerocnt;

		for (int i = 0; i < sz; ++i) {
			if (s[i] == '0') zerocnt -= 1;
			else onecnt += 1;
			if (ret > zerocnt + onecnt) ret = zerocnt + onecnt;
		}

		return ret;
	}
};

int main_leet080204() {
	Solution st;
	string s;

	s = "00110";
	//Output: 1
	cout << st.minFlipsMonoIncr(s) << "\n";

	s = "010110";
	//Output: 2
	cout << st.minFlipsMonoIncr(s) << "\n";

	s = "00011000";
	//Output: 2
	cout << st.minFlipsMonoIncr(s) << "\n";

	return 0;
}