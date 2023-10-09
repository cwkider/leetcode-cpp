/*
* leetpr00986.cpp
* 986. Interval List Intersections
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
		vector<vector<int>> ret;

		int firstListSize = firstList.size();
		int secondListSize = secondList.size();
		if (firstListSize == 0 || secondListSize == 0) return ret;

		//int** firstList2 = (int**)malloc(sizeof(int*) * firstListSize);
		//for (int i = 0; i < firstListSize; ++i) {
		//	firstList2[i] = (int*)malloc(sizeof(int) * 2);
		//	firstList2[i][0] = firstList[i][0];
		//	firstList2[i][1] = firstList[i][1];
		//}
		int* firstList2[1000];
		for (int i = 0; i < firstListSize; ++i) {
			firstList2[i] = (int*)malloc(sizeof(int) * 2);
			firstList2[i][0] = firstList[i][0];
			firstList2[i][1] = firstList[i][1];
		}
		//for (int i = 0; i < firstListSize; ++i) {
		//	cout << firstList2[i][0] << ", " << firstList2[i][1] << "\n";
		//}

		int* secondList2[1000];
		for (int i = 0; i < secondListSize; ++i) {
			secondList2[i] = (int*)malloc(sizeof(int) * 2);
			secondList2[i][0] = secondList[i][0];
			secondList2[i][1] = secondList[i][1];
		}
		//for (int i = 0; i < secondListSize; ++i) {
		//	cout << secondList2[i][0] << ", " << secondList2[i][1] << "\n";
		//}

		int returnSize = 0;
		int* returnColumnSizes[1000];
		for (int i = 0; i < 1000; ++i)
			returnColumnSizes[i] = (int*)malloc(sizeof(int) * 2);

		intervalIntersection2(firstList2, firstListSize, secondList2, secondListSize, &returnSize, returnColumnSizes);
		//cout << "returnSize : " << returnSize << "\n";

		for (int i = 0; i < returnSize; ++i) {
			vector<int> temp;
			temp.push_back(returnColumnSizes[i][0]);
			temp.push_back(returnColumnSizes[i][1]);
			ret.push_back(temp);
		}

		for (int i = 0; i < firstListSize; ++i)
			free(firstList2[i]);
		//free(firstList2);

		for (int i = 0; i < secondListSize; ++i)
			free(secondList2[i]);
		//free(secondList2);

		return ret;
	}

	int** intervalIntersection2(int** firstList, int firstListSize, int** secondList, int secondListSize, int* returnSize, int** returnColumnSizes) {
		int i = 0, j = 0;
		int firstStart, firstEnd;
		int secondStart, secondEnd;
		while (i < firstListSize || j < secondListSize) {
			//cout << "i : " << i << " | j : " << j << " | returnSize : " << *returnSize << "\n";
			firstStart = firstList[i][0];
			firstEnd = firstList[i][1];
			secondStart = secondList[j][0];
			secondEnd = secondList[j][1];
			if (firstStart > secondEnd) {
				if(j < secondListSize - 1) j++;
				else break;
			}
			else if (secondStart > firstEnd) {
				if(i < firstListSize - 1) i++;
				else break;
			}
			else {
				int start, end;
				start = firstStart;
				if (secondStart > firstStart) start = secondStart;
				end = firstEnd;
				if (secondEnd < firstEnd) end = secondEnd;
				returnColumnSizes[*returnSize][0] = start;
				returnColumnSizes[*returnSize][1] = end;
				(*returnSize)++;

				if (firstEnd <= secondEnd)
					if(i < firstListSize - 1) i++;
					else break;

				if (secondEnd <= firstEnd)
					if(j < secondListSize - 1) j++;
					else break;
			}
		}

		return returnColumnSizes;
	}
};


int main00986() {
	vector<vector<int>> firstList;
	vector<vector<int>> secondList;
	vector<vector<int>> ret;
	Solution st;

	firstList = { {0,2},{5,10},{13,23},{24,25} };
	secondList = { {1,5},{8,12},{15,24},{25,26} };
	ret = st.intervalIntersection(firstList, secondList);
	for (int i = 0; i < ret.size(); ++i) {
		cout << "[" << ret[i][0] << ", " << ret[i][1] << "]";
		if (i < ret.size() - 1) cout << ", ";
	}
	cout << "\n";

	firstList = { {1,3},{5,9} };
	secondList = { };
	ret = st.intervalIntersection(firstList, secondList);
	for (int i = 0; i < ret.size(); ++i) {
		cout << "[" << ret[i][0] << ", " << ret[i][1] << "]";
		if (i < ret.size() - 1) cout << ", ";
	}
	cout << "\n";

	firstList = { {14,16} };
	secondList = { {7, 13}, {16, 20} };
	ret = st.intervalIntersection(firstList, secondList);
	for (int i = 0; i < ret.size(); ++i) {
		cout << "[" << ret[i][0] << ", " << ret[i][1] << "]";
		if (i < ret.size() - 1) cout << ", ";
	}
	cout << "\n";

	firstList = { {1,8}, {16, 20} };
	secondList = { {2, 11}, {12, 13} };
	ret = st.intervalIntersection(firstList, secondList);
	for (int i = 0; i < ret.size(); ++i) {
		cout << "[" << ret[i][0] << ", " << ret[i][1] << "]";
		if (i < ret.size() - 1) cout << ", ";
	}
	cout << "\n";

	return 0;
}