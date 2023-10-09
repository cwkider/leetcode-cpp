/*
25. Reverse Nodes in k-Group

Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.
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

ListNode* reverseKGroup(ListNode* head, int k);


void run00025() {
	vector<int> nums;
	int k;

	nums = { 1, 2, 3, 4, 5 };
	k = 2;

	ListNode* head = NULL;
	ListNode* temp = NULL;

	for (int i = 0; i < nums.size(); ++i) {
		if (head == NULL) {
			head = new ListNode();
			head->val = nums[i];
			temp = head;
		}
		else {
			temp->next = new ListNode();
			temp = temp->next;
			temp->val = nums[i];
		}
	}

	cout << "1. [2,1,4,3,5]" << endl;
	temp = reverseKGroup(head, k);
	while (temp != NULL) {
		cout << temp->val << endl;
		temp = temp->next;
	}
	cout << "-----------------------------------" << endl;

}

ListNode* reverseKGroup(ListNode* head, int k) {
	ListNode* kst = head;
	ListNode* kend = head;
	ListNode* kpend = NULL;
	ListNode* k1st = head;
	ListNode* k2st = NULL;
	if (k1st != NULL) k2st = k1st->next;
	ListNode* k3st = NULL;
	if (k2st != NULL) k3st = k2st->next;

	while (true) {
		int move = 1;
		while (move < k && kend != NULL) {
			kend = kend->next;
			move++;
		}
		if (kend == NULL) move--;
		//if (kend != NULL) cout << "kend val : " << kend->val << endl;
		if (head == kst) head = kend;
		if (kend != NULL) kend = kend->next;

		while (move == k && k2st != NULL && k2st != kend) {
			if (k2st != NULL) k2st->next = k1st;
			k1st = k2st;
			k2st = k3st;
			if (k3st != NULL) k3st = k3st->next;
		}
		//if (k1st != NULL) cout << "k1st val : " << k1st->val << endl;
		//if (k2st != NULL) cout << "k2st val : " << k2st->val << endl;
		//if (kst != NULL) cout << "kst val : " << kst->val << endl;
		//if (kpend != NULL) cout << "kpend val : " << kpend->val << endl;

		if (kpend != NULL) kpend->next = k1st;
		kpend = kst;
		kst = k2st;
		k1st = kst;
		if (k1st != NULL) k2st = k1st->next;
		if (k2st != NULL) k3st = k2st->next;

		if (move < k) break;
	}

	return head;
}


void printTest00025() {
	cout << "printTest Solution0025 !!!!!" << endl;
}
