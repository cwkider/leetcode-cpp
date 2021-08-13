/*
* leet060302.cpp
* Matchsticks to Square
*/

#include <iostream>
#include <vector>
#include <string.h>
#include <cstring>

using namespace std;

class Solution {
public:
	bool makesquare(vector<int>& matchsticks) {
		bool ret = false;
		int lng = matchsticks.size();

		int stsum = 0;
		for (int i = 0; i < lng; ++i) {
			stsum += matchsticks[i];
		}

		if (stsum % 4 != 0) return false;
		int side = stsum / 4;
		//cout << "side : " << side << "\n";
		int lngs[4];
		memset(lngs, 0, sizeof(int) * 4);
		int useYn[16];
		memset(useYn, 0, sizeof(int) * 16);
		lngs[0] = matchsticks[0];
		useYn[0] = 1;
		
		ret = getSquare(1, side, lngs, useYn, matchsticks);

		return ret;
	}

	bool getSquare(int idx, int side, int lngs[4], int useYn[16], vector<int>& matchsticks) {
		bool ret = false;
		int lng = matchsticks.size();
		if (idx == lng - 1) {
			for (int i = 0; i < 4; ++i) {
				//cout << "side : " << side  << " | i : " << i << " | lngs[i] : " << lngs[i] << " | matchsticks[idx] : " << matchsticks[idx] << "\n";
				if (lngs[i] != side) lngs[i] += matchsticks[idx];
				if (lngs[i] != side) {
					lngs[i] -= matchsticks[idx];
					//cout << "----------------------------------\n";
					return false;
				}
			}
			//cout << "----------------------------------\n";
			return true;
		}

		for (int i = 0; i < 4; ++i) {
			if (lngs[i] < side) {
				lngs[i] += matchsticks[idx];
				//cout << "i : " << i << " | lngs[i] : " << lngs[i] << " | side : " << side << "\n";
				useYn[idx] = 1;
				if (lngs[i] <= side) {
					ret = getSquare(idx + 1, side, lngs, useYn, matchsticks);
					if (ret == true) return true;
				}
				lngs[i] -= matchsticks[idx];
				useYn[idx] = 0;
			}
		}

		return ret;
	}
};

int main_leet060302() {
	Solution st;
	vector<int> matchsticks;

	//matchsticks = {1,1,2,2,2};
	////Output: true / 1
	//cout << st.makesquare(matchsticks) << "\n";
	//cout << "-------------------------\n";

	//matchsticks = { 3,3,3,3,4 };
	////Output: false / 0
	//cout << st.makesquare(matchsticks) << "\n";
	//cout << "-------------------------\n";

	matchsticks = { 5,5,5,5,4,4,4,4,3,3,3,3 };
	//Output: true / 1
	cout << st.makesquare(matchsticks) << "\n";
	cout << "-------------------------\n";

	return 0;
}