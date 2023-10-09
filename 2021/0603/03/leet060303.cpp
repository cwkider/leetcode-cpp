/*
* leet060303.cpp
* Generate Parentheses
*/

#include <iostream>
#include <sstream>
#include <string.h>
#include <cstring>
#include <vector>

using namespace std;

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> ret;

		getString(n - 1, n, n, ret, "(");

		return ret;
	}

	void getString(int l, int r, int n, vector<string>& ret, string s) {
		if (l == 0 && r == 0) {
			ret.push_back(s);
			return;
		}

		if (l > 0) {
			getString(l - 1, r, n, ret, s + "(");
		}

		if (n - l > n - r) {
			getString(l, r - 1, n, ret, s + ")");
		}

		return;
	}
};

int main_leet060303() {
	Solution st;
	int n, lng;
	vector<string> ansvt;

	n = 3;
	ansvt = st.generateParenthesis(n);
	lng = ansvt.size();
	for (int i = 0; i < lng; ++i) cout << ansvt[i] << " ";
	cout << "\n---------------------\n";

	n = 1;
	ansvt = st.generateParenthesis(n);
	lng = ansvt.size();
	for (int i = 0; i < lng; ++i) cout << ansvt[i] << " ";
	cout << "\n---------------------\n";

	return 0;
}