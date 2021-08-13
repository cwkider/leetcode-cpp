/*
* leet050205.cpp
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxScore(vector<int>& cardPoints, int k) {
		int ret = 0;

		for (int i = 0; i < k; ++i) {
			ret += cardPoints[i];
		}
		int lng = cardPoints.size();

		int ret2 = ret;
		for (int i = lng - 1; i >= lng - k; --i) {
			ret2 = ret2 - cardPoints[k - 1 - lng + 1 + i] + cardPoints[i];
			ret = max(ret, ret2);
		}

		return ret;

	}
};

int main_leet050205() {
	vector<int> cardPoints;
	int k;
	Solution st;

	cardPoints.clear();
	cardPoints = { 1,2,3,4,5,6,1 };
	k = 3;
	// Output : 12
	cout << st.maxScore(cardPoints, k) << "\n";
	cout << "------------------------" << "\n";

	cardPoints.clear();
	cardPoints = {2,2,2};
	k = 2;
	// Output : 4
	cout << st.maxScore(cardPoints, k) << "\n";
	cout << "------------------------" << "\n";

	cardPoints.clear();
	cardPoints = { 9,7,7,9,7,7,9 };
	k = 7;
	// Output : 55
	cout << st.maxScore(cardPoints, k) << "\n";
	cout << "------------------------" << "\n";

	cardPoints.clear();
	cardPoints = { 1,1000,1 };
	k = 1;
	// Output : 1
	cout << st.maxScore(cardPoints, k) << "\n";
	cout << "------------------------" << "\n";

	cardPoints.clear();
	cardPoints = { 1,79,80,1,1,1,200,1 };
	k = 3;
	// Output : 202
	cout << st.maxScore(cardPoints, k) << "\n";
	cout << "------------------------" << "\n";

	return 0;
}
