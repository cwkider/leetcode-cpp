/**
* leet060108.cpp
* Min Cost Climbing Stairs
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
	int minCostClimbingStairs(vector<int>& cost) {
		int ret = 987654321;

		int cache[1000];
		for (int i = 0; i < 1000; ++i) cache[i] = -1;

		// start 0
		ret = getMinCostForNow(0, cost, cache);
		// start 1
		ret = min(ret, getMinCostForNow(1, cost, cache));

		return ret;
	}

	int getMinCostForNow(int now, vector<int>& cost, int cache[]) {
		int sz = cost.size();
		if (now == sz) return 0;

		int& ret = cache[now];
		if (ret != -1) return ret;
		ret = 987654321;

		//climb one
		if (now <= sz - 1) ret = getMinCostForNow(now + 1, cost, cache) + cost[now];
		//climb two
		if(now <= sz - 2) ret = min(ret, getMinCostForNow(now + 2, cost, cache) + cost[now]);

		return ret;
	}
};

int main_leet060108() {
	Solution st;
	vector<int> cost;

	cost = { 10, 15, 20 };
	//Output: 15
	cout << st.minCostClimbingStairs(cost) << "\n";
	cout << "----------------------------------\n";

	cost = { 1,100,1,1,1,100,1,1,100,1 };
	//Output: 6
	cout << st.minCostClimbingStairs(cost) << "\n";
	cout << "----------------------------------\n";

	return 0;
}