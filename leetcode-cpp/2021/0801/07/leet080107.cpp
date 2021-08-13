/*
* leet080107.cpp
* N-ary Tree Level Order Traversal
*/

#include <iostream>
#include <vector>

using namespace std;

// Definition for a Node.
class Node {
public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val) {
		val = _val;
	}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};

class Solution {
public:
	vector<vector<int>> levelOrder(Node* root) {
		vector<Node*> *ndar;
		vector<Node*> ndar0;
		vector<Node*> ndar1;
		ndar0.clear();
		ndar1.clear();
		vector<vector<int>> ret;

		if (root == NULL) return ret;

		int ndnum = 0;
		ndar0.push_back(root);
		ndar = &ndar0;
		int ndarsz = ndar->size();
		while (ndarsz > 0) {
			vector<int> ret01;
			for (int i = 0; i < ndarsz; ++i) {
				ret01.push_back(ndar->at(i)->val);
				int childsz = ndar->at(i)->children.size();
				if (childsz > 0) {
					for (int j = 0; j < childsz; ++j) {
						if (ndnum == 0) {
							ndar1.push_back(ndar->at(i)->children[j]);
						}
						else {
							ndar0.push_back(ndar->at(i)->children[j]);
						}
					}
				}
			}
			ret.push_back(ret01);
			if (ndnum == 0) {
				ndnum = 1;
				ndar = &ndar1;
				ndar0.clear();
				ndar0.resize(0);
			}
			else {
				ndnum = 0;
				ndar = &ndar0;
				ndar1.clear();
				ndar1.resize(0);
			}
			ndarsz = ndar->size();
		}

		return ret;
	}
};

static Node* setNode(vector<int> &nodes, int skipnum) {
	Node* ret = NULL;
	int sz = nodes.size();
	if (sz == 0) return ret;
	ret = new Node(nodes[0]);
	if (sz <= 1) return ret;

	vector<Node*> *ndar;
	vector<Node*> ndar0;
	vector<Node*> ndar1;
	int ndnum = 0;
	ndar0.push_back(ret);
	ndar = &ndar0;
	int ndarsz = ndar->size();
	int i = 2;
	while (i < sz) {
		int j = 0;
		while (j < ndarsz && i < sz) {
			if (nodes[i] == skipnum) {
				++j;
			}
			else {
				//cout << "ndar->at(j)->val : " << ndar->at(j)->val << " | i : " << i << " | nodes[i] : " << nodes[i] << "\n";
				Node* child = new Node(nodes[i]);
				ndar->at(j)->children.push_back(child);
				if (ndnum == 0) {
					ndar1.push_back(child);
				}
				else {
					ndar0.push_back(child);
				}
			}
			++i;
		}
		if (ndnum == 0) {
			ndnum = 1;
			ndar = &ndar1;
			ndar0.clear();
			ndar0.resize(0);
		}
		else {
			ndnum = 0;
			ndar = &ndar0;
			ndar1.clear();
			ndar1.resize(0);
		}
		ndarsz = ndar->size();
	}

	return ret;
}

int main_leet080107() {
	Solution st;
	vector<int> nodes;
	Node* root;
	vector<vector<int>> ret;
	int sz;

	nodes = { 1,9999,3,2,4,9999,5,6 };
	root = setNode(nodes, 9999);
	ret = st.levelOrder(root);
	sz = ret.size();
	cout << "{ ";
	for (int i = 0; i < sz; ++i) {
		int sz2 = ret[i].size();
		cout << "{";
		for (int j = 0; j < sz2; ++j) {
			cout << ret[i][j] << ",";
		}
		cout << "} ";
	}
	cout << " } \n";
	
	return 0;
}