/*
* leet080106.cpp
* Stone Game
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool stoneGame(vector<int>& piles) {
		return true;
	}
};

int main_leet080106() {
//int main() {
	Solution st;
	vector<int> piles;

	piles = { 5,3,4,5 };
	//Output: true
	cout << st.stoneGame(piles) << endl;

	return 0;
}