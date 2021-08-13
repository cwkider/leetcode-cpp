/*
* leet060403.cpp
* Reverse Linked List II
*/

#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int left, int right) {
		int idx = 1;

		if (left == right) return head;

		ListNode* now;
		now = head;
		while (idx < left - 1) {
			now = head->next;
			idx++;
		}

		ListNode* head2 = now;
		//cout << "head2 : " << head2->val << "\n";
		if (left > 1) {
			now = now->next;
			idx++;
		}

		int vtemp;
		if (left + 1 == right) {
			vtemp = now->next->val;
			now->next->val = now->val;
			now->val = vtemp;
			return head;
		}
		ListNode* prev = now;
		ListNode* post = now->next;
		while (idx < right) {
			//cout << "now : " << now->val << "\n";
			now = post;
			post = now->next;
			now->next = prev;
			prev = now;
			idx++;
		}
		head2->next->next = post;
		head2->next = now;

		return head;
	}
};

int main_leet060403() {
	Solution st;
	ListNode* head;
	int left, right;
	vector<int> arr;
	int lng;
	ListNode* temp;

	arr = { 1,2,3,4,5 };
	lng = arr.size();
	head = new ListNode(arr[0]);
	temp = head;
	for (int i = 1; i < lng; ++i) {
		temp->next = new ListNode(arr[i]);
		temp = temp->next;
	}
	left = 2;
	right = 4;
	head = st.reverseBetween(head, left, right);
	temp = head;
	while (temp != NULL) {
		cout << temp->val << " ";
		temp = temp->next;
	}
	cout << "\n---------------------------\n";
	
	arr = { 3,5 };
	lng = arr.size();
	head = new ListNode(arr[0]);
	temp = head;
	for (int i = 1; i < lng; ++i) {
		temp->next = new ListNode(arr[i]);
		temp = temp->next;
	}
	left = 1;
	right = 2;
	head = st.reverseBetween(head, left, right);
	temp = head;
	while (temp != NULL) {
		cout << temp->val << " ";
		temp = temp->next;
	}
	cout << "\n---------------------------\n";


	return 0;
}