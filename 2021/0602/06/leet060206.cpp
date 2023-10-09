/*
* leet060206.cpp
* Minimum Number of Refueling Stops
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
//static int cache[500][1000000000];
		int cache[501];
public:
	int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
		int ret = -1;
		int lng = stations.size();
		if (startFuel >= target) return 0;

		for (int i = 0; i < 501; ++i) cache[i] = -987654321;

		ret = getMinNum(-1, startFuel, target, stations);

		if (ret == 999) ret = -1;

		return ret;
	}

	int getMinNum(int now, int remain, int target, vector<vector<int>>& stations) {
		
		int lng = stations.size();
		long long total = remain;
		if(now >= 0) total += stations[now][0];
		//if(now >= 0) total = stations[now][0];
		if (now > -1 && now <= lng - 1) {
			//cout << "total : " << total << " | target : " << target << "\n";
			if (total >= target) return 0;
			else if(now == lng - 1) return 999;
		}

		int idx = now;
		if (now == -1) idx = 0;
		int ret = cache[idx];
		if (now != -1 && ret != -987654321) return ret;
		ret = 999;

		for (int i = now + 1; i < lng; ++i) {
			if (total >= stations[i][0]) {
				ret = min(ret, getMinNum(i, stations[i][1], target, stations) + 1);
				//ret = min(ret, getMinNum(i, total - stations[i][0] + stations[i][1], target, stations) + 1);
			}
			else {
				break;
			}
		}

		if (now != -1) cache[now] = ret;

		return ret;
	}
};

int main_leet060206() {
	Solution st;
	int target, startFuel;
	vector<vector<int>> stations;

	target = 1, startFuel = 1;
	stations = {};
	//Output: 0
	cout << st.minRefuelStops(target, startFuel, stations) << "\n";
	cout << "--------------------------------\n";

	target = 100, startFuel = 1, stations = { {10, 100} };
	//Output: -1
	cout << st.minRefuelStops(target, startFuel, stations) << "\n";
	cout << "--------------------------------\n";

	target = 100, startFuel = 10, stations = { {10, 60},{20, 30},{30, 30},{60, 40} };
	//Output: 2
	cout << st.minRefuelStops(target, startFuel, stations) << "\n";
	cout << "--------------------------------\n";

	target = 100, startFuel = 50, stations = { {50, 50} };
	//Output: 1
	cout << st.minRefuelStops(target, startFuel, stations) << "\n";
	cout << "--------------------------------\n";

	target = 100, startFuel = 25, stations = { {25,25},{50,25},{75,25} };
	//Output: 3
	cout << st.minRefuelStops(target, startFuel, stations) << "\n";
	cout << "--------------------------------\n";

	target = 100, startFuel = 10, stations = { {10,60},{20,30},{60,60} };
	//Output: 2
	cout << st.minRefuelStops(target, startFuel, stations) << "\n";
	cout << "--------------------------------\n";

	return 0;
}