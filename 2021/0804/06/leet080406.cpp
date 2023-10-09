/*
* leet080406.cpp
* Verify Preorder Serialization of a Binary Tree
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
	string val;
	TreeNode* left;
	TreeNode* right;
};

class Solution {
	int idx;
	int lng;
	//string str;
public:
	bool isValidSerialization(string preorder) {
		bool ret = false;

		//cout << "preorder : " << preorder << "\n";
		lng = preorder.size() - 1;
		idx = 0;


		
		TreeNode* root = new TreeNode();
		ret = makeTreeNode(root, preorder);
		//cout << "1 lng : " << lng << " | idx : " << idx << "\n";
		if (ret) {
			if (idx == lng + 1) ret = true;
			else ret = false;
		}
		return ret;
	}

	bool makeTreeNode(TreeNode* node, string& str) {
		//cout << "str[0] : " << str[0] << endl;
		//cout << "lng : " << lng << " | idx : " << idx << "\n";
		bool ret = false;
		if (idx > lng) return false;

		if (str[idx] == ',') {
			idx++;
			if (idx > lng) return false;
		}

		string val = "";
		while (str[idx] != ',' && idx <= lng) {
			val += str[idx];
			idx++;
		}
		
		if (val[0] == '#') return true;
		else {
			node->left = new TreeNode();
			ret = makeTreeNode(node->left, str);
			if (ret) {
				node->right = new TreeNode();
				ret = makeTreeNode(node->right, str);
			}
		}

		return ret;
	}
};

int main_leet080406() {
//int main() {
	Solution st;
	string preorder;

	preorder = "9,3,4,#,#,1,#,#,2,#,6,#,#";
	//Output: true"
	cout << st.isValidSerialization(preorder) << "\n";
	cout << "---------------------------------\n";

	preorder = "1,#";
	//Output: false"
	cout << st.isValidSerialization(preorder) << "\n";
	cout << "---------------------------------\n";

	preorder = "9,#,#,1";
	//Output: false"
	cout << st.isValidSerialization(preorder) << "\n";
	cout << "---------------------------------\n";
	
	return 0;
}