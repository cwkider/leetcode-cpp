/*
* leet050405.cpp
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		int itokens[10001];
		int lng = tokens.size();
		if (lng == 1) return atoi(tokens[0].c_str());

		int idx1 = 0, idx2 = 0;;

		int num1, num2, rst;
		while(idx1 < lng) {
			if (tokens[idx1].compare("+") == 0) {
				num1 = itokens[idx2 - 2];
				num2 = itokens[idx2 - 1];
				rst = num1 + num2;
				itokens[idx2 - 2] = rst;
				idx2--;
			}
			else if (tokens[idx1].compare("-") == 0) {
				num1 = itokens[idx2 - 2];
				num2 = itokens[idx2 - 1];
				rst = num1 - num2;
				itokens[idx2 - 2] = rst;
				idx2--;
			}
			else if (tokens[idx1].compare("*") == 0) {
				num1 = itokens[idx2 - 2];
				num2 = itokens[idx2 - 1];
				rst = num1 * num2;
				itokens[idx2 - 2] = rst;
				idx2--;
			}
			else if (tokens[idx1].compare("/") == 0) {
				num1 = itokens[idx2 - 2];
				num2 = itokens[idx2 - 1];
				rst = num1 / num2;
				itokens[idx2 - 2] = rst;
				idx2--;
			}
			else {
				itokens[idx2] = atoi(tokens[idx1].c_str());
				idx2++;
			}
			idx1++;
		}

		return itokens[0];
	}
};

int main_leet050405() {
	Solution st;
	vector<string> tokens;

	tokens = { "2","1","+","3","*" };
	cout << st.evalRPN(tokens) << "\n";
	cout << "------------------------------" << "\n";

	tokens = { "4","13","5","/","+" };
	cout << st.evalRPN(tokens) << "\n";
	cout << "------------------------------" << "\n";

	tokens = { "10","6","9","3","+","-11","*","/","*","17","+","5","+" };
	cout << st.evalRPN(tokens) << "\n";
	cout << "------------------------------" << "\n";

	return 0;
}