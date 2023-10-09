/*
* leet090406.cpp
* Transform to Chessboard
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int movesToChessboard(vector<vector<int>>& board) {
		int ret = 0;

		int n = board[0].size();
		for (int i = 0; i < n - 1; ++i) {
			// col check & move
			for (int j = 0; j < n - 1; ++j) {
				if (board[i][j] == board[i][j + 1]) {
					for (int k = 0; k < n; ++k) {

					}
				}
			}

		}
	}

	void changeCol(int a, int b, vector<vector<int>>& board) {
		int n = board[0].size();
		int temp;
		for (int i = 0; i < n; ++i) {
			temp = board[i][b];
			board[i][b] = board[i][a];
			board[i][a] = temp;
		}
	}

	void changeRol(int a, int b, vector<vector<int>>& board) {
		int n = board[0].size();
		vector<int> temp(n, 0);

		copy(board[a].begin(), board[a].end(), temp.begin());
		copy(board[b].begin(), board[b].end(), board[a].begin());
		copy(temp.begin(), temp.end(), board[b].begin());
	}

	bool checkRowForCmove(vector<vector<int>>& board) {
		int n = board[0].size();
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n - 1; ++j) {
				if (board[i][j] == board[i][j+1]) return false;
			}
		}

		return true;
	}

	bool checkColForRmove(vector<vector<int>>& board) {
		int n = board[0].size();
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n - 1; ++j) {
				if (board[j][i] == board[j+1][i]) return false;
			}
		}

		return true;
	}
};

int main090406(){
	Solution st;
	vector<vector<int>> board;

	return 0;
}