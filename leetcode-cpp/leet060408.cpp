/*
* leet060408.cpp
* Remove All Adjacent Duplicates In String
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <string.h>
#include <sstream>

using namespace std;

class Solution {
public:
	string removeDuplicates(string s) {
		string ret = "";

		char cstack[100000];
		char cs[100000];
		#pragma warning(disable:4996) // C4996 에러를 무시
		strcpy(cs, s.c_str());
		int top = -1;
		int lng = s.length();
		for (int i = 0; i < lng; ++i) {
			if (top == -1 || cstack[top] != cs[i]) {
				top++;
				cstack[top] = cs[i];
			}
			else {
				top--;
			}
		}

		for (int i = 0; i <= top; ++i) {
			ret += cstack[i];
		}

		return ret;
	}
};

int main_leet060408() {
	Solution st;
	string s;
	string ret;

	s = "abbaca";
	//Output: "ca"
	cout << st.removeDuplicates(s) << "\n";
	cout << "---------------------------------\n";

	s = "azxxzy";
	//Output: "ay"
	cout << st.removeDuplicates(s) << "\n";
	cout << "---------------------------------\n";

	return 0;
}