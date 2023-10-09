/*
* leet070304.cpp
* Three Equal Parts
* Not Completed
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> threeEqualParts(vector<int>& arr) {
		vector<int> ret;

		int i = -1, j = -1;
		int val1 = 0, val2 = 0, val3 = 0;
		int tn1 = 0, tn2 = 0, tn3 = 0;

		int asz = arr.size();
		while (i < asz - 3) {
			++i;
			val1 = 2 * val1 + i;

			j = i;
			while (j < asz - 2 && val2 < val1) {
				j++;
				
			}

		}




		return ret;
	}
};

int main_leet070304() {
	Solution st;
	vector<int> arr;
	vector<int> ret;

	arr = { 1, 0, 1, 0, 1 };
	//Output: [0,3]
	ret = st.threeEqualParts(arr);
	cout << ret[0] << " " << ret[1] << "\n";
	cout << "--------------------------------------\n";

	return 0;
}