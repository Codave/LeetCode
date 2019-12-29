#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}

};

class Solution {
public:
	bool hasCycle(ListNode* head) {
		ListNode* fast = head;
		ListNode* slow = head;
		ListNode* meet = NULL;
		while (fast) {
			slow = slow->next;
			fast = fast->next;
			if (!fast) {
				return false;
			}
			fast = fast->next;
			if (fast == slow) {
				meet = fast;
				break;
			}
		}
		if (meet == NULL) {
			return false;
		}

		return true;
	}
};