#include <iostream>
#include <math.h>
#include <string>

using namespace std;

class Solution {
public:
	bool checkPalindrome(string str) {
		int lng = str.length();

		bool ret = true;
		for (int i = 0; i < lng / 2; ++i) {
			if (str[i] != str[lng - 1 - i]) {
				ret = false;
				break;
			}
		}

		return ret;
	}

	int superpalindromesInRange(string left, string right) {
		unsigned long long nleft = atoll(left.c_str());
		unsigned long long nright = atoll(right.c_str());

		unsigned long long rsqrt1 = sqrt(nright);
		string srsqrt = to_string(rsqrt1);
		unsigned long long lng2 = srsqrt.length();
		int halflng = lng2 / 2;
		if (lng2 % 2 != 0) halflng += 1;

		string srange;

		for (int i = 0; i <= halflng; ++i)  srange += "9";

		unsigned long long nrange = atoll(srange.c_str());

		int ret = 0;
		unsigned long long temp1, temp2;
		for (unsigned long long i = 1; i < 10; ++i) {
			if (checkPalindrome(to_string(i))) {
				temp1 = i * i;
				//cout << "1. temp1 : " << temp1 << "\n";
				if (temp1 >= nleft && temp1 <= nright)
					if (checkPalindrome(to_string(temp1))) ++ret;
			}
		}

		string strtemp1, strtemp2, strtemp3, strtemp;
		int templng;
		//cout << "1. nrange : " << nrange << "\n";
		for (unsigned long long i = 1; i <= nrange; ++i) {
			strtemp1 = to_string(i);
			templng  = strtemp1.length();

			strtemp2 = strtemp1;
			reverse(strtemp2.begin(), strtemp2.end());
			//cout << "strtemp2 : " << strtemp2 << "\n";

			strtemp = strtemp1 + strtemp2;

			temp2 = atoll(strtemp.c_str());
			temp1 = temp2 * temp2;
			//cout << "1. temp1 : " << temp1 << " | temp2 : " << temp2 << " | strtemp1 : " << strtemp1 << " | strtemp2 : " << strtemp2 << " | i : " << i << "\n";
			if (temp1 >= nleft && temp1 <= nright)
				if (checkPalindrome(to_string(temp1))) ++ret;

			if (templng > 1) {
				strtemp3 = strtemp2.substr(1, templng - 1);

				strtemp = strtemp1 + strtemp3;

				temp2 = atoll(strtemp.c_str());
				temp1 = temp2 * temp2;
				//cout << "2. temp1 : " << temp1 << " | temp2 : " << temp2 << " | strtemp1 : " << strtemp1 << " | strtemp2 : " << strtemp2 << " | i : " << i << "\n";
				if (temp1 >= nleft && temp1 <= nright)
					if (checkPalindrome(to_string(temp1))) ++ret;

				if (temp1 > nright) break;
			}
		}

		return ret;
	}


};

int main_leet050202() {
	Solution st;
	string left, right;

	left = "4", right = "1000";
	//output : 4

	cout << st.superpalindromesInRange(left, right) << "\n";

	left = "1", right = "2";
	//output : 1
	cout << st.superpalindromesInRange(left, right) << "\n";

	left = "1", right = "5";
	//output : 2
	cout << st.superpalindromesInRange(left, right) << "\n";

	left = "40000000000000000", right = "50000000000000000";
	//output : 2
	cout << st.superpalindromesInRange(left, right) << "\n";

	left = "1", right = "19028";
	//output : 8
	cout << st.superpalindromesInRange(left, right) << "\n";

	left = "398904669", right = "13479046850";
	//output : 6
	cout << st.superpalindromesInRange(left, right) << "\n";


	return 0;
}