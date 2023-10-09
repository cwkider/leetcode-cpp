/*
* leetpr00005.cpp
* 5. Longest Palindromic Substring
*/
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		string ret = s.substr(0, 1);

		string temp;
		for (int i = 0; i < s.length(); ++i) {
			temp = subLongestPalindrome(s, i);
			if (ret.length() < temp.length()) ret = temp;
		}

		return ret;
	}

	string subLongestPalindrome(string s, int mid) {
		string ret = "";
		
		bool oddYn = true;
		bool evenYn = true;

		int move = 1;
		int left = mid - move;
		int right = mid;
		int lng = 1;
		int retleft = 0;
		int retright = 0;
		int retlng = 0;

		while (left >= 0 && right < s.length()) {
			right = mid + move;
			if (right < s.length() && oddYn) {
				if (s[left] == s[right]) {
					if (retlng < (right - left + 1)) {
						retleft = left;
						retright = right;
						retlng = retright - retleft + 1;
					}
				}
				else
					oddYn = false;

			}

			right = mid + move - 1;
			if (right < s.length() && evenYn) {
				if (s[left] == s[right]) {
					if (retlng < (right - left + 1)) {
						retleft = left;
						retright = right;
						retlng = retright - retleft + 1;
					}
				}
				else
					evenYn = false;
			}

			if (!evenYn && !oddYn) break;

			move++;
			left = mid - move;
		}

		ret = s.substr(retleft, retright - retleft + 1);

		return ret;
	}
};

int main00005() {
	Solution st;
	string s;
	string output;

	s = "babad";
	//Output : "bab"
	//cout << "s[0] : " << s[0] << endl;
	//cout << "s[0] type id name : " << typeid(s[0]).name() << endl;
	output = st.longestPalindrome(s);
	cout << output << "\n";
	cout << "=================================\n";

	s = "cbbd";
	//Output : bb
	output = st.longestPalindrome(s);
	cout << output << "\n";
	cout << "=================================\n";

	s = "ccc";
	//Output : ccc
	output = st.longestPalindrome(s);
	cout << output << "\n";
	cout << "=================================\n";

	return 0;
}