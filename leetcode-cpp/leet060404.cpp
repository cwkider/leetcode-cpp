/*
* leet060404.cpp
* Out of Boundary Paths
*/

#include <iostream>

using namespace std;

class Solution {
	int cache[51][51][51];
	int sm, sn, smax;
public:
	int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
		int ret = 0;
		sm = m, sn = n, smax = maxMove;
		for (int i = 0; i < 51; ++i)
			for (int j = 0; j < 51; ++j)
				for (int k = 0; k < 51; ++k)
					cache[i][j][k] = -1;
		int mod = 1000000007;
		ret = (getCnt(startRow, startColumn, 0) % mod);

		return ret;
	}

	int getCnt(int x, int y, int mvcnt) {
		if (mvcnt == smax) return 0;

		int& ret = cache[x][y][mvcnt];
		if (ret > -1) return ret;
		ret = 0;
		int mod = 1000000007;
		// left
		if (x - 1 < 0) ret = (ret + 1) % mod;
		else {
			ret += (getCnt(x - 1, y, mvcnt + 1) % mod);
			ret = ret % mod;
		}
		// right
		if (x + 1 == sm) ret = (ret + 1) % mod;
		else {
			ret += (getCnt(x + 1, y, mvcnt + 1) % mod);
			ret = ret % mod;
		}
		// up
		if (y - 1 < 0) ret = (ret + 1) % mod;
		else {
			ret += (getCnt(x, y - 1, mvcnt + 1) % mod);
			ret = ret % mod;
		}

		// down
		if (y + 1 == sn) ret = (ret + 1) % mod;
		else {
			ret += (getCnt(x, y + 1, mvcnt + 1) % mod);
			ret = ret % mod;
		}

		return ret;
	}
};

int main_leet060404() {
	Solution st;
	int m;
	int n;
	int maxMove;
	int startRow;
	int startColumn;

	m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0;
	//Output: 6
	cout << st.findPaths(m, n, maxMove, startRow, startColumn) << "\n";
	cout << "------------------------------------\n";

	m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1;
	//Output: 12
	cout << st.findPaths(m, n, maxMove, startRow, startColumn) << "\n";
	cout << "------------------------------------\n";

	return 0;
}