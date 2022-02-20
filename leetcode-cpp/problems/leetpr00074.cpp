/*
* leetpr00074.cpp
* 74. Search a 2D Matrix
*/
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		bool ret = false;
		int len1 = matrix.size();
		int len2 = matrix[0].size();

		int low, high, mid, col;
		low = 0;
		high = matrix.size() - 1;
		col = 0;
		while (matrix.size() > 1 && low <= high) {
			mid = (low + high) / 2;
			if (matrix[mid][0] == target) return true;

			if (target > matrix[mid][0]) {
				if (mid == len1 - 1) {
					col = mid;
					break;
				}
				if (target < matrix[mid + 1][0]) {
					col = mid;
					break;
				}
				else {
					low = mid + 1;
				}
			}
			else {
				if (mid == 0) {
					col = mid;
					break;
				}
				if (target > matrix[mid - 1][0]) {
					col = mid - 1;
					break;
				}
				else {
					high = mid - 1;
				}
			}
		}

		cout << "col :" << col << endl;

		low = 0;
		high = matrix[col].size() - 1;

		if (high == 0) {
			if (target == matrix[col][0]) return true;
			else return false;
		}

		while (low <= high) {
			mid = (low + high) / 2;
			if (matrix[col][mid] == target) {
				return true;
			}

			if (target > matrix[col][mid]) low = mid + 1;
			else high = mid - 1;
		}

		return ret;
	}
};