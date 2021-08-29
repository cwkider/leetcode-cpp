/*
* leet080307.cpp
* Valid Sudoku
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
	int crow[9][9];
	int ccol[9][9];
	int csub[9][9];
	
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		bool ret = true;

		for (int i = 0; i < 9; ++i) {
			memset(crow[i], 0, sizeof(int) * 9);
			memset(ccol[i], 0, sizeof(int) * 9);
			memset(csub[i], 0, sizeof(int) * 9);
		}

		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				if (board[i][j] != '.') {
					int val = board[i][j] - '0' - 1;
					if (!checkPossible(i, j, val)) return false;
				}
			}
		}

		return ret;
	}

	bool checkPossible(int i, int j, int val) {
		int ret = true;

		if (crow[i][val] == 1) return false;
		if (ccol[j][val] == 1) return false;
		int sidx = (i / 3) * 3 + (j / 3);
		if (csub[sidx][val] == 1) return false;

		crow[i][val] = 1;
		ccol[j][val] = 1;
		csub[sidx][val] = 1;

		return ret;
	}


	bool checkPosition(vector<pair<int, int>>& dots, int idx) {
		int sz = dots.size();
		int i = dots[idx].first;
		int j = dots[idx].second;
		int sidx = (i / 3) * 3 + (j / 3);
		if (idx == sz - 1) {
			for (int v = 1; v <= 9; ++v) {
				int val = v - 1;
				if (checkPossible(i, j, val)) return true;
				crow[i][val] = 0;
				ccol[j][val] = 0;
				csub[sidx][val] = 0;
			}
			return false;
		}
		bool ret = false;

		for (int v = 1; v <= 9; ++v) {
			int val = v - 1;
			if (checkPossible(i, j, val)) {
				ret = checkPosition(dots, idx + 1);
				if (ret) break;
				crow[i][val] = 0;
				ccol[j][val] = 0;
				csub[sidx][val] = 0;
			}
		}

		return ret;
	}

};

int main_leet080307() {
	Solution st;
	vector<vector<char>> board;

	board = { {'5','3','.','.','7','.','.','.','.'}
,{'6','.','.','1','9','5','.','.','.'}
,{'.','9','8','.','.','.','.','6','.'}
,{'8','.','.','.','6','.','.','.','3'}
,{'4','.','.','8','.','3','.','.','1'}
,{'7','.','.','.','2','.','.','.','6'}
,{'.','6','.','.','.','.','2','8','.'}
,{'.','.','.','4','1','9','.','.','5'}
,{'.','.','.','.','8','.','.','7','9'} };
	//Output: true
	cout << st.isValidSudoku(board) << "\n";
	cout << "------------------------------\n";

	board = { {'8', '3', '.', '.', '7', '.', '.', '.', '.'}
	, { '6','.','.','1','9','5','.','.','.' }
		, { '.','9','8','.','.','.','.','6','.' }
		, { '8','.','.','.','6','.','.','.','3' }
		, { '4','.','.','8','.','3','.','.','1' }
		, { '7','.','.','.','2','.','.','.','6' }
		, { '.','6','.','.','.','.','2','8','.' }
		, { '.','.','.','4','1','9','.','.','5' }
		, { '.','.','.','.','8','.','.','7','9' } };
	//Output: false
	cout << st.isValidSudoku(board) << "\n";
	cout << "------------------------------\n";

	board = { {'.','8','7','6','5','4','3','2','1'}
	,{'2','.','.','.','.','.','.','.','.'}
	,{'3','.','.','.','.','.','.','.','.'}
	,{'4','.','.','.','.','.','.','.','.'}
	,{'5','.','.','.','.','.','.','.','.'}
	,{'6','.','.','.','.','.','.','.','.'}
	,{'7','.','.','.','.','.','.','.','.'}
	,{'8','.','.','.','.','.','.','.','.'}
	,{'9','.','.','.','.','.','.','.','.'} };
	//Output: true
	cout << st.isValidSudoku(board) << "\n";
	cout << "------------------------------\n";

	return 0;
}