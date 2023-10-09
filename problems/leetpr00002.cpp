/*
* leetpr00560.cpp
* 560. Subarray Sum Equals K
*/
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* ret = NULL;
		int num1 = 0;
		int num2 = 0;
		int num3 = 0;
		int rest = 0;
		
		ListNode* temp1;
		ListNode* temp2;
		ListNode* temp3;
		ListNode* prev3;

		temp1 = l1;
		temp2 = l2;

		ret = new ListNode(0);
		temp3 = ret;
		prev3 = ret;
		int upper = 0;
		
		while (temp1 != NULL || temp2 != NULL) {
			if (temp1 != NULL) {
				num1 = temp1->val;
				temp1 = temp1->next;
			}
			else {
				num1 = 0;
			}

			if (temp2 != NULL) {
				num2 = temp2->val;
				temp2 = temp2->next;
			}
			else {
				num2 = 0;
			}

			num3 = num1 + num2 + upper;
			rest = num3 % 10;
			upper = num3 / 10;
			temp3->val = rest;
			temp3->next = new ListNode();
			prev3 = temp3;
			temp3 = temp3->next;
		}

		if (upper > 0) {
			prev3->next->val = upper;
		}
		else {
			prev3->next = NULL;
		}

		return ret;
	}
};


int main00002() {
	Solution st;
	ListNode* l1;
	ListNode* l2;
	ListNode* ret;
	vector<int> arr1, arr2;
	ListNode* temp;
	int sz = 0;

	arr1 = { 2, 4, 3 };
	arr2 = { 5, 6, 4 };
	l1 = new ListNode();
	temp = l1;
	sz = arr1.size();
	for (int i = 0; i < sz; ++i) {
		temp->val = arr1[i];
		if (i < sz - 1) {
			temp->next = new ListNode();
			temp = temp->next;
		}
	}

	l2 = new ListNode();
	temp = l2;
	sz = arr2.size();
	for (int i = 0; i < sz; ++i) {
		temp->val = arr2[i];
		if (i < sz - 1) {
			temp->next = new ListNode();
			temp = temp->next;
		}
	}

	ret = st.addTwoNumbers(l1, l2);
	temp = ret;
	while (temp != NULL) {
		cout << temp->val << endl;
		temp = temp->next;
	}
	cout << "================================================" << "\n";

	arr1 = { 0 };
	arr2 = { 0 };
	l1 = new ListNode();
	temp = l1;
	sz = arr1.size();
	for (int i = 0; i < sz; ++i) {
		temp->val = arr1[i];
		if (i < sz - 1) {
			temp->next = new ListNode();
			temp = temp->next;
		}
	}

	l2 = new ListNode();
	temp = l2;
	sz = arr2.size();
	for (int i = 0; i < sz; ++i) {
		temp->val = arr2[i];
		if (i < sz - 1) {
			temp->next = new ListNode();
			temp = temp->next;
		}
	}

	ret = st.addTwoNumbers(l1, l2);
	temp = ret;
	while (temp != NULL) {
		cout << temp->val << endl;
		temp = temp->next;
	}
	cout << "================================================" << "\n";

	arr1 = { 9,9,9,9,9,9,9 };
	arr2 = { 9,9,9,9 };
	l1 = new ListNode();
	temp = l1;
	sz = arr1.size();
	for (int i = 0; i < sz; ++i) {
		temp->val = arr1[i];
		if (i < sz - 1) {
			temp->next = new ListNode();
			temp = temp->next;
		}
	}

	l2 = new ListNode();
	temp = l2;
	sz = arr2.size();
	for (int i = 0; i < sz; ++i) {
		temp->val = arr2[i];
		if (i < sz - 1) {
			temp->next = new ListNode();
			temp = temp->next;
		}
	}

	ret = st.addTwoNumbers(l1, l2);
	temp = ret;
	while (temp != NULL) {
		cout << temp->val << endl;
		temp = temp->next;
	}
	cout << "================================================" << "\n";


	return 0;
}