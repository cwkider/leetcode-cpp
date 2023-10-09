/*
* leet060204.cpp
* My Calendar I
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class MyCalendar {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	vector<pair<int, int>> pq2;
public:
	MyCalendar() {

	}

	bool book(int start, int end) {
		int ret = false;
		if (pq.empty()) {
			pq.push({ start, end });
			ret = true;
		}
		else {
			int qstart = pq.top().first;
			int qend = pq.top().second;
			if (end <= qstart) {
				pq.push({ start, end });
				return true;
			}
			pq.pop();
			if (pq.empty()) {
				if (start >= qend) {
					pq.push({ qstart, qend });
					pq.push({ start, end });
					return true;
				}
			}
			pq.push({ qstart, qend });
			int qstart2, qend2;
			while (!pq.empty()) {
				qstart = pq.top().first;
				qend = pq.top().second;
				pq.pop();
				pq2.push_back({ qstart, qend });
				//cout << "qstart : " << qstart << " | qend : " << qend << "\n";
				if (!pq.empty()) {
					qstart2 = pq.top().first;
					qend2 = pq.top().second;
					if (start >= qend && end <= qstart2) {
						pq2.push_back({ start, end });
						ret = true;
						break;
					}
				}
				else {
					if (start >= qend) {
						pq2.push_back({ start, end });
						ret = true;
						break;
					}
				}

				if (start < qend && end > qstart2) {
					ret = false;
					break;
				}
			}

			int lng = pq2.size();
			for(int i = 0; i < lng; ++i) {
				qstart = pq2[i].first;
				qend = pq2[i].second;
				pq.push({ qstart, qend });
			}
			pq2.clear();
		}

		return ret;
	}
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

int main_leet060204() {
	MyCalendar* obj = new MyCalendar();

	obj = new MyCalendar();
	cout << obj->book(10, 20) << "\n"; // returns true
	cout << obj->book(15, 25) << "\n"; // returns false
	cout << obj->book(20, 30) << "\n"; // returns true
	cout << "===========================================\n";

	//["MyCalendar", "book", "book", "book", "book", "book", "book", "book", "book", "book", "book"]
	//[[], [47, 50], [33, 41], [39, 45], [33, 42], [25, 32], [26, 35], [19, 25], [3, 8], [8, 13], [18, 27]]
	//Output : [null,true,true,false,false,true,false,true,true,true,false]
	obj = new MyCalendar();
	cout << obj->book(47, 50) << "\n"; // returns true
	cout << obj->book(33, 41) << "\n"; // returns true
	cout << obj->book(39, 45) << "\n"; // returns false
	cout << obj->book(33, 42) << "\n"; // returns false
	cout << obj->book(25, 32) << "\n"; // returns true
	cout << obj->book(26, 35) << "\n"; // returns false
	cout << obj->book(19, 25) << "\n"; // returns true
	cout << obj->book(3, 8) << "\n"; // returns true
	cout << obj->book(8, 13) << "\n"; // returns true
	cout << obj->book(18, 27) << "\n"; // returns false
	cout << "===========================================\n";

	//[null,true,false,true,true,false,true,false,true
	//[[],[20,29],[13,22],[44,50],[1,7],[2,10],[14,20],[19,25],[36,42]
	obj = new MyCalendar();
	cout << obj->book(20, 29) << "\n"; // returns true
	cout << obj->book(13, 22) << "\n"; // returns false
	cout << obj->book(44, 50) << "\n"; // returns true
	cout << obj->book(1, 7) << "\n"; // returns true
	cout << obj->book(2, 10) << "\n"; // returns false
	cout << obj->book(14, 20) << "\n"; // returns true
	cout << obj->book(19, 25) << "\n"; // returns false
	cout << obj->book(36, 42) << "\n"; // returns true
	cout << "===========================================\n";

	return 0;
}