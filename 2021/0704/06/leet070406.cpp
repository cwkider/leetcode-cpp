/*
* leet070406.cpp
* Convert Sorted Array to Binary Search Tree
* Not Completed.
*/

#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 **/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {

	}

	void setLeftChildren(TreeNode* now, int left, int right, vector<int>& nums) {
		int nval = now->val;

		int vleft = 0;
		int vright = 0;
		TreeNode* lchild = new TreeNode();
		TreeNode* rchild = new TreeNode();
		if (left == right) {
			vleft = nums[left];
			lchild->val = vleft;
			now->left = lchild;
			return;
		}
		int mid = (left + right) / 2;
	}
};

int main_leet070406() {
	Solution st;
	vector<int> nums;

	nums = { -10, -3, 0, 5, 9 };
	//Output: [0, -3, 9, -10, null, 5]

	return 0;
}