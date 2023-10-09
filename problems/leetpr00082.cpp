/*
* leetpr00082.cpp
* 82. Remove Duplicates from Sorted List II
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
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL) return head;
		if (head->next == NULL) return head;
		ListNode* prev;
		ListNode*  now;
		ListNode* move1;
		ListNode* move2;
		prev = head;
		now = head;
		move1 = head;
		move2 = head->next;
		while (1) {
			if (move1->val == move2->val) {
				if (move2->next != NULL) {
					move1 = move2;
					move2 = move2->next;
				}
				else {
					if (prev == head && now->val == prev->val) return NULL;
					else {
						prev->next = NULL;
						return head;
					}
				}
			}
			else {
				if (move2->next == NULL) {
					//cout << "now : " << now->val << endl;
					//cout << "move1 : " << move1->val << endl;
					if (now != move1) {
						if (prev->val != now->val)
							prev->next = move2;
						else {
							prev = move2;
							head = move2;
						}
					}
					return head;
				}
				else {
					if (now != move1) {
						if (prev->val != now->val)
							prev->next = move2;
						else {
							prev = move2;
							head = move2;
						}

					}
					else {
						prev = now;
					}
					now = move2;
					move1 = move2;
					move2 = move2->next;

				}
				//cout << prev->val << endl;
			}
		}

		return head;
	}
};