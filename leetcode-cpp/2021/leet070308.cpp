/*
* leet070308.cpp
* Push Dominoes
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string pushDominoes(string dominoes) {
		string ret = "";

		int lng = dominoes.length();

		int dcnt = 0;
		char domino = 'N';
		char arret[100001];
		for (int i = 0; i < lng; ++i) {
			if (dominoes[i] == '.') {
				dcnt++;
				if (domino == 'R') {
					arret[i] = 'R';
				}
				else {
					arret[i] = '.';
				}
			}
			else if (dominoes[i] == 'L') {
				if (domino == 'R') {
					int even = dcnt % 2;
					int half = dcnt / 2;
					for (int j = i - 1; j >= i - half; --j) {
						arret[j] = 'L';
					}
					if (even == 1) {
						arret[i - half - 1] = '.';
					}
				}
				else {
					for (int j = i - 1; j >= i - dcnt; --j) {
						arret[j] = 'L';
					}
				}
				arret[i] = 'L';
				domino = 'L';
				dcnt = 0;
			}
			else if (dominoes[i] == 'R') {
				arret[i] = 'R';
				domino = 'R';
				dcnt = 0;
			}
		}

		for (int i = 0; i < lng; ++i) {
			ret += arret[i];
		}

		//cout << "ret : " << ret << "\n";

		return ret;
	}
};

int main_leet070308() {
	Solution st;
	string dominoes;

	dominoes = "RR.L";
	//Output: "RR.L"
	cout << st.pushDominoes(dominoes) << "\n";
	cout << "----------------------------\n";

	dominoes = ".L.R...LR..L..";
	//Output: "LL.RR.LLRRLL.."
	cout << st.pushDominoes(dominoes) << "\n";
	cout << "----------------------------\n";

	return 0;
}