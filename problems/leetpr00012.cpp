/*
* leetpr00012.cpp
* 12. Integer to Roman
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
	string intToRoman(int num) {
		string ret = "";
		unordered_map<int, string> um;
		um.insert(make_pair(1, "I"));
		um.insert(make_pair(2, "II"));
		um.insert(make_pair(3, "III"));
		um.insert(make_pair(4, "IV"));
		um.insert(make_pair(5, "V"));
		um.insert(make_pair(6, "VI"));
		um.insert(make_pair(7, "VII"));
		um.insert(make_pair(8, "VIII"));
		um.insert(make_pair(9, "IX"));
		um.insert(make_pair(10, "X"));
		um.insert(make_pair(20, "XX"));
		um.insert(make_pair(30, "XXX"));
		um.insert(make_pair(40, "XL"));
		um.insert(make_pair(50, "L"));
		um.insert(make_pair(60, "LX"));
		um.insert(make_pair(70, "LXX"));
		um.insert(make_pair(80, "LXXX"));
		um.insert(make_pair(90, "XC"));
		um.insert(make_pair(100, "C"));
		um.insert(make_pair(200, "CC"));
		um.insert(make_pair(300, "CCC"));
		um.insert(make_pair(400, "CD"));
		um.insert(make_pair(500, "D"));
		um.insert(make_pair(600, "DC"));
		um.insert(make_pair(700, "DCC"));
		um.insert(make_pair(800, "DCCC"));
		um.insert(make_pair(900, "CM"));
		um.insert(make_pair(1000, "M"));
		um.insert(make_pair(2000, "MM"));
		um.insert(make_pair(3000, "MMM"));

		int rest = 1;
		int mulp = 1;
		while (num > 0) {
			rest = num % 10;
			num = num / 10;
			int keyNum = rest * mulp;
			ret = um[keyNum] + ret;
			mulp = mulp * 10;
		}

		return ret;
	}
};

int main00012() {
	Solution st;
	string ret;
	int num;

	num = 3;
	//Output: "III"
	ret = st.intToRoman(num);
	cout << ret << endl;
	cout << "========================================\n";

	num = 58;
	//Output: "LVIII"
	ret = st.intToRoman(num);
	cout << ret << endl;
	cout << "========================================\n";

	num = 1994;
	//Output: "MCMXCIV"
	ret = st.intToRoman(num);
	cout << ret << endl;
	cout << "========================================\n";

	return 0;
}