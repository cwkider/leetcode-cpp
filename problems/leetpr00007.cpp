/*
* leetpr00007.cpp
* 7. Reverse Integer
*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
	int reverse(int x) {
		int ret = 0;
		int quot = 1;
		int remain = 0;

		vector<int> pos;
		int mux = 1;
		if (x < 0) mux = -1;
		int lng = 0;
		while (quot != 0) {
			quot = x / 10;
			remain = x % 10;
			pos.push_back(remain);
			x = quot;
			lng++;
			//cout << "quot : " << quot << " | x : " << x << " | remain: " << remain << " | lng : " << lng << endl;
		}

		int k = 1;
		int poscheck = 147483647;
		int negcheck = -147483648;
		              //147483651 
		for (int i = lng - 1; i >= 0; --i) {
			//cout << pos[i] << endl;
			if (k > 1000000000) {
				ret = 0;
				break;
			} else if(k == 1000000000) {
				if (pos[i] >= 3 || pos[i] <= -3) {
					ret = 0;
					break;
				}
				else if (pos[i] == 2 || pos[i] == -2) {
					if (ret > poscheck || ret < negcheck) {
						ret = 0;
						break;
					}
				}
			}
			ret = ret + (pos[i] * k);

			if (k >= 1000000000) break;
			k = k * 10;
		}

		return ret;
	}
};

int main00007() {
	Solution st;
	int x;

	x = 123;
	//Output : 321
	cout << "output : " <<  st.reverse(x) << endl;
	cout << "=======================================\n";

	x = -123;
	//Output : -321
	cout << "output : " << st.reverse(x) << endl;
	cout << "=======================================\n";

	x = 120;
	//Output : 21
	cout << "output : " << st.reverse(x) << endl;
	cout << "=======================================\n";
	return 0;
}