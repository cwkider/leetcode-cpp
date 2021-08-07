/*
* leet060101.cpp
*/

#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		int ret = 0;

		int n = grid.size();
		int m = grid[0].size();
		int sidx = 0, sidy = 0, j = 0, cyn, sum = 0;
		for (int i = 0; i < n; ++i) {
			j = 0;
			cyn = 0;
			sidx = 0;
			sidy = 0;
			sum = 0;
			while (j < m) {
				if (grid[i][j] >= 1 || grid[i][j] == -1) {
					sidy = i;
					sidx = j;
					int j1 = 0, j2 = 0;

					while (j+j1 < m && (grid[i][j+j1] >= 1 || grid[i][j+j1] == -1)) {
						sidy = i;
						sidx = j + j1;
						if (i < n - 1 && (grid[i+1][j+j1] >= 1 || grid[i + 1][j + j1] == -1)) {
							sidy = i + 1;
							sidx = j + j1;
						}
						if(grid[i][j+j1] >= 1) sum += grid[i][j+j1];
						grid[i][j+j1] = -1;
						j2 = 1;
						while ((i+j2) < n && (grid[i+j2][j+j1] >= 1 || grid[i+j2][j+j1] == -1)) {
							if(grid[i+j2][j+j1] >= 1) sum += grid[i+j2][j+j1];
							grid[i+j2][j+j1] = -1;
							j2++;
						}
						//cout << "1> i : " << i << " | j : " << j << " | j1 : " << j1 << " | j 2 : " << j2 << "\n";
						j2 = 1;
						while ((i-j2) > 0 && (grid[i-j2][j+j1] >= 1 || grid[i-j2][j+j1] == -1)) {
							if (grid[i-j2][j+j1] >= 1) sum += grid[i-j2][j+j1];
							grid[i-j2][j+j1] = -1;
							j2++;
						}
						//cout << "1> i : " << i << " | j : " << j << " | j1 : " << j1 << " | j 2 : " << j2 << " | sum : " << sum << "\n";
						j1++;
					}

					ret = max(ret, sum);
					//cout << "1. i : " << i << " | j : " << j << " | sum : " << sum << " | sidy : " << sidy << " | sidx : " << sidx << "\n";
					grid[sidy][sidx] = sum;
					j += j1 - 1;
				}
				else {
					int upv = 0, leftv = 0;
					if (i > 0 && grid[i - 1][j] >= 1) upv = grid[i - 1][j];
					if (j > 0 && grid[i][j-1] >= 1) leftv = grid[i][j - 1];
					sum = upv + leftv;
					ret = max(ret, sum);
				}
				sum = 0;
				j++;
			}
			for (int k = 0; k < m; ++k) {
				cout << grid[i][k] << " ";
			}
			cout << "\n";
		}

		return ret;
	}
};

int main_leet060102() {
	Solution st;
	vector<vector<int>> grid;
	
	grid = { {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}, \
	{0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, { 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0 }, \
	{0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0}, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 }, \
	{0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0} };
	//Output : 6
	cout << st.maxAreaOfIsland(grid) << "\n";
	cout << "--------------------------------\n";

	//grid = { {1,1,1},{1,0,1} };
	////Output : 5
	//cout << st.maxAreaOfIsland(grid) << "\n";
	//cout << "--------------------------------\n";

	//grid = { {0,1,1},{1,1,1} };
	////Output : 5
	//cout << st.maxAreaOfIsland(grid) << "\n";
	//cout << "--------------------------------\n";

	//grid = { {1,0},{1,0},{1,1} };
	////Output : 4
	//cout << st.maxAreaOfIsland(grid) << "\n";
	//cout << "--------------------------------\n";

	//grid = { {1,1,1 }, { 1,0,1 }, { 1,1,0 }};
	////Output : 7
	//cout << st.maxAreaOfIsland(grid) << "\n";
	//cout << "--------------------------------\n";

	return 0;
}