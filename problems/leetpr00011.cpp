/*
* leetpr00011.cpp
* 11. Container With Most Water
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		int ret = 0;

		int sz = height.size();
		if (sz == 2) min(height[0], height[1]);

		vector<pair<int, int>> temp;
		for (int i = 0; i < sz; ++i)
			temp.push_back({ height[i], i });

		sort(temp.rbegin(), temp.rend());
		int ht = temp[1].first;
		int widleft = temp[0].second;
		int widright = temp[1].second;
		if (temp[0].second > temp[1].second) {
			widleft = temp[1].second;
			widright = temp[0].second;
		}
		int dist = widright - widleft;
		ret = ht * dist;

		for (int i = 2; i < sz; ++i) {
			if (temp[i].second > widright) {
				widright = temp[i].second;
			}
			else if (temp[i].second < widleft) {
				widleft = temp[i].second;
			}
			ht = temp[i].first;
			dist = widright - widleft;
			ret = max(ret, ht * dist);
		}

		return ret;
	}
};

int main00011() {
	Solution st;
	vector<int> height;
	int ret;

	height = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
	//Output: 49
	ret = st.maxArea(height);
	cout << ret << endl;
	cout << "=======================================\n";

	//height = { 1, 1 };
	////Output: 1
	//ret = st.maxArea(height);
	//cout << ret << endl;
	//cout << "=======================================\n";

	//height = { 3, 2, 1, 3 };
	////Output: 9
	//ret = st.maxArea(height);
	//cout << ret << endl;
	//cout << "=======================================\n";

	//height = { 10,14,10,4,10,2,6,1,6,12 };
	////Output: 96
	//ret = st.maxArea(height);
	//cout << ret << endl;
	//cout << "=======================================\n";

	//height = { 1,0,0,0,0,0,0,2,2 };
	////Output: 8
	//ret = st.maxArea(height);
	//cout << ret << endl;
	//cout << "=======================================\n";

	//height = { 10,9,8,7,6,5,4,3,2,1 };
	////Output: 25
	//ret = st.maxArea(height);
	//cout << ret << endl;
	//cout << "=======================================\n";

	//height = { 8,10,14,0,13,10,9,9,11,11 };
	////Output: 80
	//ret = st.maxArea(height);
	//cout << ret << endl;
	//cout << "=======================================\n";

	//height = { 75,21,3,152,13,107,163,166,32,160,41,131,7,67,56,5,153,176,29,139,61,149,176,142,64,75,170,156,73,48,148,101,70,103,53,83,11,168,1,195,81,43,126,88,62,134,45,167,63,26,107,124,128,83,67,192,158,189,149,184,37,49,85,107,152,90,143,115,58,144,62,139,139,189,180,153,75,177,121,138,4,28,15,132,63,82,124,174,23,25,110,60,74,147,120,179,37,63,94,47 };
	////Output: 14608
	//ret = st.maxArea(height);
	//cout << ret << endl;
	//cout << "=======================================\n";

	return 0;
}
