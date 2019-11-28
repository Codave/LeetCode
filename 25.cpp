#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		
		ListNode dummyHead(0);
		dummyHead.next = head;
		ListNode* pre = &dummyHead;
		ListNode* end = &dummyHead;
		while (end->next != NULL) {
			for (int i = 0; i < k && end != NULL; i++) {
				end = end->next;
			}
			if (end == NULL)	break;
			ListNode* start = pre->next;
			ListNode* next = end->next;
			end->next = NULL;
			pre->next = reverse(start);
			start->next = next;
			pre = start;
			end = pre;
		}
		return dummyHead.next;
	}
	ListNode* reverse(ListNode* head) {
		ListNode* new_head = NULL;
		while (head) {
			ListNode* next = head->next;
			head->next = new_head;
			new_head = head;
			head = next;
		}
		return new_head;
	}
};

int main() {
	ListNode a(1);
	ListNode b(2);
	ListNode c(3);
	ListNode d(4);
	ListNode e(5);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;

	ListNode* head = Solution().reverseKGroup(&a,3);
	while (head) {
		if (head->next) {
			cout << head->val << "->";
		}
		else {
			cout << head->val << "->NULL";
		}
		head = head->next;
	}

	return 0;
}