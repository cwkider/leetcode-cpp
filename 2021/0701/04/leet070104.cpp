/*
* leet070104.cpp
* Max Sum of Rectangle No Larger Than K
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
	int cache[101][101];
public:
	int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
		int ret = -999;

		for (int i = 0; i < 101; ++i)
			for (int j = 0; j < 101; ++j)
				cache[i][j] = -999;

		int m = matrix.size();
		int n = matrix[0].size();

		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				for (int p = i; p < m; ++p) {
					for (int q = j; q < n; ++q) {
						if (p == i && q == j) continue;
						//if(p == i) cache[]
					}
				}
			}
		}

		return ret;
	}
};

int main_leet070104() {
	Solution st;
	vector<vector<int>> matrix;
	int k;

	matrix = { {1, 0, 1}, {0, -2, 3} };
	k = 2;
	// Output: 2
	cout << st.maxSumSubmatrix(matrix, k) << "\n";
	cout << "----------------------------------------\n";

	return 0;
}