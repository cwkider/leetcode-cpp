/*
* leet060205.cpp
* Stone Game VII
*/

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <malloc.h>

using namespace std;

class Solution {
int cache[2][1001][1001];
public:
	int stoneGameVII(vector<int>& stones) {
		int ret = 0;

		//int cache[2][1001][1001];
		//int* cache = (int*)malloc(sizeof(int) * 2*1000*1000);
		for (int i = 0; i < 1001; ++i) {
			for (int j = 0; j < 1001; ++j) {
				cache[0][i][j] = -987654321;
				cache[1][i][j] = -1;
			}
		}
		int lng = stones.size();
		int sum = 0;
		for (int i = 0; i < lng; ++i)
			sum += stones[i];

		int retarr1[2];
		getGap(1, lng - 1, sum - stones[0], 1, stones, retarr1);
		ret = retarr1[0] + sum - stones[0] - retarr1[1];
		//cout << "1 scre[0] : " << scre[0] << " | scre[1] : " << scre[1] << "\n";
		getGap(0, lng - 2, sum - stones[lng - 1], 1, stones, retarr1);
		ret = max(ret, retarr1[0] + sum - stones[lng - 1] - retarr1[1]);
		//cout << "2 scre[0] : " << scre[0] << " | scre[1] : " << scre[1] << "\n";

		return ret;
	}

	void getGap(int l, int r, int sum, int gbn, vector<int>& stones, int retarr1[2]) {
		if (l == r) {
			retarr1[0] = retarr1[1] = 0;
			return;
		}

		//gbn 0 : Alice, 1 : Bob
		if (cache[0][l][r] != -987654321) {
			int gap = cache[1][l][r];
			if (gbn == 0) {
				retarr1[0] = cache[0][l][r];
				retarr1[1] = retarr1[0] - gap;
			}
			else {
				retarr1[1] = cache[0][l][r];
				retarr1[0] = retarr1[1] - gap;
			}
			return;
		}

		//leftmost
		int retarr[2];
		getGap(l + 1, r, sum - stones[l], (gbn + 1) % 2, stones, retarr);
		int aval, bval;
		if (gbn == 0) {
			aval = retarr[0] + sum - stones[l];
			bval = retarr[1];
			cache[0][l][r] = aval;
			cache[1][l][r] = aval - bval;
		}
		else {
			aval = retarr[0];
			bval = retarr[1] + sum - stones[l];
			cache[0][l][r] = bval;
			cache[1][l][r] = bval - aval;
		}
		retarr1[0] = aval;
		retarr1[1] = bval;

		//rightmost
		getGap(l, r - 1, sum - stones[r], (gbn + 1) % 2, stones, retarr);
		int gab2 = 0;
		if (gbn == 0) {
			aval = retarr[0] + sum - stones[r];
			bval = retarr[1];
			gab2 = aval - bval;
		}
		else {
			aval = retarr[0];
			bval = retarr[1] + sum - stones[r];
			gab2 = bval - aval;

		}

		//if (gab2 > cache[1][l][r] || (gab2 == cache[1][l][r] && stones[r] < stones[l])) {
		if (gab2 > cache[1][l][r]) {
			cache[1][l][r] = gab2;
			if (gbn == 0) {
				cache[0][l][r] = aval;
			}
			else {
				cache[0][l][r] = bval;
			}
			retarr1[0] = aval;
			retarr1[1] = bval;
		}

		//cout << "1. ret[0] : " << ret[0] << " | ret[1] : " << ret[1] << "\n";

		return;
	}
};

int main_leet060205() {
	Solution st;
	vector<int> stones;

	stones = { 5,3,1,4,2 };
	// Output: 6
	cout << st.stoneGameVII(stones) << "\n";
	cout << "----------------------------\n";

	stones = { 7,90,5,1,100,10,10,2 };
	// Output: 122
	cout << st.stoneGameVII(stones) << "\n";
	cout << "----------------------------\n";

	stones = { 1,1,1,1,1,1,1,7,7,1,1,1,1,1,1,1 };
	// Output: 14
	cout << st.stoneGameVII(stones) << "\n";
	cout << "----------------------------\n";

	return 0;
}