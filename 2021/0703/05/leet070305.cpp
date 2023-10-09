/*
* leet070305.cpp
* Reverse Nodes in k-Group
* Not Completed.
*/

#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
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
	ListNode* reverseKGroup(ListNode* head, int k) {
		// ListNode* ret;

		ListNode* start;
		ListNode* end;
		ListNode* prev;
		ListNode* now;
		ListNode* next;
		ListNode* pend;

		int idx = 1;
		start = head;
		prev = NULL;
		pend = NULL;
		now = head;
		next = now->next;
		while (now->next != NULL && idx < k) {
			now = now->next;
			idx++;
		}
		if (idx == k) {
			end = now;
			head = now;
		}
		else return head;

		while (now->next != NULL) {
			if (idx == k) {
				if (pend != NULL) pend->next = now;
				end = now;
				idx = 1;
				now = start;
				next = now->next;
				start->next = end->next;
				while (idx < k) {
					prev = now;
					now = next;
					next = next->next;
					now->next = prev;
					idx++;
					//cout << "now->val : " << now->val << "| next->val : " << next->val << "\n";
				}
				//cout << "-------------------------\n";
				pend = start;
				if (next != NULL) {
					start = next;
					now = next;
					next = now->next;
				}
			}
			else {
				break;
			}
			idx = 1;
			while (now->next != NULL && idx < k) {
				now = now->next;
				idx++;
			}
		}

		return head;
	}
};

int main_leet070305() {
	Solution st;
	ListNode* head;
	vector<int> nums;
	int k;
	int nsz = 0;
	ListNode* temp;
	ListNode* now;
	ListNode* ret;

	nums = { 1,2,3,4,5 };
	k = 2;
	nsz = nums.size();
	head = new ListNode(nums[0]);
	now = head;
	for (int i = 1; i < nsz; ++i) {
		temp = new ListNode(nums[i]);
		now->next = temp;
		now = now->next;
	}
	now = head;
	for (int i = 0; i < nsz; ++i) {
		cout << now->val << " ";
		now = now->next;
	}
	cout << endl;
	ret = st.reverseKGroup(head, k);
	for (int i = 0; i < nsz; ++i) {
		cout << ret->val << " ";
		ret = ret->next;
	}
	cout << "\n-----------------------------\n";


	return 0;
}