/*
* leet050501.cpp
*/

#include <iostream>
#include <cmath>
#include <vector>

#define CACHE_SIZE (int)pow(2, 9);

using namespace std;

class Solution {
public:
	int totalNQueens(int n) {
		int ret = 1;

		vector<vector<int>> board;

		for (int i = 0; i < n; ++i) {
			vector<int> temp(n, 0);
			board.push_back(temp);
		}

		ret = getCase(0, n, board);

		return ret;
	}


	bool checkPossible(vector<vector<int>>& board, const int row, const int col, const int n) {
		bool ret = true;

		int checkrow = row - 1;
		int checkcol = col - 1;
		while (checkrow >= 0 && checkcol >= 0) {
			if (board[checkrow][checkcol] == 1) return false;
			checkrow--;
			checkcol--;
		}
		checkrow = row - 1;
		checkcol = col;
		while (checkrow >= 0) {
			if (board[checkrow][checkcol] == 1) return false;
			checkrow--;
		}
		checkrow = row - 1;
		checkcol = col + 1;
		while (checkrow >= 0 && checkcol <= n - 1) {
			if (board[checkrow][checkcol] == 1) return false;
			checkrow--;
			checkcol++;
		}

		return ret;
	}

	int getCase(const int row, const int n, vector<vector<int>>& board) {
		int ret = 0;

		if (row >= n) {
			//cout << "Success !\n";
			return 1;
		}

		for (int i = 0; i < n; ++i) {
			if (checkPossible(board, row, i, n)) {
				board[row][i] = 1;
				ret += getCase(row + 1, n, board);
				board[row][i] = 0;
			}
		}

		return ret;
	}

};

int main_leet050501() {
	Solution st;
	int n;

	n = 4;
	// Output: 2
	cout << st.totalNQueens(n) << "\n";
	cout << "----------------------------\n";


	n = 9;
	// Output: 2
	cout << st.totalNQueens(n) << "\n";
	cout << "----------------------------\n";

	return 0;
}