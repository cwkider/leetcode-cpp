/*
* leet080105.cpp
* Path Sum II
*/

#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
	int tSum;
public:
	vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
		tSum = targetSum;
		vector<vector<int>> ret;
		if (root == NULL) return ret;
		ret = recPathSum(root, 0);

		return ret;
	}

	vector<vector<int>> recPathSum(TreeNode* node, int subSum) {
		vector<vector<int>> ret;
		if (node->left == NULL && node->right == NULL) {
			if (subSum + node->val == tSum) {
				vector<int> subret;
				subret.push_back(node->val);
				ret.push_back(subret);
				return ret;
			}
			else {
				return ret;
			}
		}

		subSum += node->val;
		vector<vector<int>> tempRet;
		if (node->left != NULL) {
			tempRet = recPathSum(node->left, subSum);
			int sz = tempRet.size();
			vector<int> tempSub;
			for (int i = 0; i < sz; ++i) {
				tempSub = tempRet[i];
				tempSub.insert(tempSub.begin(), node->val);
				ret.push_back(tempSub);
			}
		}

		if (node->right != NULL) {
			tempRet = recPathSum(node->right, subSum);
			int sz = tempRet.size();
			vector<int> tempSub;
			for (int i = 0; i < sz; ++i) {
				tempSub = tempRet[i];
				tempSub.insert(tempSub.begin(), node->val);
				ret.push_back(tempSub);
			}
		}

		return ret;
	}

};

int main_leet080105() {
	cout << "hello git hub!" << endl;

	return 0;
}