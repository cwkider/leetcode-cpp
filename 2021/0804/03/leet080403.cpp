/*
* leet080403.cpp
* Two Sum IV - Input is a BST
*/
#include <iostream>
#include <map>
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

static TreeNode* setTreeNode(vector<int>& nums, int skipnum) {
	TreeNode* ret;

	vector<TreeNode*> vtn;
	int lng = nums.size();

	ret = new TreeNode(nums[0]);
	vtn.push_back(ret);
	int i = 1;
	int j = 0;
	int lng2 = vtn.size();
	vector<TreeNode*> vtn2;
	while (i < lng) {
		if (j < lng2) {
			if (nums[i] != skipnum) {
				TreeNode* tn = new TreeNode(nums[i]);
				vtn2.push_back(tn);
				vtn[j]->left = tn;
			}
			else {
				vtn[j]->left = NULL;
			}
			i++;
			if (i < lng) {
				if (nums[i] != skipnum) {
					TreeNode* tn = new TreeNode(nums[i]);
					vtn2.push_back(tn);
					vtn[j]->right = tn;
				}
				else {
					vtn[j]->right = NULL;
				}
				i++;
			}
			j++;
		}
		else {
			j = 0;
			vtn.clear();
			int vtn2lng = vtn2.size();
			vtn.assign(vtn2lng, 0);
			copy(vtn2.begin(), vtn2.end(), vtn.begin());
			lng2 = vtn.size();
			vtn2.clear();
			vtn2.assign(0, 0);
		}
	}
	return ret;
}

static void printTreeNode(TreeNode* root) {
	vector<TreeNode*> vtn;
	vtn.push_back(root);
	vector<TreeNode*> vtn2;
	int i = 0;
	int lng = vtn.size();
	while (lng > 0) {
		if (i < lng) {
			cout << vtn[i]->val << " ";
			if (vtn[i]->left != NULL) {
				vtn2.push_back(vtn[i]->left);
			}
			if (vtn[i]->right != NULL) {
				vtn2.push_back(vtn[i]->right);
			}
			++i;
		}
		else {
			vtn.clear();
			int vtn2lng = vtn2.size();
			vtn.assign(vtn2lng, 0);
			copy(vtn2.begin(), vtn2.end(), vtn.begin());
			vtn2.clear();
			vtn2.assign(0, 0);
			i = 0;
		}
	}

}

class Solution {
	int fk;
	map<int, int> mp;
public:
	bool findTarget(TreeNode* root, int k) {
		fk = k;
		int findnum = fk - root->val;
		mp.insert({ findnum, 1 });

		bool ret = false;
		if (root->left != NULL) ret = findSum(root->left);
		if (ret) return ret;
		if (root->right != NULL) ret = findSum(root->right);
		if (ret) return ret;
		if (root->left != NULL) ret = findSum(root->left);
		if (ret) return ret;
		if (root->right != NULL) ret = findSum(root->right);

		return ret;
	}

	bool findSum(TreeNode* node) {
		map<int, int>::iterator it;
		int findnum = fk - node->val;
		mp.insert({ findnum, 1 });
		it = mp.find(node->val);
		if (it != mp.end()) {
			if (findnum == node->val) {
				if ((node->left != NULL && node->left->val == findnum) || (node->right != NULL && node->right->val == findnum))
					return true;
			} else
			return true;
		}
		if (node->left == NULL && node->right == NULL) return false;
		if (node->left != NULL) {
			if (findSum(node->left)) return true;
		}
		if (node->right != NULL) {
			if (findSum(node->right)) return true;
		}

		return false;
	}
};


int main_leet080403() {

	return 0;
}