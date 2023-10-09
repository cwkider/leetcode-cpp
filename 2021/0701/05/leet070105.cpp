/*
* leet070105.cpp
* Count Vowels Permutation
*/

#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

class Solution {
	int cache[5][(2 * 10000) + 1];
	vector<vector<char>> vcRules;
public:
	int countVowelPermutation(int n) {
		int ret = 0;
		int mod = 1000000000 + 7;

		for (int i = 0; i < 5; ++i) {
			memset(cache[i], 0, sizeof(int) * ((2 * 10000) + 1));
		}

		vector<char> vcRules2;
		vcRules2.push_back('e');
		vcRules.push_back(vcRules2);
		vcRules2.clear();
		
		vcRules2.push_back('a');
		vcRules2.push_back('i');
		vcRules.push_back(vcRules2);
		vcRules2.clear();

		vcRules2.push_back('a');
		vcRules2.push_back('e');
		vcRules2.push_back('o');
		vcRules2.push_back('u');
		vcRules.push_back(vcRules2);
		vcRules2.clear();

		vcRules2.push_back('i');
		vcRules2.push_back('u');
		vcRules.push_back(vcRules2);
		vcRules2.clear();

		vcRules2.push_back('a');
		vcRules.push_back(vcRules2);
		vcRules2.clear();

		ret += getCnt('a', n);
		ret = ret % mod;
		ret += getCnt('e', n);
		ret = ret % mod;
		ret += getCnt('i', n);
		ret = ret % mod;
		ret += getCnt('o', n);
		ret = ret % mod;
		ret += getCnt('u', n);
		ret = ret % mod;

		return ret;
	}

	int getCnt(char now, int n) {
		if (n == 1) return 1;
		int mod = 1000000000 + 7;

		int idx;
		if (now == 'a') idx = 0;
		else if (now == 'e') idx = 1;
		else if (now == 'i') idx = 2;
		else if (now == 'o') idx = 3;
		else if (now == 'u') idx = 4;

		int& ret = cache[idx][n];
		if (ret > 0) return ret;

		ret = 0;
		int sz = vcRules[idx].size();
		for (int i = 0; i < sz; ++i) {
			ret += (getCnt(vcRules[idx][i], n - 1) % mod);
			ret = ret % mod;
		}

		return ret;

	}
};

int main_leet070105() {
	Solution st;
	int n;

	n = 1;
	// Output: 5
	cout << st.countVowelPermutation(n) << "\n";
	cout << "--------------------------------\n";

	n = 2;
	// Output: 10
	cout << st.countVowelPermutation(n) << "\n";
	cout << "--------------------------------\n";

	n = 5;
	// Output: 68
	cout << st.countVowelPermutation(n) << "\n";
	cout << "--------------------------------\n";

	return 0;
}