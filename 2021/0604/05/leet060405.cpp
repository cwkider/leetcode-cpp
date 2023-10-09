/*
* leet060405.cpp
* Redundant Connection
*/

#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

class Solution {
	vector<vector<int>> adjs;
public:
	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		vector<int> ret;
		adjs.clear();
		for (int i = 0; i < 1001; ++i) {
			vector<int> temp;
			adjs.push_back(temp);
		}

		int lng = edges.size();
		int a, b;
		vector<int> level;
		int lng3;
		vector<int> frontier;
		for (int i = 0; i < lng; ++i) {
			a = edges[i][0];
			b = edges[i][1];
			level.clear();
			level.resize(1001);
			fill(level.begin(), level.end(), 0);
			lng3 = adjs[a].size();
			frontier.resize(lng3);
			copy(adjs[a].begin(), adjs[a].end(), frontier.begin());
			level[a] = 1;

			//cout << "1 a : " << a << " | b : " << b << " | lng3 : " << lng3 << "\n";
			while (lng3 > 0) {
				vector<int> temp;
				for (int j = 0; j < lng3; ++j) {
					//cout << "j : " << j << " | frontier[j] : " << frontier[j] << " ";
					if (frontier[j] != b && level[frontier[j]] == 0) {
						level[frontier[j]] = 1;
						int lng2 = adjs[frontier[j]].size();
						for (int k = 0; k < lng2; ++k) {
							temp.push_back(adjs[frontier[j]][k]);
						}
					}
					else {
						if (frontier[j] == b) {
							ret.push_back(a);
							ret.push_back(b);
							return ret;
						}
					}
					//cout << "\n";
				}
				//frontier.clear();
				lng3 = temp.size();
				frontier.resize(lng3);
				copy(temp.begin(), temp.end(), frontier.begin());
				//frontier = temp;
				lng3 = frontier.size();
			}
			adjs[a].push_back(b);
			adjs[b].push_back(a);
		}

		return ret;
	}
};

int main_leet060405() {
	Solution st;
	vector<vector<int>> edges;
	vector<int> ret;

	edges = { {1,2},{1,3},{2,3} };
	//Output: [2,3]
	ret = st.findRedundantConnection(edges);
	cout << "{" << ret[0] << ", " << ret[1] << "}\n";
	cout << "------------------------------------------\n";

	edges = { {1,2},{2,3},{3,4},{1,4},{1,5} };
	//Output: [1,4]
	ret = st.findRedundantConnection(edges);
	cout << "{" << ret[0] << ", " << ret[1] << "}\n";
	cout << "------------------------------------------\n";

	edges = { {1,2},{2,3},{1,5},{3,4},{1,4} };
	//Output: [1,4]
	ret = st.findRedundantConnection(edges);
	cout << "{" << ret[0] << ", " << ret[1] << "}\n";
	cout << "------------------------------------------\n";

	return 0;
}