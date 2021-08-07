/*
* leet060306.cpp
* K Inverse Pairs Array
*/

#include <iostream>

using namespace std;

class Solution {
	int cache[1001][1001];
	int md = 1000000007;
public:
	int kInversePairs(int n, int k) {
		int ret = 0;

		if (k == 0) return 1;
		if (k == 1) return n - 1;
		else if (k == n) return 1;
		else {
			ret = (n - k) * 2;
		}

		//for (int i = 0; i < 1001; ++i)
		//	for (int j = 0; j < 1001; ++j)
		//		cache[i][j] = -1;

		//ret = cntPair(1, n, k) % md;


		return ret;
	}

	int cntPair(int idx, int n, int k) {
		if (idx >= n) return 0;
		if (idx == n - 1) {
			if (k == 1) return 1;
			else return 0;
		}

		int& ret = cache[idx][k];
		if (ret != -1) return ret;

		ret = 0;
		int ret1, ret2;
		if (k == 1) ret = 1;
		else {
			ret1 = cntPair(idx + 1, n, k - 1);
			ret = ret1 % md;
		}

		ret2 = cntPair(idx + 1, n, k);
		ret += ret2 % md;

		return ret;
	}
};

int main_leet060306() {
	Solution st;
	int n, k;

	n = 3;
	k = 0;
	//Output: 1
	cout << st.kInversePairs(n, k) << "\n";
	cout << "-------------------------\n";

	n = 3;
	k = 1;
	//Output: 2
	cout << st.kInversePairs(n, k) << "\n";
	cout << "-------------------------\n";

	n = 3;
	k = 2;
	//Output: 2
	cout << st.kInversePairs(n, k) << "\n";
	cout << "-------------------------\n";

	return 0;
}