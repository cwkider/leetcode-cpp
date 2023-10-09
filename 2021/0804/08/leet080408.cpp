/*
* leet080408.cpp
* Maximum Profit in Job Scheduling
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <malloc.h>

using namespace std;

class Solution {
	int* cache;
	int lng;
public:
	//Solution() {}
	int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
		int ret = 0;
		cache = (int*)malloc(sizeof(int) * 50000);
		memset(cache, 0, sizeof(int) * 50000);
		lng = startTime.size();
		vector<pair<int, pair<int, int>>> sorted;
		for (int i = 0; i < lng; ++i)
			sorted.push_back({ startTime[i], {endTime[i], profit[i]} });
		
		sort(sorted.begin(), sorted.end());

		for (int i = 0; i < lng; ++i) {
			startTime[i] = sorted[i].first;
			endTime[i] = sorted[i].second.first;
			profit[i] = sorted[i].second.second;
		}

		ret = getMaxAtIdx(startTime, endTime, profit, 0);

		free(cache);

		return ret;
	}

	int getMaxAtIdx(vector<int>& startTime, vector<int>& endTime, vector<int>& profit, int idx) {
		if (idx == lng - 1) return profit[idx];

		int& ret = cache[idx];
		if (ret != 0) return ret;
		ret = 0;
		ret = profit[idx];
		int nextIdx = -1;
		for (int i = idx + 1; i < lng; ++i) {
			if (startTime[i] >= endTime[idx]) {
				nextIdx = i;
				break;
			}
		}
		if (nextIdx != -1) ret += getMaxAtIdx(startTime, endTime, profit, nextIdx);

		ret = max(ret, getMaxAtIdx(startTime, endTime, profit, idx + 1));


		return ret;
	}
};

int main_leet080408() {
//int main() {
	Solution st;
	vector<int> startTime;
	vector<int> endTime;
	vector<int> profit;

	startTime = { 1, 2, 3, 3 };
	endTime = { 3, 4, 5, 6 };
	profit = { 50, 10, 40, 70 };
	//Output: 120
	cout << st.jobScheduling(startTime, endTime, profit) << "\n";
	cout << "-------------------------------\n";

	startTime = { 1,2,3,4,6 };
	endTime = { 3,5,10,6,9 };
	profit = { 20,20,100,70,60 };
	//Output: 150
	cout << st.jobScheduling(startTime, endTime, profit) << "\n";
	cout << "-------------------------------\n";

	startTime = { 1,1,1 };
	endTime = { 2,3,4 };
	profit = { 5,6,4 };
	//Output: 6
	cout << st.jobScheduling(startTime, endTime, profit) << "\n";
	cout << "-------------------------------\n";

	startTime = { 6,15,7,11,1,3,16,2 };
	endTime = { 19,18,19,16,10,8,19,8 };
	profit = { 2,9,1,19,5,7,3,19 };
	//Output: 41
	cout << st.jobScheduling(startTime, endTime, profit) << "\n";
	cout << "-------------------------------\n";

	return 0;
}