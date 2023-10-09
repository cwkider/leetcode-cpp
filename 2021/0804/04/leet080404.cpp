/*
* leet080404.cpp
* Complex Number Multiplication
*/
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string complexNumberMultiply(string num1, string num2) {
		string ret = "";
		int a, b, c, d;
		getNums(&a, &b, num1);
		getNums(&c, &d, num2);
		int e, f;
		e = a * c;
		e += (-1 * b * d);
		f = (b * c) + (a * d);
		ret += to_string(e);
		ret += "+";
		ret += to_string(f);
		ret += "i";

		return ret;
	}

	void getNums(int* a, int* b, string snum) {
		int lng = snum.size();
		*a = 0;
		int nyn = 0;
		int i = 0;
		if (snum[0] == '-') {
			i++;
			nyn = 1;
		}
		while (snum[i] != '+' && snum[i] != '-') {
			*a = (*a * 10) + (snum[i] - '0');
			++i;
		}
		if (nyn == 1) *a *= -1;

		*b = 0;
		nyn = 0;
		++i;
		if (snum[i] == '-') {
			i++;
			nyn = 1;
		}
		while (snum[i] != 'i') {
			*b = (*b * 10) + (snum[i] - '0');
			++i;
		}
		if (nyn == 1) *b *= -1;
	}
};
